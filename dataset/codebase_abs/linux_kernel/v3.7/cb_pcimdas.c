static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 , unsigned int * V_7 )
{
const struct V_8 * V_9 = F_2 ( V_2 ) ;
struct V_10 * V_11 = V_2 -> V_12 ;
int V_13 , V_14 ;
unsigned int V_15 ;
unsigned int V_16 ;
int V_17 = F_3 ( V_6 -> V_18 ) ;
unsigned short V_19 ;
int V_20 ;
if ( ( F_4 ( V_11 -> V_21 + 2 ) & 0x20 ) == 0 )
V_20 = V_9 -> V_22 ;
else
V_20 = V_9 -> V_23 ;
if ( V_17 > ( V_20 - 1 ) )
return - V_24 ;
V_15 = F_4 ( V_11 -> V_21 + 5 ) ;
if ( ( V_15 & 0x03 ) > 0 ) {
V_15 = V_15 & 0xfd ;
F_5 ( V_15 , V_11 -> V_21 + 5 ) ;
}
F_5 ( 0x01 , V_11 -> V_21 + 6 ) ;
F_5 ( 0x00 , V_11 -> V_21 + 7 ) ;
V_19 = V_17 | ( V_17 << 4 ) ;
F_5 ( V_19 , V_11 -> V_21 + 0 ) ;
for ( V_13 = 0 ; V_13 < V_6 -> V_13 ; V_13 ++ ) {
F_6 ( 0 , V_2 -> V_25 + 0 ) ;
#define F_7 1000
for ( V_14 = 0 ; V_14 < F_7 ; V_14 ++ ) {
V_16 = F_4 ( V_11 -> V_21 + 2 ) & 0x80 ;
if ( ! V_16 )
break;
}
if ( V_14 == F_7 ) {
F_8 ( L_1 ) ;
return - V_24 ;
}
V_15 = F_9 ( V_2 -> V_25 + 0 ) ;
V_7 [ V_13 ] = V_15 ;
}
return V_13 ;
}
static int F_10 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 , unsigned int * V_7 )
{
struct V_10 * V_11 = V_2 -> V_12 ;
int V_14 ;
int V_17 = F_3 ( V_6 -> V_18 ) ;
for ( V_14 = 0 ; V_14 < V_6 -> V_13 ; V_14 ++ ) {
switch ( V_17 ) {
case 0 :
F_6 ( V_7 [ V_14 ] & 0x0FFF , V_2 -> V_25 + V_26 ) ;
break;
case 1 :
F_6 ( V_7 [ V_14 ] & 0x0FFF , V_2 -> V_25 + V_27 ) ;
break;
default:
return - 1 ;
}
V_11 -> V_28 [ V_17 ] = V_7 [ V_14 ] ;
}
return V_14 ;
}
static int F_11 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 , unsigned int * V_7 )
{
struct V_10 * V_11 = V_2 -> V_12 ;
int V_14 ;
int V_17 = F_3 ( V_6 -> V_18 ) ;
for ( V_14 = 0 ; V_14 < V_6 -> V_13 ; V_14 ++ )
V_7 [ V_14 ] = V_11 -> V_28 [ V_17 ] ;
return V_14 ;
}
static const void * F_12 ( struct V_1 * V_2 ,
struct V_29 * V_30 )
{
const struct V_8 * V_9 ;
int V_14 ;
for ( V_14 = 0 ; V_14 < F_13 ( V_31 ) ; V_14 ++ ) {
V_9 = & V_31 [ V_14 ] ;
if ( V_9 -> V_32 == V_30 -> V_33 )
return V_9 ;
}
return NULL ;
}
static int F_14 ( struct V_1 * V_2 ,
struct V_29 * V_30 )
{
const struct V_8 * V_9 ;
struct V_10 * V_11 ;
struct V_3 * V_4 ;
unsigned long V_34 ;
int V_35 ;
F_15 ( V_2 , & V_30 -> V_2 ) ;
V_9 = F_12 ( V_2 , V_30 ) ;
if ( ! V_9 )
return - V_36 ;
V_2 -> V_37 = V_9 ;
V_2 -> V_38 = V_9 -> V_39 ;
V_35 = F_16 ( V_2 , sizeof( * V_11 ) ) ;
if ( V_35 )
return V_35 ;
V_11 = V_2 -> V_12 ;
switch ( V_9 -> V_32 ) {
case 0x56 :
break;
default:
F_17 ( V_2 -> V_40 , L_2 ) ;
F_17 ( V_2 -> V_40 ,
L_3 ) ;
}
V_35 = F_18 ( V_30 , V_2 -> V_38 ) ;
if ( V_35 )
return V_35 ;
V_2 -> V_25 = F_19 ( V_30 , 2 ) ;
V_11 -> V_21 = F_19 ( V_30 , 3 ) ;
V_34 = F_19 ( V_30 , 4 ) ;
V_35 = F_20 ( V_2 , 3 ) ;
if ( V_35 )
return V_35 ;
V_4 = & V_2 -> V_41 [ 0 ] ;
V_4 -> type = V_42 ;
V_4 -> V_43 = V_44 | V_45 ;
V_4 -> V_46 = V_9 -> V_23 ;
V_4 -> V_47 = ( 1 << V_9 -> V_48 ) - 1 ;
V_4 -> V_49 = & V_50 ;
V_4 -> V_51 = 1 ;
V_4 -> V_52 = F_1 ;
V_4 = & V_2 -> V_41 [ 1 ] ;
V_4 -> type = V_53 ;
V_4 -> V_43 = V_54 ;
V_4 -> V_46 = V_9 -> V_55 ;
V_4 -> V_47 = 1 << V_9 -> V_56 ;
V_4 -> V_49 = & V_50 ;
V_4 -> V_57 = & F_10 ;
V_4 -> V_52 = & F_11 ;
V_4 = & V_2 -> V_41 [ 2 ] ;
if ( V_9 -> V_58 )
F_21 ( V_2 , V_4 , NULL , V_34 ) ;
else
V_4 -> type = V_59 ;
F_22 ( V_2 -> V_40 , L_4 , V_2 -> V_38 ) ;
return 0 ;
}
static void F_23 ( struct V_1 * V_2 )
{
struct V_29 * V_30 = F_24 ( V_2 ) ;
if ( V_2 -> V_60 )
F_25 ( V_2 -> V_60 , V_2 ) ;
if ( V_30 ) {
if ( V_2 -> V_25 )
F_26 ( V_30 ) ;
}
}
static int T_1 F_27 ( struct V_29 * V_2 ,
const struct V_61 * V_62 )
{
return F_28 ( V_2 , & V_63 ) ;
}
static void T_2 F_29 ( struct V_29 * V_2 )
{
F_30 ( V_2 ) ;
}
