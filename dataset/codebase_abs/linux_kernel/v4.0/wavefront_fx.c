static int
F_1 ( T_1 * V_1 )
{
int V_2 ;
unsigned int V_3 = 0x80 ;
for ( V_2 = 0 ; V_2 < 1000 ; V_2 ++ ) {
V_3 = F_2 ( V_1 -> V_4 ) ;
if ( ( V_3 & 0x80 ) == 0 ) {
break;
}
}
if ( V_3 & 0x80 ) {
F_3 ( L_1 ) ;
return 0 ;
}
return ( 1 ) ;
}
static void
F_4 ( T_1 * V_1 , int V_5 )
{
if ( ! F_1 ( V_1 ) ) {
return;
}
F_5 ( V_5 ? 0x02 : 0x00 , V_1 -> V_6 ) ;
}
static int
F_6 ( T_1 * V_1 ,
int V_7 ,
int V_8 ,
int V_9 ,
unsigned short * V_10 )
{
if ( V_7 < 0 || V_7 > 7 ) {
F_3 ( L_2
L_3 ) ;
return - ( V_11 ) ;
}
if ( V_8 < 0 || V_8 > 0x7f ) {
F_3 ( L_2
L_4 ) ;
return - ( V_11 ) ;
}
if ( V_9 == 1 ) {
F_5 ( V_12 , V_1 -> V_13 ) ;
F_5 ( V_7 , V_1 -> V_14 ) ;
F_5 ( V_8 , V_1 -> V_15 ) ;
F_5 ( ( V_10 [ 0 ] >> 8 ) , V_1 -> V_16 ) ;
F_5 ( ( V_10 [ 0 ] & 0xff ) , V_1 -> V_17 ) ;
F_3 ( L_5 ,
V_7 , V_8 , V_10 [ 0 ] ) ;
} else {
int V_2 ;
F_5 ( V_18 | V_12 , V_1 -> V_13 ) ;
F_5 ( V_7 , V_1 -> V_14 ) ;
F_5 ( V_8 , V_1 -> V_15 ) ;
for ( V_2 = 0 ; V_2 < V_9 ; V_2 ++ ) {
F_5 ( ( V_10 [ V_2 ] >> 8 ) , V_1 -> V_16 ) ;
F_5 ( ( V_10 [ V_2 ] & 0xff ) , V_1 -> V_17 ) ;
if ( ! F_1 ( V_1 ) ) {
break;
}
}
if ( V_2 != V_9 ) {
F_3 ( L_6
L_7 ,
V_7 , V_8 , ( unsigned long ) V_10 , V_9 ) ;
return - ( V_19 ) ;
}
}
return 0 ;
}
int
F_7 ( T_1 * V_1 )
{
if ( F_2 ( V_1 -> V_4 ) & 0x80 ) {
F_3 ( L_8 ) ;
return - 1 ;
}
return 0 ;
}
int
F_8 ( struct V_20 * V_21 , struct V_22 * V_22 )
{
if ( ! F_9 ( V_21 -> V_23 -> V_24 ) )
return - V_25 ;
V_22 -> V_26 = V_21 ;
return 0 ;
}
int
F_10 ( struct V_20 * V_21 , struct V_22 * V_22 )
{
F_11 ( V_21 -> V_23 -> V_24 ) ;
return 0 ;
}
int
F_12 ( struct V_20 * V_27 , struct V_22 * V_22 ,
unsigned int V_28 , unsigned long V_29 )
{
struct V_30 * V_23 ;
T_2 * V_31 ;
T_1 * V_1 ;
T_3 V_32 ;
unsigned short * V_33 = NULL ;
unsigned short * V_34 ;
int V_35 = 0 ;
V_23 = V_27 -> V_23 ;
if ( F_13 ( ! V_23 ) )
return - V_36 ;
if ( F_13 ( ! V_23 -> V_26 ) )
return - V_36 ;
V_31 = V_23 -> V_26 ;
V_1 = & V_31 -> V_37 ;
if ( F_14 ( & V_32 , ( void V_38 * ) V_29 , sizeof ( T_3 ) ) )
return - V_25 ;
switch ( V_32 . V_39 ) {
case V_40 :
F_4 ( V_1 , V_32 . V_10 [ 0 ] ) ;
return - V_19 ;
case V_41 :
if ( V_32 . V_10 [ 2 ] <= 0 ) {
F_3 ( L_9
L_10 ) ;
return - V_19 ;
} else if ( V_32 . V_10 [ 2 ] == 1 ) {
V_34 = ( unsigned short * ) & V_32 . V_10 [ 3 ] ;
} else {
if ( V_32 . V_10 [ 2 ] > 256 ) {
F_3 ( L_9
L_11 ) ;
return - V_19 ;
}
V_33 = F_15 ( ( unsigned char V_38 * )
V_32 . V_10 [ 3 ] ,
V_32 . V_10 [ 2 ] * sizeof( short ) ) ;
if ( F_16 ( V_33 ) )
return F_17 ( V_33 ) ;
V_34 = V_33 ;
}
V_35 = F_6 ( V_1 ,
V_32 . V_10 [ 0 ] ,
V_32 . V_10 [ 1 ] ,
V_32 . V_10 [ 2 ] ,
V_34 ) ;
F_18 ( V_33 ) ;
break;
default:
F_3 ( L_12 ,
V_32 . V_39 ) ;
return - V_42 ;
}
return V_35 ;
}
int
F_19 ( T_1 * V_1 )
{
unsigned int V_2 ;
int V_35 ;
const struct V_43 * V_43 = NULL ;
if ( V_1 -> V_44 )
return 0 ;
V_35 = F_20 ( & V_43 , L_13 ,
V_1 -> V_23 -> V_1 ) ;
if ( V_35 < 0 ) {
V_35 = - 1 ;
goto V_45;
}
for ( V_2 = 0 ; V_2 + 1 < V_43 -> V_46 ; V_2 += 2 ) {
if ( V_43 -> V_10 [ V_2 ] >= 8 && V_43 -> V_10 [ V_2 ] < 16 ) {
F_5 ( V_43 -> V_10 [ V_2 + 1 ] ,
V_1 -> V_47 + V_43 -> V_10 [ V_2 ] ) ;
} else if ( V_43 -> V_10 [ V_2 ] == V_48 ) {
if ( ! F_1 ( V_1 ) ) {
V_35 = - 1 ;
goto V_45;
}
} else {
F_3 ( V_49 L_14
L_15 ) ;
V_35 = - 1 ;
goto V_45;
}
}
V_1 -> V_44 = 1 ;
V_35 = 0 ;
V_45:
F_21 ( V_43 ) ;
return V_35 ;
}
