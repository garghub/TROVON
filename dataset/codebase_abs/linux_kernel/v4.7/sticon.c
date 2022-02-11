static inline void F_1 ( void )
{
V_1 = 0 ;
V_2 = 0 ;
}
static const char * F_2 ( void )
{
return L_1 ;
}
static int F_3 ( struct V_3 * V_4 , const unsigned char * V_5 )
{
return - V_6 ;
}
static void F_4 ( struct V_3 * V_7 , int V_4 , int V_8 , int V_9 )
{
int V_10 = 0 ;
if ( V_11 || V_12 )
return;
if ( V_7 -> V_13 != V_14 )
return;
#if 0
if ((p->cursor_x == xpos) && (p->cursor_y == ypos)) {
cursor_undrawn();
redraw_cursor = 1;
}
#endif
F_5 ( V_15 , V_4 , V_8 , V_9 ) ;
if ( V_10 )
V_1 = V_16 ;
}
static void F_6 ( struct V_3 * V_7 , const unsigned short * V_17 ,
int V_18 , int V_8 , int V_9 )
{
int V_10 = 0 ;
if ( V_11 || V_12 )
return;
if ( V_7 -> V_13 != V_14 )
return;
#if 0
if ((p->cursor_y == ypos) && (xpos <= p->cursor_x) &&
(p->cursor_x < (xpos + count))) {
cursor_undrawn();
redraw_cursor = 1;
}
#endif
while ( V_18 -- ) {
F_5 ( V_15 , F_7 ( V_17 ++ ) , V_8 , V_9 ++ ) ;
}
if ( V_10 )
V_1 = V_16 ;
}
static void F_8 ( struct V_3 * V_7 , int V_19 )
{
unsigned short V_20 ;
V_20 = V_7 -> V_21 [ V_7 -> V_22 + V_7 -> V_23 * V_7 -> V_24 ] ;
switch ( V_19 ) {
case V_25 :
F_5 ( V_15 , V_20 , V_7 -> V_23 , V_7 -> V_22 ) ;
break;
case V_26 :
case V_27 :
switch ( V_7 -> V_28 & 0x0f ) {
case V_29 :
case V_30 :
case V_31 :
case V_32 :
case V_33 :
F_5 ( V_15 , ( V_20 & 255 ) + ( 0 << 8 ) + ( 7 << 11 ) ,
V_7 -> V_23 , V_7 -> V_22 ) ;
break;
}
break;
}
}
static int F_9 ( struct V_3 * V_7 , int V_34 , int V_35 , int V_36 , int V_18 )
{
struct V_37 * V_38 = V_15 ;
if ( V_11 )
return 0 ;
F_8 ( V_7 , V_25 ) ;
switch ( V_36 ) {
case V_39 :
F_10 ( V_38 , V_34 + V_18 , 0 , V_34 , 0 , V_35 - V_34 - V_18 , V_7 -> V_24 ) ;
F_11 ( V_38 , V_35 - V_18 , 0 , V_18 , V_7 -> V_24 , V_7 -> V_40 ) ;
break;
case V_41 :
F_10 ( V_38 , V_34 , 0 , V_34 + V_18 , 0 , V_35 - V_34 - V_18 , V_7 -> V_24 ) ;
F_11 ( V_38 , V_34 , 0 , V_18 , V_7 -> V_24 , V_7 -> V_40 ) ;
break;
}
return 0 ;
}
static void F_12 ( struct V_3 * V_7 , int V_42 , int V_43 ,
int V_44 , int V_45 , int V_46 , int V_47 )
{
if ( ! V_47 || ! V_46 )
return;
#if 0
if (((sy <= p->cursor_y) && (p->cursor_y < sy+height) &&
(sx <= p->cursor_x) && (p->cursor_x < sx+width)) ||
((dy <= p->cursor_y) && (p->cursor_y < dy+height) &&
(dx <= p->cursor_x) && (p->cursor_x < dx+width)))
sticon_cursor(p, CM_ERASE );
#endif
F_10 ( V_15 , V_42 , V_43 , V_44 , V_45 , V_46 , V_47 ) ;
}
static void F_13 ( struct V_3 * V_4 , int V_48 )
{
struct V_37 * V_38 = V_15 ;
int V_24 , V_49 ;
F_14 ( V_38 , 0 , 0 , F_15 ( V_38 ) , F_16 ( V_38 ) , 0 ) ;
V_24 = F_16 ( V_38 ) / V_38 -> V_50 ;
V_49 = F_15 ( V_38 ) / V_38 -> V_51 ;
V_4 -> V_52 = 1 ;
if ( V_48 ) {
V_4 -> V_24 = V_24 ;
V_4 -> V_49 = V_49 ;
} else {
F_17 ( V_4 , V_24 , V_49 ) ;
}
}
static void F_18 ( struct V_3 * V_4 )
{
}
static void F_19 ( struct V_3 * V_7 , int V_42 , int V_43 , int V_46 ,
int V_47 )
{
if ( ! V_46 || ! V_47 )
return;
F_11 ( V_15 , V_42 , V_43 , V_46 , V_47 , V_7 -> V_40 ) ;
}
static int F_20 ( struct V_3 * V_7 )
{
return 1 ;
}
static int F_21 ( struct V_3 * V_7 )
{
return 0 ;
}
static int F_22 ( struct V_3 * V_4 , int V_53 , int V_54 )
{
if ( V_53 == 0 ) {
if ( V_54 )
V_11 = 0 ;
return 1 ;
}
F_21 ( V_4 ) ;
F_11 ( V_15 , 0 , 0 , V_4 -> V_49 , V_4 -> V_24 , V_55 ) ;
if ( V_54 )
V_11 = 1 ;
return 1 ;
}
static int F_23 ( struct V_3 * V_7 , int V_56 )
{
return 0 ;
}
static T_1 * F_24 ( struct V_3 * V_7 , int V_57 )
{
int line ;
unsigned long V_58 ;
if ( V_7 -> V_59 != V_60 || ! V_61 )
return ( T_1 * ) ( V_7 -> V_62 + V_57 ) ;
line = V_57 / V_7 -> V_63 ;
if ( line >= V_61 )
return ( T_1 * ) ( V_7 -> V_62 + V_57 - V_61 * V_7 -> V_63 ) ;
V_58 = V_64 + V_57 ;
if ( V_58 >= V_65 )
V_58 += V_66 - V_65 ;
return ( T_1 * ) V_58 ;
}
static unsigned long F_25 ( struct V_3 * V_7 , unsigned long V_67 ,
int * V_68 , int * V_69 )
{
int V_70 , V_71 ;
unsigned long V_72 ;
if ( V_67 >= V_7 -> V_62 && V_67 < V_7 -> V_73 ) {
unsigned long V_57 = ( V_67 - V_7 -> V_62 ) / 2 ;
V_70 = V_57 % V_7 -> V_24 ;
V_71 = V_57 / V_7 -> V_24 ;
if ( V_7 -> V_59 == V_60 )
V_71 += V_61 ;
V_72 = V_67 + ( V_7 -> V_24 - V_70 ) * 2 ;
} else if ( V_7 -> V_59 == V_60 && V_61 ) {
unsigned long V_57 = V_67 - V_64 ;
if ( V_67 < V_64 )
V_57 += V_65 - V_66 ;
V_57 /= 2 ;
V_70 = V_57 % V_7 -> V_24 ;
V_71 = V_57 / V_7 -> V_24 ;
V_72 = V_67 + ( V_7 -> V_24 - V_70 ) * 2 ;
if ( V_72 == V_65 )
V_72 = V_66 ;
if ( V_72 == V_74 )
V_72 = V_7 -> V_62 ;
} else {
V_70 = V_71 = 0 ;
V_72 = V_7 -> V_62 ;
}
if ( V_68 ) * V_68 = V_70 ;
if ( V_69 ) * V_69 = V_71 ;
return V_72 ;
}
static T_2 F_26 ( struct V_3 * V_7 , T_2 V_75 , T_2 V_76 ,
T_2 V_77 , T_2 V_78 , T_2 V_79 , T_2 V_80 )
{
T_2 V_81 = ( ( V_75 & 0x70 ) >> 1 ) | ( ( V_75 & 7 ) ) ;
if ( V_79 ) {
V_75 = ( ( V_75 >> 3 ) & 0x7 ) | ( ( V_75 & 0x7 ) << 3 ) ;
}
return V_81 ;
}
static void F_27 ( struct V_3 * V_7 , T_1 * V_58 , int V_18 )
{
int V_82 = 1 ;
while ( V_18 -- ) {
T_1 V_83 = F_7 ( V_58 ) ;
if ( V_82 )
V_83 = ( ( V_83 ) & 0x88ff ) | ( ( ( V_83 ) & 0x7000 ) >> 4 ) | ( ( ( V_83 ) & 0x0700 ) << 4 ) ;
else
V_83 = ( ( V_83 & 0x0700 ) == 0x0100 ) ? 0x7000 : 0x7700 ;
F_28 ( V_83 , V_58 ++ ) ;
}
}
static void F_29 ( struct V_3 * V_7 )
{
}
static int T_3 F_30 ( void )
{
int V_84 ;
if ( V_15 )
return 0 ;
V_15 = F_31 ( 0 ) ;
if ( ! V_15 )
return - V_85 ;
if ( V_86 == & V_87 ) {
F_32 ( V_88 L_2 ) ;
F_33 () ;
V_84 = F_34 ( & V_89 , 0 , V_90 - 1 , 1 ) ;
F_35 () ;
return V_84 ;
}
return 0 ;
}
