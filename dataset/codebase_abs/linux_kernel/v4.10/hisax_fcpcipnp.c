static unsigned char F_1 ( struct V_1 * V_1 , unsigned char V_2 )
{
struct V_3 * V_4 = V_1 -> V_5 ;
unsigned char V_6 = ( V_2 > 0x2f ) ?
V_7 : V_8 ;
unsigned char V_9 ;
unsigned long V_10 ;
F_2 ( & V_4 -> V_11 , V_10 ) ;
F_3 ( V_6 , V_4 -> V_12 + V_13 ) ;
V_9 = F_4 ( V_4 -> V_12 + V_14 + ( V_2 & 0xf ) ) ;
F_5 ( & V_4 -> V_11 , V_10 ) ;
F_6 ( 0x1000 , L_1 ,
V_2 , V_9 ) ;
return V_9 ;
}
static void F_7 ( struct V_1 * V_1 , unsigned char V_2 ,
unsigned char V_15 )
{
struct V_3 * V_4 = V_1 -> V_5 ;
unsigned char V_6 = ( V_2 > 0x2f ) ?
V_7 : V_8 ;
unsigned long V_10 ;
F_6 ( 0x1000 , L_1 ,
V_2 , V_15 ) ;
F_2 ( & V_4 -> V_11 , V_10 ) ;
F_3 ( V_6 , V_4 -> V_12 + V_13 ) ;
F_3 ( V_15 , V_4 -> V_12 + V_14 + ( V_2 & 0xf ) ) ;
F_5 ( & V_4 -> V_11 , V_10 ) ;
}
static void F_8 ( struct V_1 * V_1 , unsigned char * V_16 ,
int V_17 )
{
struct V_3 * V_4 = V_1 -> V_5 ;
unsigned long V_10 ;
F_2 ( & V_4 -> V_11 , V_10 ) ;
F_3 ( V_18 , V_4 -> V_12 + V_13 ) ;
F_9 ( V_4 -> V_12 + V_14 , V_16 , V_17 ) ;
F_5 ( & V_4 -> V_11 , V_10 ) ;
}
static void F_10 ( struct V_1 * V_1 , unsigned char * V_16 ,
int V_17 )
{
struct V_3 * V_4 = V_1 -> V_5 ;
unsigned long V_10 ;
F_2 ( & V_4 -> V_11 , V_10 ) ;
F_3 ( V_18 , V_4 -> V_12 + V_13 ) ;
F_11 ( V_4 -> V_12 + V_14 , V_16 , V_17 ) ;
F_5 ( & V_4 -> V_11 , V_10 ) ;
}
static T_1 F_12 ( struct V_3 * V_4 , int V_19 )
{
T_1 V_9 ;
int V_6 = V_19 ? V_20 : V_21 ;
unsigned long V_10 ;
F_2 ( & V_4 -> V_11 , V_10 ) ;
F_13 ( V_6 , V_4 -> V_12 + V_13 ) ;
V_9 = F_14 ( V_4 -> V_12 + V_14 + V_22 ) ;
F_5 ( & V_4 -> V_11 , V_10 ) ;
return V_9 ;
}
static void F_15 ( struct V_23 * V_24 , int V_25 )
{
struct V_3 * V_4 = V_24 -> V_4 ;
int V_6 = V_24 -> V_26 ? V_20 : V_21 ;
F_6 ( 0x40 , L_2 ,
'A' + V_24 -> V_26 , V_25 , V_24 -> V_27 . V_27 ) ;
F_13 ( V_6 , V_4 -> V_12 + V_13 ) ;
F_13 ( V_24 -> V_27 . V_27 , V_4 -> V_12 + V_14 + V_28 ) ;
}
static void F_16 ( struct V_23 * V_24 , int V_25 )
{
struct V_3 * V_4 = V_24 -> V_4 ;
unsigned long V_10 ;
F_2 ( & V_4 -> V_11 , V_10 ) ;
F_15 ( V_24 , V_25 ) ;
F_5 ( & V_4 -> V_11 , V_10 ) ;
}
static unsigned char F_17 ( struct V_1 * V_1 , unsigned char V_2 )
{
struct V_3 * V_4 = V_1 -> V_5 ;
unsigned char V_9 ;
unsigned long V_10 ;
F_2 ( & V_4 -> V_11 , V_10 ) ;
F_13 ( V_2 , V_4 -> V_12 + V_29 ) ;
V_9 = F_14 ( V_4 -> V_12 + V_30 ) ;
F_5 ( & V_4 -> V_11 , V_10 ) ;
F_6 ( 0x1000 , L_1 ,
V_2 , V_9 ) ;
return V_9 ;
}
static void F_18 ( struct V_1 * V_1 , unsigned char V_2 ,
unsigned char V_15 )
{
struct V_3 * V_4 = V_1 -> V_5 ;
unsigned long V_10 ;
F_6 ( 0x1000 , L_1 ,
V_2 , V_15 ) ;
F_2 ( & V_4 -> V_11 , V_10 ) ;
F_13 ( V_2 , V_4 -> V_12 + V_29 ) ;
F_13 ( V_15 , V_4 -> V_12 + V_30 ) ;
F_5 ( & V_4 -> V_11 , V_10 ) ;
}
static void F_19 ( struct V_1 * V_1 , unsigned char * V_16 ,
int V_17 )
{
struct V_3 * V_4 = V_1 -> V_5 ;
int V_31 ;
unsigned long V_10 ;
F_2 ( & V_4 -> V_11 , V_10 ) ;
F_13 ( 0 , V_4 -> V_12 + V_29 ) ;
for ( V_31 = 0 ; V_31 < V_17 ; V_31 ++ )
V_16 [ V_31 ] = F_14 ( V_4 -> V_12 + V_30 ) ;
F_5 ( & V_4 -> V_11 , V_10 ) ;
}
static void F_20 ( struct V_1 * V_1 , unsigned char * V_16 ,
int V_17 )
{
struct V_3 * V_4 = V_1 -> V_5 ;
int V_31 ;
unsigned long V_10 ;
F_2 ( & V_4 -> V_11 , V_10 ) ;
F_13 ( 0 , V_4 -> V_12 + V_29 ) ;
for ( V_31 = 0 ; V_31 < V_17 ; V_31 ++ )
F_13 ( V_16 [ V_31 ] , V_4 -> V_12 + V_30 ) ;
F_5 ( & V_4 -> V_11 , V_10 ) ;
}
static T_1 F_21 ( struct V_3 * V_4 , int V_19 )
{
int V_2 = V_19 ? V_32 : V_33 ;
return F_14 ( V_4 -> V_12 + V_2 ) ;
}
static void F_22 ( struct V_23 * V_24 , int V_25 )
{
struct V_3 * V_4 = V_24 -> V_4 ;
int V_2 = V_24 -> V_26 ? V_32 : V_33 ;
F_6 ( 0x40 , L_2 ,
'A' + V_24 -> V_26 , V_25 , V_24 -> V_27 . V_27 ) ;
F_13 ( V_24 -> V_27 . V_27 , V_4 -> V_12 + V_2 ) ;
}
static T_1 F_23 ( struct V_3 * V_4 , int V_19 )
{
unsigned char V_6 = V_19 ? V_20 : V_21 ;
T_1 V_9 ;
unsigned long V_10 ;
F_2 ( & V_4 -> V_11 , V_10 ) ;
F_3 ( V_6 , V_4 -> V_12 + V_13 ) ;
V_9 = F_4 ( V_4 -> V_12 + V_14 + V_22 ) ;
if ( V_9 & V_34 )
V_9 |= F_4 ( V_4 -> V_12 + V_14 + V_22 + 1 ) << 8 ;
F_5 ( & V_4 -> V_11 , V_10 ) ;
return V_9 ;
}
static void F_24 ( struct V_23 * V_24 , int V_25 )
{
struct V_3 * V_4 = V_24 -> V_4 ;
unsigned char V_6 = V_24 -> V_26 ? V_20 : V_21 ;
F_6 ( 0x40 , L_2 ,
'A' + V_24 -> V_26 , V_25 , V_24 -> V_27 . V_27 ) ;
F_3 ( V_6 , V_4 -> V_12 + V_13 ) ;
if ( V_25 & 4 )
F_3 ( V_24 -> V_27 . V_35 . V_36 ,
V_4 -> V_12 + V_14 + V_22 + 2 ) ;
if ( V_25 & 2 )
F_3 ( V_24 -> V_27 . V_35 . V_37 ,
V_4 -> V_12 + V_14 + V_22 + 1 ) ;
if ( V_25 & 1 )
F_3 ( V_24 -> V_27 . V_35 . V_38 ,
V_4 -> V_12 + V_14 + V_22 + 0 ) ;
}
static void F_25 ( struct V_23 * V_24 , int V_25 )
{
struct V_3 * V_4 = V_24 -> V_4 ;
unsigned long V_10 ;
F_2 ( & V_4 -> V_11 , V_10 ) ;
F_24 ( V_24 , V_25 ) ;
F_5 ( & V_4 -> V_11 , V_10 ) ;
}
static inline void F_26 ( struct V_23 * V_24 , int V_39 , void * V_40 )
{
struct V_41 * V_42 = (struct V_41 * ) & V_24 -> V_43 ;
F_6 ( 2 , L_3 , V_39 ) ;
V_42 -> V_44 ( V_42 , V_39 , V_40 ) ;
}
static void F_27 ( struct V_23 * V_24 )
{
struct V_3 * V_4 = V_24 -> V_4 ;
struct V_45 * V_46 = V_24 -> V_47 ;
int V_48 ;
unsigned long V_10 ;
unsigned char * V_49 ;
F_6 ( 0x40 , L_4 ) ;
F_28 ( V_46 -> V_50 == 0 ) ;
V_24 -> V_27 . V_35 . V_38 &= ~ V_51 ;
if ( V_24 -> V_47 -> V_50 > V_24 -> V_52 ) {
V_48 = V_24 -> V_52 ;
} else {
V_48 = V_24 -> V_47 -> V_50 ;
if ( V_24 -> V_36 != V_53 )
V_24 -> V_27 . V_35 . V_38 |= V_51 ;
}
F_6 ( 0x40 , L_5 , V_48 , V_24 -> V_47 -> V_50 ) ;
V_49 = V_24 -> V_47 -> V_16 ;
F_29 ( V_24 -> V_47 , V_48 ) ;
V_24 -> V_54 += V_48 ;
V_24 -> V_27 . V_35 . V_37 = ( ( V_48 == V_24 -> V_52 ) ? 0 : V_48 ) ;
switch ( V_4 -> type ) {
case V_55 :
F_2 ( & V_4 -> V_11 , V_10 ) ;
F_15 ( V_24 , 3 ) ;
F_30 ( V_4 -> V_12 + V_14 + V_56 ,
V_49 , ( V_48 + 3 ) / 4 ) ;
F_5 ( & V_4 -> V_11 , V_10 ) ;
break;
case V_57 :
F_22 ( V_24 , 3 ) ;
F_30 ( V_4 -> V_12 +
( V_24 -> V_26 ? V_58 : V_59 ) ,
V_49 , ( V_48 + 3 ) / 4 ) ;
break;
case V_60 :
F_2 ( & V_4 -> V_11 , V_10 ) ;
F_24 ( V_24 , 3 ) ;
F_11 ( V_4 -> V_12 + V_14 , V_49 , V_48 ) ;
F_5 ( & V_4 -> V_11 , V_10 ) ;
break;
}
}
static inline void F_31 ( struct V_23 * V_24 , int V_48 )
{
struct V_3 * V_4 = V_24 -> V_4 ;
unsigned char * V_49 ;
unsigned char V_6 = V_24 -> V_26 ? V_20 : V_21 ;
F_6 ( 0x10 , L_6 , V_48 ) ;
if ( V_24 -> V_61 + V_48 > V_62 ) {
F_6 ( 0x10 , L_7 ) ;
return;
}
V_49 = V_24 -> V_63 + V_24 -> V_61 ;
V_24 -> V_61 += V_48 ;
switch ( V_4 -> type ) {
case V_55 :
F_32 ( & V_4 -> V_11 ) ;
F_13 ( V_6 , V_4 -> V_12 + V_13 ) ;
F_33 ( V_4 -> V_12 + V_14 + V_56 ,
V_49 , ( V_48 + 3 ) / 4 ) ;
F_34 ( & V_4 -> V_11 ) ;
break;
case V_57 :
F_33 ( V_4 -> V_12 +
( V_24 -> V_26 ? V_58 : V_59 ) ,
V_49 , ( V_48 + 3 ) / 4 ) ;
break;
case V_60 :
F_32 ( & V_4 -> V_11 ) ;
F_3 ( V_6 , V_4 -> V_12 + V_13 ) ;
F_9 ( V_4 -> V_12 + V_14 , V_49 , V_48 ) ;
F_34 ( & V_4 -> V_11 ) ;
break;
}
}
static inline void F_35 ( struct V_23 * V_24 , T_1 V_64 )
{
struct V_3 * V_4 = V_24 -> V_4 ;
struct V_45 * V_46 ;
int V_50 ;
if ( V_64 & V_65 ) {
F_6 ( 0x10 , L_8 ) ;
V_24 -> V_27 . V_35 . V_37 = 0 ;
V_24 -> V_27 . V_35 . V_38 |= V_66 ;
V_4 -> V_67 ( V_24 , 1 ) ;
V_24 -> V_27 . V_35 . V_38 &= ~ V_66 ;
V_4 -> V_67 ( V_24 , 1 ) ;
V_24 -> V_61 = 0 ;
return;
}
V_50 = ( V_64 & V_68 ) >> 8 ;
if ( V_50 == 0 )
V_50 = V_24 -> V_52 ;
F_31 ( V_24 , V_50 ) ;
if ( ( V_64 & V_69 ) || ( V_24 -> V_36 == V_53 ) ) {
if ( ( ( V_64 & V_70 ) == V_71 ) ||
( V_24 -> V_36 == V_53 ) ) {
V_46 = F_36 ( V_24 -> V_61 ) ;
if ( ! V_46 ) {
F_37 ( V_72 L_9 ) ;
} else {
memcpy ( F_38 ( V_46 , V_24 -> V_61 ) , V_24 -> V_63 ,
V_24 -> V_61 ) ;
F_39 ( 1 , V_46 ) ;
F_26 ( V_24 , V_73 | V_74 , V_46 ) ;
}
V_24 -> V_61 = 0 ;
} else {
F_6 ( 0x10 , L_10 ,
V_24 -> V_26 , V_64 ) ;
V_24 -> V_61 = 0 ;
}
}
}
static inline void F_40 ( struct V_23 * V_24 )
{
struct V_3 * V_4 = V_24 -> V_4 ;
V_24 -> V_27 . V_35 . V_37 = 0 ;
V_24 -> V_27 . V_35 . V_38 |= V_75 ;
V_4 -> V_67 ( V_24 , 1 ) ;
V_24 -> V_27 . V_35 . V_38 &= ~ V_75 ;
if ( ! V_24 -> V_47 ) {
F_6 ( 0x10 , L_11 ) ;
V_4 -> V_67 ( V_24 , 1 ) ;
return;
}
if ( V_24 -> V_36 == V_76 ) {
F_41 ( V_24 -> V_47 , V_24 -> V_54 ) ;
V_24 -> V_54 = 0 ;
}
}
static inline void F_42 ( struct V_23 * V_24 )
{
struct V_45 * V_46 ;
V_46 = V_24 -> V_47 ;
if ( ! V_46 )
return;
if ( V_46 -> V_50 ) {
F_27 ( V_24 ) ;
return;
}
V_24 -> V_54 = 0 ;
V_24 -> V_47 = NULL ;
F_26 ( V_24 , V_73 | V_77 , ( void * ) ( unsigned long ) V_46 -> V_78 ) ;
F_43 ( V_46 ) ;
}
static void F_44 ( struct V_23 * V_24 , T_1 V_64 )
{
F_6 ( 0x10 , L_12 , V_24 -> V_26 , V_64 ) ;
if ( V_64 & V_34 ) {
F_6 ( 0x10 , L_13 ) ;
F_35 ( V_24 , V_64 ) ;
}
if ( V_64 & V_79 ) {
F_6 ( 0x10 , L_14 ) ;
F_40 ( V_24 ) ;
F_42 ( V_24 ) ;
return;
}
if ( V_64 & V_80 ) {
F_6 ( 0x10 , L_15 ) ;
F_42 ( V_24 ) ;
}
}
static inline void F_45 ( struct V_3 * V_4 )
{
int V_19 ;
T_1 V_64 ;
for ( V_19 = 0 ; V_19 < 2 ; V_19 ++ ) {
V_64 = V_4 -> V_81 ( V_4 , V_19 ) ;
F_6 ( 0x10 , L_16 , 'A' + V_19 , V_64 ) ;
if ( V_64 & V_82 )
F_44 ( & V_4 -> V_24 [ V_19 ] , V_64 ) ;
}
}
static void F_46 ( struct V_23 * V_24 , int V_36 )
{
struct V_3 * V_4 = V_24 -> V_4 ;
F_6 ( 0x40 , L_17 ,
'A' + V_24 -> V_26 , V_24 -> V_36 , V_36 ) ;
if ( V_24 -> V_36 == V_36 )
return;
V_24 -> V_52 = 32 ;
V_24 -> V_27 . V_27 = 0 ;
V_24 -> V_27 . V_35 . V_38 = V_75 | V_66 ;
switch ( V_36 ) {
case V_83 :
V_24 -> V_27 . V_35 . V_36 = V_84 ;
V_4 -> V_67 ( V_24 , 5 ) ;
break;
case V_53 :
case V_76 :
V_24 -> V_61 = 0 ;
V_24 -> V_54 = 0 ;
V_24 -> V_47 = NULL ;
if ( V_36 == V_53 ) {
V_24 -> V_27 . V_35 . V_36 = V_84 ;
} else {
V_24 -> V_27 . V_35 . V_36 = V_85 ;
}
V_4 -> V_67 ( V_24 , 5 ) ;
V_24 -> V_27 . V_35 . V_38 = V_75 ;
V_4 -> V_67 ( V_24 , 1 ) ;
V_24 -> V_27 . V_35 . V_38 = 0 ;
break;
}
V_24 -> V_36 = V_36 ;
}
static void F_47 ( struct V_41 * V_42 , int V_39 , void * V_40 )
{
struct V_23 * V_24 = V_42 -> V_5 ;
struct V_45 * V_46 = V_40 ;
int V_36 ;
F_6 ( 0x10 , L_3 , V_39 ) ;
switch ( V_39 ) {
case V_73 | V_86 :
F_28 ( V_24 -> V_47 ) ;
V_24 -> V_47 = V_46 ;
F_39 ( 1 , V_46 ) ;
F_27 ( V_24 ) ;
break;
case V_87 | V_86 :
V_36 = ( long ) V_40 ;
F_6 ( 4 , L_18 , V_24 -> V_26 + 1 , V_36 ) ;
F_46 ( V_24 , V_36 ) ;
F_26 ( V_24 , V_87 | V_74 , NULL ) ;
break;
case V_88 | V_86 :
F_6 ( 4 , L_19 , V_24 -> V_26 + 1 ) ;
F_46 ( V_24 , V_83 ) ;
F_26 ( V_24 , V_88 | V_74 , NULL ) ;
break;
}
}
static T_2
F_48 ( int V_89 , void * V_90 )
{
struct V_3 * V_4 = V_90 ;
unsigned char V_9 ;
V_9 = F_4 ( V_4 -> V_12 + V_91 ) ;
if ( ! ( V_9 & V_92 ) )
return V_93 ;
F_6 ( 2 , L_20 , V_9 ) ;
if ( V_9 & V_94 )
F_49 ( & V_4 -> V_1 ) ;
if ( V_9 & V_95 )
F_45 ( V_4 ) ;
if ( V_9 & V_94 )
F_49 ( & V_4 -> V_1 ) ;
return V_96 ;
}
static T_2
F_50 ( int V_89 , void * V_90 )
{
struct V_3 * V_4 = V_90 ;
unsigned char V_97 ;
V_97 = F_4 ( V_4 -> V_12 + 2 ) ;
if ( ( V_97 & V_92 ) == V_92 )
return V_93 ;
F_6 ( 2 , L_21 , V_97 ) ;
if ( ! ( V_97 & V_94 ) )
F_51 ( & V_4 -> V_1 ) ;
if ( ! ( V_97 & V_95 ) )
F_45 ( V_4 ) ;
return V_96 ;
}
static inline void F_52 ( struct V_3 * V_4 )
{
F_3 ( V_98 , V_4 -> V_12 + V_91 ) ;
F_3 ( V_99 , V_4 -> V_12 + V_91 ) ;
}
static inline void F_53 ( struct V_3 * V_4 )
{
F_3 ( V_100 | V_98 |
V_99 , V_4 -> V_12 + V_91 ) ;
F_3 ( V_101 | V_4 -> V_102 ,
V_4 -> V_12 + V_103 ) ;
F_54 ( 10 ) ;
}
static int F_55 ( struct V_3 * V_4 )
{
T_1 V_9 = 0 ;
int V_104 ;
F_6 ( 1 , L_22 ) ;
F_56 ( & V_4 -> V_1 ) ;
V_104 = - V_105 ;
if ( ! F_57 ( V_4 -> V_12 , 32 , L_23 ) )
goto V_106;
switch ( V_4 -> type ) {
case V_57 :
case V_55 :
V_9 = F_14 ( V_4 -> V_12 ) ;
break;
case V_60 :
V_9 = F_4 ( V_4 -> V_12 ) ;
V_9 |= F_4 ( V_4 -> V_12 + 1 ) << 8 ;
break;
}
F_6 ( 1 , L_24 ,
V_9 , V_9 & 0xff , ( V_9 >> 8 ) & 0xff ) ;
F_58 ( & V_4 -> V_11 ) ;
V_4 -> V_1 . V_5 = V_4 ;
switch ( V_4 -> type ) {
case V_57 :
V_4 -> V_1 . V_107 = & F_17 ;
V_4 -> V_1 . V_108 = & F_18 ;
V_4 -> V_1 . V_109 = & F_19 ;
V_4 -> V_1 . V_110 = & F_20 ;
V_4 -> V_81 = & F_21 ;
V_4 -> V_67 = & F_22 ;
break;
case V_55 :
V_4 -> V_1 . V_107 = & F_1 ;
V_4 -> V_1 . V_108 = & F_7 ;
V_4 -> V_1 . V_109 = & F_8 ;
V_4 -> V_1 . V_110 = & F_10 ;
V_4 -> V_81 = & F_12 ;
V_4 -> V_67 = & F_16 ;
break;
case V_60 :
V_4 -> V_1 . V_107 = & F_1 ;
V_4 -> V_1 . V_108 = & F_7 ;
V_4 -> V_1 . V_109 = & F_8 ;
V_4 -> V_1 . V_110 = & F_10 ;
V_4 -> V_81 = & F_23 ;
V_4 -> V_67 = & F_25 ;
break;
}
F_3 ( 0 , V_4 -> V_12 + V_91 ) ;
F_54 ( 10 ) ;
F_3 ( V_111 , V_4 -> V_12 + V_91 ) ;
F_54 ( 10 ) ;
F_3 ( 0 , V_4 -> V_12 + V_91 ) ;
F_54 ( 10 ) ;
switch ( V_4 -> type ) {
case V_57 :
V_104 = F_59 ( V_4 -> V_102 , F_48 , V_112 ,
L_23 , V_4 ) ;
break;
case V_55 :
V_104 = F_59 ( V_4 -> V_102 , F_50 , V_112 ,
L_23 , V_4 ) ;
break;
case V_60 :
V_104 = F_59 ( V_4 -> V_102 , F_50 , 0 ,
L_23 , V_4 ) ;
break;
}
if ( V_104 )
goto V_113;
switch ( V_4 -> type ) {
case V_57 :
F_52 ( V_4 ) ;
F_60 ( & V_4 -> V_1 ) ;
break;
case V_55 :
case V_60 :
F_53 ( V_4 ) ;
F_61 ( & V_4 -> V_1 ) ;
break;
}
V_9 = V_4 -> V_81 ( V_4 , 0 ) ;
F_6 ( 0x20 , L_25 , V_9 ) ;
V_9 = V_4 -> V_81 ( V_4 , 1 ) ;
F_6 ( 0x20 , L_26 , V_9 ) ;
V_4 -> V_24 [ 0 ] . V_36 = - 1 ;
V_4 -> V_24 [ 1 ] . V_36 = - 1 ;
F_46 ( & V_4 -> V_24 [ 0 ] , V_83 ) ;
F_46 ( & V_4 -> V_24 [ 1 ] , V_83 ) ;
return 0 ;
V_113:
F_62 ( V_4 -> V_12 , 32 ) ;
V_106:
return V_104 ;
}
static void F_63 ( struct V_3 * V_4 )
{
F_6 ( 1 , L_22 ) ;
F_3 ( 0 , V_4 -> V_12 + V_91 ) ;
F_64 ( V_4 -> V_102 , V_4 ) ;
F_62 ( V_4 -> V_12 , 32 ) ;
}
static struct V_3 * F_65 ( void )
{
struct V_3 * V_4 ;
struct V_114 * V_43 [ 2 ] ;
int V_31 ;
V_4 = F_66 ( sizeof( struct V_3 ) , V_115 ) ;
if ( ! V_4 )
return NULL ;
V_4 -> V_1 . V_116 . V_117 = V_118 ;
V_4 -> V_1 . V_116 . V_42 . V_5 = & V_4 -> V_1 ;
V_4 -> V_1 . V_116 . V_42 . V_119 = V_120 ;
for ( V_31 = 0 ; V_31 < 2 ; V_31 ++ ) {
V_4 -> V_24 [ V_31 ] . V_4 = V_4 ;
V_4 -> V_24 [ V_31 ] . V_26 = V_31 ;
V_4 -> V_24 [ V_31 ] . V_43 . V_42 . V_5 = & V_4 -> V_24 [ V_31 ] ;
V_4 -> V_24 [ V_31 ] . V_43 . V_42 . V_119 = F_47 ;
}
for ( V_31 = 0 ; V_31 < 2 ; V_31 ++ )
V_43 [ V_31 ] = & V_4 -> V_24 [ V_31 ] . V_43 ;
if ( F_67 ( & V_4 -> V_1 . V_116 , V_43 , L_23 ,
V_121 ) != 0 ) {
F_68 ( V_4 ) ;
V_4 = NULL ;
}
return V_4 ;
}
static void F_69 ( struct V_3 * V_4 )
{
F_70 ( & V_4 -> V_1 . V_116 ) ;
F_68 ( V_4 ) ;
}
static int F_71 ( struct V_122 * V_123 , const struct V_124 * V_125 )
{
struct V_3 * V_4 ;
int V_104 ;
V_104 = - V_126 ;
V_4 = F_65 () ;
if ( ! V_4 )
goto V_106;
F_72 ( V_123 , V_4 ) ;
if ( V_123 -> V_127 == V_128 )
V_4 -> type = V_57 ;
else
V_4 -> type = V_55 ;
V_104 = F_73 ( V_123 ) ;
if ( V_104 )
goto V_129;
V_4 -> V_12 = F_74 ( V_123 , 1 ) ;
V_4 -> V_102 = V_123 -> V_102 ;
F_37 ( V_130 L_27 ,
( char * ) V_125 -> V_131 , F_75 ( V_123 ) ) ;
V_104 = F_55 ( V_4 ) ;
if ( V_104 )
goto V_129;
return 0 ;
V_129:
F_69 ( V_4 ) ;
V_106:
return V_104 ;
}
static int F_76 ( struct V_132 * V_123 , const struct V_133 * V_134 )
{
struct V_3 * V_4 ;
int V_104 ;
if ( ! V_123 )
return ( - V_135 ) ;
V_104 = - V_126 ;
V_4 = F_65 () ;
if ( ! V_4 )
goto V_106;
F_77 ( V_123 , V_4 ) ;
V_4 -> type = V_60 ;
F_78 ( V_123 ) ;
V_104 = F_79 ( V_123 ) ;
if ( V_104 < 0 ) {
F_37 ( V_72 L_28 , V_136 ,
( char * ) V_134 -> V_131 , V_104 ) ;
goto V_129;
}
V_4 -> V_12 = F_80 ( V_123 , 0 ) ;
V_4 -> V_102 = F_81 ( V_123 , 0 ) ;
F_37 ( V_130 L_29 ,
( char * ) V_134 -> V_131 , V_4 -> V_12 , V_4 -> V_102 ) ;
V_104 = F_55 ( V_4 ) ;
if ( V_104 )
goto V_129;
return 0 ;
V_129:
F_69 ( V_4 ) ;
V_106:
return V_104 ;
}
static void F_82 ( struct V_132 * V_123 )
{
struct V_3 * V_4 = F_83 ( V_123 ) ;
if ( V_4 ) {
F_63 ( V_4 ) ;
F_69 ( V_4 ) ;
}
F_78 ( V_123 ) ;
}
static void F_84 ( struct V_122 * V_123 )
{
struct V_3 * V_4 = F_85 ( V_123 ) ;
F_63 ( V_4 ) ;
F_86 ( V_123 ) ;
F_69 ( V_4 ) ;
}
static int T_3 F_87 ( void )
{
int V_104 ;
F_37 ( V_130 L_30 ) ;
V_104 = F_88 ( & V_137 ) ;
if ( V_104 )
return V_104 ;
#ifdef F_89
V_104 = F_90 ( & V_138 ) ;
if ( V_104 < 0 ) {
F_91 ( & V_137 ) ;
return V_104 ;
}
#endif
return 0 ;
}
static void T_4 F_92 ( void )
{
#ifdef F_89
F_93 ( & V_138 ) ;
#endif
F_91 ( & V_137 ) ;
}
