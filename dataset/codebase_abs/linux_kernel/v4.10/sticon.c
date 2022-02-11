static inline void F_1 ( void )
{
V_1 = 0 ;
V_2 = 0 ;
}
static const char * F_2 ( void )
{
return L_1 ;
}
static void F_3 ( struct V_3 * V_4 , int V_5 , int V_6 , int V_7 )
{
int V_8 = 0 ;
if ( V_9 || V_10 )
return;
if ( V_4 -> V_11 != V_12 )
return;
#if 0
if ((p->cursor_x == xpos) && (p->cursor_y == ypos)) {
cursor_undrawn();
redraw_cursor = 1;
}
#endif
F_4 ( V_13 , V_5 , V_6 , V_7 ) ;
if ( V_8 )
V_1 = V_14 ;
}
static void F_5 ( struct V_3 * V_4 , const unsigned short * V_15 ,
int V_16 , int V_6 , int V_7 )
{
int V_8 = 0 ;
if ( V_9 || V_10 )
return;
if ( V_4 -> V_11 != V_12 )
return;
#if 0
if ((p->cursor_y == ypos) && (xpos <= p->cursor_x) &&
(p->cursor_x < (xpos + count))) {
cursor_undrawn();
redraw_cursor = 1;
}
#endif
while ( V_16 -- ) {
F_4 ( V_13 , F_6 ( V_15 ++ ) , V_6 , V_7 ++ ) ;
}
if ( V_8 )
V_1 = V_14 ;
}
static void F_7 ( struct V_3 * V_4 , int V_17 )
{
unsigned short V_18 ;
V_18 = V_4 -> V_19 [ V_4 -> V_20 + V_4 -> V_21 * V_4 -> V_22 ] ;
switch ( V_17 ) {
case V_23 :
F_4 ( V_13 , V_18 , V_4 -> V_21 , V_4 -> V_20 ) ;
break;
case V_24 :
case V_25 :
switch ( V_4 -> V_26 & 0x0f ) {
case V_27 :
case V_28 :
case V_29 :
case V_30 :
case V_31 :
F_4 ( V_13 , ( V_18 & 255 ) + ( 0 << 8 ) + ( 7 << 11 ) ,
V_4 -> V_21 , V_4 -> V_20 ) ;
break;
}
break;
}
}
static bool F_8 ( struct V_3 * V_4 , unsigned int V_32 ,
unsigned int V_33 , enum V_34 V_35 , unsigned int V_16 )
{
struct V_36 * V_37 = V_13 ;
if ( V_9 )
return false ;
F_7 ( V_4 , V_23 ) ;
switch ( V_35 ) {
case V_38 :
F_9 ( V_37 , V_32 + V_16 , 0 , V_32 , 0 , V_33 - V_32 - V_16 , V_4 -> V_22 ) ;
F_10 ( V_37 , V_33 - V_16 , 0 , V_16 , V_4 -> V_22 , V_4 -> V_39 ) ;
break;
case V_40 :
F_9 ( V_37 , V_32 , 0 , V_32 + V_16 , 0 , V_33 - V_32 - V_16 , V_4 -> V_22 ) ;
F_10 ( V_37 , V_32 , 0 , V_16 , V_4 -> V_22 , V_4 -> V_39 ) ;
break;
}
return false ;
}
static void F_11 ( struct V_3 * V_5 , int V_41 )
{
struct V_36 * V_37 = V_13 ;
int V_22 , V_42 ;
F_12 ( V_37 , 0 , 0 , F_13 ( V_37 ) , F_14 ( V_37 ) , 0 ) ;
V_22 = F_14 ( V_37 ) / V_37 -> V_43 ;
V_42 = F_13 ( V_37 ) / V_37 -> V_44 ;
V_5 -> V_45 = 1 ;
if ( V_41 ) {
V_5 -> V_22 = V_22 ;
V_5 -> V_42 = V_42 ;
} else {
F_15 ( V_5 , V_22 , V_42 ) ;
}
}
static void F_16 ( struct V_3 * V_5 )
{
}
static void F_17 ( struct V_3 * V_4 , int V_46 , int V_47 , int V_48 ,
int V_49 )
{
if ( ! V_48 || ! V_49 )
return;
F_10 ( V_13 , V_46 , V_47 , V_48 , V_49 , V_4 -> V_39 ) ;
}
static int F_18 ( struct V_3 * V_4 )
{
return 1 ;
}
static int F_19 ( struct V_3 * V_4 )
{
return 0 ;
}
static int F_20 ( struct V_3 * V_5 , int V_50 , int V_51 )
{
if ( V_50 == 0 ) {
if ( V_51 )
V_9 = 0 ;
return 1 ;
}
F_19 ( V_5 ) ;
F_10 ( V_13 , 0 , 0 , V_5 -> V_42 , V_5 -> V_22 , V_52 ) ;
if ( V_51 )
V_9 = 1 ;
return 1 ;
}
static T_1 * F_21 ( struct V_3 * V_4 , int V_53 )
{
int line ;
unsigned long V_54 ;
if ( V_4 -> V_55 != V_56 || ! V_57 )
return ( T_1 * ) ( V_4 -> V_58 + V_53 ) ;
line = V_53 / V_4 -> V_59 ;
if ( line >= V_57 )
return ( T_1 * ) ( V_4 -> V_58 + V_53 - V_57 * V_4 -> V_59 ) ;
V_54 = V_60 + V_53 ;
if ( V_54 >= V_61 )
V_54 += V_62 - V_61 ;
return ( T_1 * ) V_54 ;
}
static unsigned long F_22 ( struct V_3 * V_4 , unsigned long V_63 ,
int * V_64 , int * V_65 )
{
int V_66 , V_67 ;
unsigned long V_68 ;
if ( V_63 >= V_4 -> V_58 && V_63 < V_4 -> V_69 ) {
unsigned long V_53 = ( V_63 - V_4 -> V_58 ) / 2 ;
V_66 = V_53 % V_4 -> V_22 ;
V_67 = V_53 / V_4 -> V_22 ;
if ( V_4 -> V_55 == V_56 )
V_67 += V_57 ;
V_68 = V_63 + ( V_4 -> V_22 - V_66 ) * 2 ;
} else if ( V_4 -> V_55 == V_56 && V_57 ) {
unsigned long V_53 = V_63 - V_60 ;
if ( V_63 < V_60 )
V_53 += V_61 - V_62 ;
V_53 /= 2 ;
V_66 = V_53 % V_4 -> V_22 ;
V_67 = V_53 / V_4 -> V_22 ;
V_68 = V_63 + ( V_4 -> V_22 - V_66 ) * 2 ;
if ( V_68 == V_61 )
V_68 = V_62 ;
if ( V_68 == V_70 )
V_68 = V_4 -> V_58 ;
} else {
V_66 = V_67 = 0 ;
V_68 = V_4 -> V_58 ;
}
if ( V_64 ) * V_64 = V_66 ;
if ( V_65 ) * V_65 = V_67 ;
return V_68 ;
}
static T_2 F_23 ( struct V_3 * V_4 , T_2 V_71 , T_2 V_72 ,
T_2 V_73 , T_2 V_74 , T_2 V_75 , T_2 V_76 )
{
T_2 V_77 = ( ( V_71 & 0x70 ) >> 1 ) | ( ( V_71 & 7 ) ) ;
if ( V_75 ) {
V_71 = ( ( V_71 >> 3 ) & 0x7 ) | ( ( V_71 & 0x7 ) << 3 ) ;
}
return V_77 ;
}
static void F_24 ( struct V_3 * V_4 , T_1 * V_54 , int V_16 )
{
int V_78 = 1 ;
while ( V_16 -- ) {
T_1 V_79 = F_6 ( V_54 ) ;
if ( V_78 )
V_79 = ( ( V_79 ) & 0x88ff ) | ( ( ( V_79 ) & 0x7000 ) >> 4 ) | ( ( ( V_79 ) & 0x0700 ) << 4 ) ;
else
V_79 = ( ( V_79 & 0x0700 ) == 0x0100 ) ? 0x7000 : 0x7700 ;
F_25 ( V_79 , V_54 ++ ) ;
}
}
static void F_26 ( struct V_3 * V_4 )
{
}
static int T_3 F_27 ( void )
{
int V_80 ;
if ( V_13 )
return 0 ;
V_13 = F_28 ( 0 ) ;
if ( ! V_13 )
return - V_81 ;
if ( V_82 == & V_83 ) {
F_29 ( V_84 L_2 ) ;
F_30 () ;
V_80 = F_31 ( & V_85 , 0 , V_86 - 1 , 1 ) ;
F_32 () ;
return V_80 ;
}
return 0 ;
}
