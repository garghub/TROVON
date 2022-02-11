static unsigned long F_1 ( int V_1 )
{
unsigned long V_2 ;
struct V_3 V_4 = {
. V_5 = V_1 - 1900 ,
. V_6 = 1 ,
} ;
F_2 ( & V_4 , & V_2 ) ;
return V_2 ;
}
static int F_3 ( struct V_7 * V_8 , struct V_3 * V_4 )
{
unsigned long V_9 = V_10 + V_11 ;
int V_12 , V_13 ;
unsigned long V_14 , V_2 ;
unsigned char V_15 [ F_4 ( V_16 ) ] ;
T_1 V_17 ;
V_12 = F_5 ( V_8 ,
V_18 , V_19 , V_20 ) ;
if ( V_12 < 0 )
return V_12 ;
if ( F_6 ( V_8 ) == 0 ) {
F_7 ( 1 ) ;
} else {
while ( F_8 ( V_10 , V_9 ) ) {
V_12 = F_9 ( V_8 ,
V_18 , V_19 , & V_17 ) ;
if ( V_12 < 0 )
return V_12 ;
if ( ! ( V_17 & V_20 ) )
break;
F_7 ( 1 ) ;
}
}
for ( V_13 = 0 ; V_13 < F_4 ( V_16 ) ; V_13 ++ ) {
V_12 = F_9 ( V_8 ,
V_18 , V_16 [ V_13 ] , & V_17 ) ;
if ( V_12 < 0 )
return V_12 ;
V_15 [ V_13 ] = V_17 ;
}
V_14 = ( V_15 [ 0 ] << 16 ) | ( V_15 [ 1 ] << 8 ) | V_15 [ 2 ] ;
V_2 = ( V_15 [ 3 ] << 8 ) | V_15 [ 4 ] ;
V_2 = V_2 / V_21 ;
V_2 = V_2 + ( V_14 * 60 ) ;
V_2 += F_1 ( V_22 ) ;
F_10 ( V_2 , V_4 ) ;
return F_11 ( V_4 ) ;
}
static int F_12 ( struct V_7 * V_8 , struct V_3 * V_4 )
{
int V_12 , V_13 ;
unsigned char V_15 [ F_4 ( V_16 ) ] ;
unsigned long V_23 , V_24 , V_2 = 0 ;
if ( V_4 -> V_5 < ( V_22 - 1900 ) ) {
F_13 ( V_8 , L_1 ,
V_22 ) ;
return - V_25 ;
}
F_2 ( V_4 , & V_2 ) ;
V_2 -= F_1 ( V_22 ) ;
V_24 = V_2 / 60 ;
V_23 = V_2 % 60 ;
V_23 = V_23 * V_21 ;
V_15 [ 4 ] = V_23 & 0xFF ;
V_15 [ 3 ] = ( V_23 >> 8 ) & 0xFF ;
V_15 [ 2 ] = V_24 & 0xFF ;
V_15 [ 1 ] = ( V_24 >> 8 ) & 0xFF ;
V_15 [ 0 ] = ( V_24 >> 16 ) & 0xFF ;
for ( V_13 = 0 ; V_13 < F_4 ( V_16 ) ; V_13 ++ ) {
V_12 = F_5 ( V_8 , V_18 ,
V_16 [ V_13 ] , V_15 [ V_13 ] ) ;
if ( V_12 < 0 )
return V_12 ;
}
return F_5 ( V_8 , V_18 ,
V_19 , V_26 ) ;
}
static int F_14 ( struct V_7 * V_8 , struct V_27 * V_28 )
{
int V_12 , V_13 ;
T_1 V_29 , V_17 ;
unsigned char V_15 [ F_4 ( V_30 ) ] ;
unsigned long V_2 , V_14 ;
V_12 = F_9 ( V_8 , V_18 ,
V_31 , & V_29 ) ;
if ( V_12 < 0 )
return V_12 ;
if ( V_29 & V_32 )
V_28 -> V_33 = 1 ;
else
V_28 -> V_33 = 0 ;
V_28 -> V_34 = 0 ;
for ( V_13 = 0 ; V_13 < F_4 ( V_30 ) ; V_13 ++ ) {
V_12 = F_9 ( V_8 , V_18 ,
V_30 [ V_13 ] , & V_17 ) ;
if ( V_12 < 0 )
return V_12 ;
V_15 [ V_13 ] = V_17 ;
}
V_14 = ( V_15 [ 0 ] << 16 ) | ( V_15 [ 1 ] << 8 ) | ( V_15 [ 2 ] ) ;
V_2 = V_14 * 60 ;
V_2 += F_1 ( V_22 ) ;
F_10 ( V_2 , & V_28 -> time ) ;
return F_11 ( & V_28 -> time ) ;
}
static int F_15 ( struct V_7 * V_8 , unsigned int V_33 )
{
return F_16 ( V_8 , V_18 ,
V_31 , V_32 ,
V_33 ? V_32 : 0 ) ;
}
static int F_17 ( struct V_7 * V_8 , struct V_27 * V_28 )
{
int V_12 , V_13 ;
unsigned char V_15 [ F_4 ( V_30 ) ] ;
unsigned long V_14 , V_2 = 0 ;
if ( V_28 -> time . V_5 < ( V_22 - 1900 ) ) {
F_13 ( V_8 , L_1 ,
V_22 ) ;
return - V_25 ;
}
F_2 ( & V_28 -> time , & V_2 ) ;
V_2 -= F_1 ( V_22 ) ;
V_14 = V_2 / 60 ;
V_15 [ 2 ] = V_14 & 0xFF ;
V_15 [ 1 ] = ( V_14 >> 8 ) & 0xFF ;
V_15 [ 0 ] = ( V_14 >> 16 ) & 0xFF ;
for ( V_13 = 0 ; V_13 < F_4 ( V_30 ) ; V_13 ++ ) {
V_12 = F_5 ( V_8 , V_18 ,
V_30 [ V_13 ] , V_15 [ V_13 ] ) ;
if ( V_12 < 0 )
return V_12 ;
}
return F_15 ( V_8 , V_28 -> V_33 ) ;
}
static T_2 F_18 ( int V_35 , void * V_36 )
{
struct V_37 * V_38 = V_36 ;
unsigned long V_39 = V_40 | V_41 ;
F_13 ( & V_38 -> V_8 , L_2 , V_42 ) ;
F_19 ( V_38 , 1 , V_39 ) ;
return V_43 ;
}
static int T_3 F_20 ( struct V_44 * V_45 )
{
int V_46 ;
struct V_37 * V_38 ;
T_1 V_29 ;
int V_35 ;
V_35 = F_21 ( V_45 , L_3 ) ;
if ( V_35 < 0 )
return V_35 ;
V_46 = F_16 ( & V_45 -> V_8 , V_18 ,
V_31 , V_47 , V_47 ) ;
if ( V_46 < 0 )
return V_46 ;
F_7 ( 1 ) ;
V_46 = F_9 ( & V_45 -> V_8 , V_18 ,
V_31 , & V_29 ) ;
if ( V_46 < 0 )
return V_46 ;
if ( ! ( V_29 & V_47 ) ) {
F_22 ( & V_45 -> V_8 , L_4 ) ;
return - V_48 ;
}
V_38 = F_23 ( L_5 , & V_45 -> V_8 , & V_49 ,
V_50 ) ;
if ( F_24 ( V_38 ) ) {
F_22 ( & V_45 -> V_8 , L_6 ) ;
V_46 = F_25 ( V_38 ) ;
return V_46 ;
}
V_46 = F_26 ( V_35 , NULL , F_18 , 0 ,
L_5 , V_38 ) ;
if ( V_46 < 0 ) {
F_27 ( V_38 ) ;
return V_46 ;
}
F_28 ( V_45 , V_38 ) ;
return 0 ;
}
static int T_4 F_29 ( struct V_44 * V_45 )
{
struct V_37 * V_38 = F_30 ( V_45 ) ;
int V_35 = F_21 ( V_45 , L_3 ) ;
F_31 ( V_35 , V_38 ) ;
F_27 ( V_38 ) ;
F_28 ( V_45 , NULL ) ;
return 0 ;
}
static int T_5 F_32 ( void )
{
return F_33 ( & V_51 ) ;
}
static void T_6 F_34 ( void )
{
F_35 ( & V_51 ) ;
}
