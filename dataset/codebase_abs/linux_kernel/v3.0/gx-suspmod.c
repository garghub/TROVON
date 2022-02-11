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
static void F_5 ( unsigned int V_11 )
{
T_1 V_18 , V_19 ;
unsigned int V_20 ;
unsigned long V_21 ;
struct V_22 V_23 ;
V_23 . V_5 = 0 ;
V_23 . V_24 = F_3 ( 0 ) ;
V_20 = F_4 ( V_11 , & V_3 -> V_10 ,
& V_3 -> V_9 ) ;
V_23 . V_25 = V_20 ;
F_6 ( & V_23 , V_26 ) ;
F_7 ( V_21 ) ;
if ( V_20 != V_8 ) {
switch ( V_3 -> V_4 -> V_27 ) {
case V_28 :
V_19 = V_3 -> V_29 | V_30 | V_31 ;
F_1 ( V_32 , 4 ) ;
F_1 ( V_33 , 100 ) ;
F_1 ( V_34 , V_19 ) ;
if ( V_3 -> V_4 -> V_35 < 0x10 ) {
V_18 = V_3 -> V_6 | V_7 ;
} else {
V_18 = V_3 -> V_6 | V_7 | V_36 ;
}
break;
case V_37 :
case V_38 :
V_18 = V_3 -> V_6 | V_7 ;
break;
default:
F_8 ( V_21 ) ;
F_9 ( L_1 ) ;
return;
}
} else {
V_18 = V_3 -> V_6 & ~ ( V_7 ) ;
V_3 -> V_9 = 0 ;
V_3 -> V_10 = 0 ;
F_9 ( L_2 ) ;
}
F_1 ( V_39 , V_3 -> V_9 ) ;
F_1 ( V_40 , V_3 -> V_10 ) ;
F_1 ( V_41 , V_18 ) ;
F_10 ( V_3 -> V_4 , V_41 , & V_18 ) ;
F_8 ( V_21 ) ;
V_3 -> V_6 = V_18 ;
F_6 ( & V_23 , V_42 ) ;
F_9 ( L_3 ,
V_3 -> V_10 * 32 , V_3 -> V_9 * 32 ) ;
F_9 ( L_4 , V_23 . V_25 ) ;
}
static int F_11 ( struct V_43 * V_44 )
{
unsigned int V_16 = 0 ;
T_1 V_45 , V_46 ;
if ( ! V_8 || ! V_44 )
return - V_47 ;
V_44 -> V_5 = 0 ;
F_12 ( V_44 , ( V_8 / V_17 ) ,
V_8 ) ;
V_16 = F_4 ( V_44 -> V_48 , & V_45 , & V_46 ) ;
if ( V_16 < V_44 -> V_48 )
V_16 += V_8 / V_17 ;
V_44 -> V_48 = V_16 ;
if ( V_44 -> V_48 > V_44 -> V_49 )
V_44 -> V_49 = V_16 ;
V_16 = F_4 ( V_44 -> V_49 , & V_45 , & V_46 ) ;
if ( V_16 > V_44 -> V_49 )
V_16 -= V_8 / V_17 ;
V_44 -> V_49 = V_16 ;
if ( V_44 -> V_49 < V_44 -> V_48 )
V_44 -> V_49 = V_44 -> V_48 ;
F_12 ( V_44 , ( V_8 / V_17 ) ,
V_8 ) ;
return 0 ;
}
static int F_13 ( struct V_43 * V_44 ,
unsigned int V_50 ,
unsigned int V_51 )
{
T_1 V_45 , V_46 ;
unsigned int V_16 ;
if ( ! V_8 || ! V_44 )
return - V_47 ;
V_44 -> V_5 = 0 ;
V_16 = F_4 ( V_50 , & V_45 , & V_46 ) ;
while ( V_16 < V_44 -> V_48 ) {
V_16 += V_8 / V_17 ;
V_16 = F_4 ( V_16 , & V_45 , & V_46 ) ;
}
while ( V_16 > V_44 -> V_49 ) {
V_16 -= V_8 / V_17 ;
V_16 = F_4 ( V_16 , & V_45 , & V_46 ) ;
}
F_5 ( V_16 ) ;
return 0 ;
}
static int F_14 ( struct V_43 * V_44 )
{
unsigned int V_52 , V_53 ;
if ( ! V_44 || V_44 -> V_5 != 0 )
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
V_44 -> V_5 = 0 ;
if ( V_17 < V_59 )
V_44 -> V_48 = V_52 / V_17 ;
else
V_44 -> V_48 = V_52 / V_59 ;
V_44 -> V_49 = V_52 ;
V_44 -> V_60 = V_53 ;
V_44 -> V_61 . V_62 = V_52 / V_17 ;
V_44 -> V_61 . V_63 = V_52 ;
V_44 -> V_61 . V_64 = V_65 ;
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
F_10 ( V_68 -> V_4 , V_41 , & ( V_68 -> V_6 ) ) ;
F_10 ( V_68 -> V_4 , V_34 , & ( V_68 -> V_29 ) ) ;
F_10 ( V_68 -> V_4 , V_73 , & ( V_68 -> V_74 ) ) ;
F_10 ( V_68 -> V_4 , V_40 , & ( V_68 -> V_10 ) ) ;
F_10 ( V_68 -> V_4 , V_39 ,
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
