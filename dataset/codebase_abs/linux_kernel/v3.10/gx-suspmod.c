static void F_1 ( int V_1 , int V_2 )
{
F_2 ( V_3 -> V_4 , V_1 , V_2 ) ;
}
unsigned int F_3 ( unsigned int V_5 )
{
if ( ( V_3 -> V_6 & V_7 ) == 0 )
return V_8 ;
return ( V_8 * V_3 -> V_9 )
/ ( V_3 -> V_10 + V_3 -> V_9 ) ;
}
static unsigned int F_4 ( unsigned int V_11 , T_1 * V_10 ,
T_1 * V_9 )
{
unsigned int V_12 ;
T_1 V_13 , V_14 ;
int V_15 = V_8 ;
int V_16 ;
* V_9 = 1 ;
* V_10 = 0 ;
for ( V_12 = V_17 ; V_12 > 0 ; V_12 -- ) {
V_14 = ( ( V_11 * V_12 ) / V_8 ) & 0xff ;
V_13 = V_12 - V_14 ;
V_16 = ( V_8 * V_14 ) / V_12 ;
if ( abs ( V_16 - V_11 ) <= abs ( V_15 - V_11 ) ) {
* V_10 = V_13 ;
* V_9 = V_14 ;
V_15 = V_16 ;
}
}
return V_15 ;
}
static void F_5 ( struct V_18 * V_19 , unsigned int V_11 )
{
T_1 V_20 , V_21 ;
unsigned int V_22 ;
unsigned long V_23 ;
struct V_24 V_25 ;
V_25 . V_26 = F_3 ( 0 ) ;
V_22 = F_4 ( V_11 , & V_3 -> V_10 ,
& V_3 -> V_9 ) ;
V_25 . V_27 = V_22 ;
F_6 ( V_19 , & V_25 , V_28 ) ;
F_7 ( V_23 ) ;
if ( V_22 != V_8 ) {
switch ( V_3 -> V_4 -> V_29 ) {
case V_30 :
V_21 = V_3 -> V_31 | V_32 | V_33 ;
F_1 ( V_34 , 4 ) ;
F_1 ( V_35 , 100 ) ;
F_1 ( V_36 , V_21 ) ;
if ( V_3 -> V_4 -> V_37 < 0x10 ) {
V_20 = V_3 -> V_6 | V_7 ;
} else {
V_20 = V_3 -> V_6 | V_7 | V_38 ;
}
break;
case V_39 :
case V_40 :
V_20 = V_3 -> V_6 | V_7 ;
break;
default:
F_8 ( V_23 ) ;
F_9 ( L_1 ) ;
return;
}
} else {
V_20 = V_3 -> V_6 & ~ ( V_7 ) ;
V_3 -> V_9 = 0 ;
V_3 -> V_10 = 0 ;
F_9 ( L_2 ) ;
}
F_1 ( V_41 , V_3 -> V_9 ) ;
F_1 ( V_42 , V_3 -> V_10 ) ;
F_1 ( V_43 , V_20 ) ;
F_10 ( V_3 -> V_4 , V_43 , & V_20 ) ;
F_8 ( V_23 ) ;
V_3 -> V_6 = V_20 ;
F_6 ( V_19 , & V_25 , V_44 ) ;
F_9 ( L_3 ,
V_3 -> V_10 * 32 , V_3 -> V_9 * 32 ) ;
F_9 ( L_4 , V_25 . V_27 ) ;
}
static int F_11 ( struct V_18 * V_19 )
{
unsigned int V_16 = 0 ;
T_1 V_45 , V_46 ;
if ( ! V_8 || ! V_19 )
return - V_47 ;
V_19 -> V_5 = 0 ;
F_12 ( V_19 , ( V_8 / V_17 ) ,
V_8 ) ;
V_16 = F_4 ( V_19 -> V_48 , & V_45 , & V_46 ) ;
if ( V_16 < V_19 -> V_48 )
V_16 += V_8 / V_17 ;
V_19 -> V_48 = V_16 ;
if ( V_19 -> V_48 > V_19 -> V_49 )
V_19 -> V_49 = V_16 ;
V_16 = F_4 ( V_19 -> V_49 , & V_45 , & V_46 ) ;
if ( V_16 > V_19 -> V_49 )
V_16 -= V_8 / V_17 ;
V_19 -> V_49 = V_16 ;
if ( V_19 -> V_49 < V_19 -> V_48 )
V_19 -> V_49 = V_19 -> V_48 ;
F_12 ( V_19 , ( V_8 / V_17 ) ,
V_8 ) ;
return 0 ;
}
static int F_13 ( struct V_18 * V_19 ,
unsigned int V_50 ,
unsigned int V_51 )
{
T_1 V_45 , V_46 ;
unsigned int V_16 ;
if ( ! V_8 || ! V_19 )
return - V_47 ;
V_19 -> V_5 = 0 ;
V_16 = F_4 ( V_50 , & V_45 , & V_46 ) ;
while ( V_16 < V_19 -> V_48 ) {
V_16 += V_8 / V_17 ;
V_16 = F_4 ( V_16 , & V_45 , & V_46 ) ;
}
while ( V_16 > V_19 -> V_49 ) {
V_16 -= V_8 / V_17 ;
V_16 = F_4 ( V_16 , & V_45 , & V_46 ) ;
}
F_5 ( V_19 , V_16 ) ;
return 0 ;
}
static int F_14 ( struct V_18 * V_19 )
{
unsigned int V_52 , V_53 ;
if ( ! V_19 || V_19 -> V_5 != 0 )
return - V_54 ;
if ( V_55 )
V_52 = V_55 * V_56 [ F_15 ( V_57 ) & 0x0f ] ;
else if ( V_58 )
V_52 = V_58 ;
else
V_52 = 30000 * V_56 [ F_15 ( V_57 ) & 0x0f ] ;
V_8 = V_52 ;
V_53 = F_3 ( 0 ) ;
F_9 ( L_5 , V_52 ) ;
F_9 ( L_6 , V_53 ) ;
V_19 -> V_5 = 0 ;
if ( V_17 < V_59 )
V_19 -> V_48 = V_52 / V_17 ;
else
V_19 -> V_48 = V_52 / V_59 ;
V_19 -> V_49 = V_52 ;
V_19 -> V_60 = V_53 ;
V_19 -> V_61 . V_62 = V_52 / V_17 ;
V_19 -> V_61 . V_63 = V_52 ;
V_19 -> V_61 . V_64 = V_65 ;
return 0 ;
}
static int T_2 F_16 ( void )
{
int V_66 ;
struct V_67 * V_68 ;
struct V_69 * V_70 ;
V_70 = F_17 () ;
if ( V_70 == NULL )
return - V_54 ;
if ( V_17 > 0xff )
V_17 = 0xff ;
F_9 ( L_7 ) ;
V_68 = F_18 ( sizeof( struct V_67 ) , V_71 ) ;
if ( V_68 == NULL )
return - V_72 ;
V_68 -> V_4 = V_70 ;
V_3 = V_68 ;
F_10 ( V_68 -> V_4 , V_43 , & ( V_68 -> V_6 ) ) ;
F_10 ( V_68 -> V_4 , V_36 , & ( V_68 -> V_31 ) ) ;
F_10 ( V_68 -> V_4 , V_73 , & ( V_68 -> V_74 ) ) ;
F_10 ( V_68 -> V_4 , V_42 , & ( V_68 -> V_10 ) ) ;
F_10 ( V_68 -> V_4 , V_41 ,
& ( V_68 -> V_9 ) ) ;
V_66 = F_19 ( & V_75 ) ;
if ( V_66 ) {
F_20 ( V_68 ) ;
return V_66 ;
}
return 0 ;
}
static void T_3 F_21 ( void )
{
F_22 ( & V_75 ) ;
F_23 ( V_3 -> V_4 ) ;
F_20 ( V_3 ) ;
}
