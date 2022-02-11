static void F_1 ( int V_1 , int V_2 )
{
F_2 ( V_3 -> V_4 , V_1 , V_2 ) ;
}
static struct V_5 * T_1 F_3 ( void )
{
struct V_5 * V_6 = NULL ;
F_4 (gx_pci) {
if ( ( F_5 ( V_7 , V_6 ) ) != NULL )
return V_6 ;
}
F_6 ( L_1 ) ;
return NULL ;
}
static unsigned int F_7 ( unsigned int V_8 )
{
if ( ( V_3 -> V_9 & V_10 ) == 0 )
return V_11 ;
return ( V_11 * V_3 -> V_12 )
/ ( V_3 -> V_13 + V_3 -> V_12 ) ;
}
static unsigned int F_8 ( unsigned int V_14 , T_2 * V_13 ,
T_2 * V_12 )
{
unsigned int V_15 ;
T_2 V_16 , V_17 ;
int V_18 = V_11 ;
int V_19 ;
* V_12 = 1 ;
* V_13 = 0 ;
for ( V_15 = V_20 ; V_15 > 0 ; V_15 -- ) {
V_17 = ( ( V_14 * V_15 ) / V_11 ) & 0xff ;
V_16 = V_15 - V_17 ;
V_19 = ( V_11 * V_17 ) / V_15 ;
if ( abs ( V_19 - V_14 ) <= abs ( V_18 - V_14 ) ) {
* V_13 = V_16 ;
* V_12 = V_17 ;
V_18 = V_19 ;
}
}
return V_18 ;
}
static void F_9 ( struct V_21 * V_22 , unsigned int V_14 )
{
T_2 V_23 , V_24 ;
unsigned int V_25 ;
unsigned long V_26 ;
struct V_27 V_28 ;
V_28 . V_29 = F_7 ( 0 ) ;
V_25 = F_8 ( V_14 , & V_3 -> V_13 ,
& V_3 -> V_12 ) ;
V_28 . V_30 = V_25 ;
F_10 ( V_22 , & V_28 , V_31 ) ;
F_11 ( V_26 ) ;
if ( V_25 != V_11 ) {
switch ( V_3 -> V_4 -> V_32 ) {
case V_33 :
V_24 = V_3 -> V_34 | V_35 | V_36 ;
F_1 ( V_37 , 4 ) ;
F_1 ( V_38 , 100 ) ;
F_1 ( V_39 , V_24 ) ;
if ( V_3 -> V_4 -> V_40 < 0x10 ) {
V_23 = V_3 -> V_9 | V_10 ;
} else {
V_23 = V_3 -> V_9 | V_10 | V_41 ;
}
break;
case V_42 :
case V_43 :
V_23 = V_3 -> V_9 | V_10 ;
break;
default:
F_12 ( V_26 ) ;
F_6 ( L_2 ) ;
return;
}
} else {
V_23 = V_3 -> V_9 & ~ ( V_10 ) ;
V_3 -> V_12 = 0 ;
V_3 -> V_13 = 0 ;
F_6 ( L_3 ) ;
}
F_1 ( V_44 , V_3 -> V_12 ) ;
F_1 ( V_45 , V_3 -> V_13 ) ;
F_1 ( V_46 , V_23 ) ;
F_13 ( V_3 -> V_4 , V_46 , & V_23 ) ;
F_12 ( V_26 ) ;
V_3 -> V_9 = V_23 ;
F_10 ( V_22 , & V_28 , V_47 ) ;
F_6 ( L_4 ,
V_3 -> V_13 * 32 , V_3 -> V_12 * 32 ) ;
F_6 ( L_5 , V_28 . V_30 ) ;
}
static int F_14 ( struct V_21 * V_22 )
{
unsigned int V_19 = 0 ;
T_2 V_48 , V_49 ;
if ( ! V_11 || ! V_22 )
return - V_50 ;
V_22 -> V_8 = 0 ;
F_15 ( V_22 , ( V_11 / V_20 ) ,
V_11 ) ;
V_19 = F_8 ( V_22 -> V_51 , & V_48 , & V_49 ) ;
if ( V_19 < V_22 -> V_51 )
V_19 += V_11 / V_20 ;
V_22 -> V_51 = V_19 ;
if ( V_22 -> V_51 > V_22 -> V_52 )
V_22 -> V_52 = V_19 ;
V_19 = F_8 ( V_22 -> V_52 , & V_48 , & V_49 ) ;
if ( V_19 > V_22 -> V_52 )
V_19 -= V_11 / V_20 ;
V_22 -> V_52 = V_19 ;
if ( V_22 -> V_52 < V_22 -> V_51 )
V_22 -> V_52 = V_22 -> V_51 ;
F_15 ( V_22 , ( V_11 / V_20 ) ,
V_11 ) ;
return 0 ;
}
static int F_16 ( struct V_21 * V_22 ,
unsigned int V_53 ,
unsigned int V_54 )
{
T_2 V_48 , V_49 ;
unsigned int V_19 ;
if ( ! V_11 || ! V_22 )
return - V_50 ;
V_22 -> V_8 = 0 ;
V_19 = F_8 ( V_53 , & V_48 , & V_49 ) ;
while ( V_19 < V_22 -> V_51 ) {
V_19 += V_11 / V_20 ;
V_19 = F_8 ( V_19 , & V_48 , & V_49 ) ;
}
while ( V_19 > V_22 -> V_52 ) {
V_19 -= V_11 / V_20 ;
V_19 = F_8 ( V_19 , & V_48 , & V_49 ) ;
}
F_9 ( V_22 , V_19 ) ;
return 0 ;
}
static int F_17 ( struct V_21 * V_22 )
{
unsigned int V_55 ;
if ( ! V_22 || V_22 -> V_8 != 0 )
return - V_56 ;
if ( V_57 )
V_55 = V_57 * V_58 [ F_18 ( V_59 ) & 0x0f ] ;
else if ( V_60 )
V_55 = V_60 ;
else
V_55 = 30000 * V_58 [ F_18 ( V_59 ) & 0x0f ] ;
V_11 = V_55 ;
F_6 ( L_6 , V_55 ) ;
V_22 -> V_8 = 0 ;
if ( V_20 < V_61 )
V_22 -> V_51 = V_55 / V_20 ;
else
V_22 -> V_51 = V_55 / V_61 ;
V_22 -> V_52 = V_55 ;
V_22 -> V_62 . V_63 = V_55 / V_20 ;
V_22 -> V_62 . V_64 = V_55 ;
V_22 -> V_62 . V_65 = V_66 ;
return 0 ;
}
static int T_1 F_19 ( void )
{
int V_67 ;
struct V_68 * V_69 ;
struct V_5 * V_6 ;
V_6 = F_3 () ;
if ( V_6 == NULL )
return - V_56 ;
if ( V_20 > 0xff )
V_20 = 0xff ;
F_6 ( L_7 ) ;
V_69 = F_20 ( sizeof( * V_69 ) , V_70 ) ;
if ( V_69 == NULL )
return - V_71 ;
V_69 -> V_4 = V_6 ;
V_3 = V_69 ;
F_13 ( V_69 -> V_4 , V_46 , & ( V_69 -> V_9 ) ) ;
F_13 ( V_69 -> V_4 , V_39 , & ( V_69 -> V_34 ) ) ;
F_13 ( V_69 -> V_4 , V_72 , & ( V_69 -> V_73 ) ) ;
F_13 ( V_69 -> V_4 , V_45 , & ( V_69 -> V_13 ) ) ;
F_13 ( V_69 -> V_4 , V_44 ,
& ( V_69 -> V_12 ) ) ;
V_67 = F_21 ( & V_74 ) ;
if ( V_67 ) {
F_22 ( V_69 ) ;
return V_67 ;
}
return 0 ;
}
static void T_3 F_23 ( void )
{
F_24 ( & V_74 ) ;
F_25 ( V_3 -> V_4 ) ;
F_22 ( V_3 ) ;
}
