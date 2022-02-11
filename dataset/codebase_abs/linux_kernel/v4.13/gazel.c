static inline T_1
F_1 ( unsigned int V_1 , T_2 V_2 )
{
return F_2 ( V_1 + V_2 ) ;
}
static inline void
F_3 ( unsigned int V_1 , T_2 V_2 , T_1 V_3 )
{
F_4 ( V_1 + V_2 , V_3 ) ;
}
static inline void
F_5 ( unsigned int V_1 , T_1 * V_3 , int V_4 )
{
F_6 ( V_1 , V_3 , V_4 ) ;
}
static void
F_7 ( unsigned int V_1 , T_1 * V_3 , int V_4 )
{
F_8 ( V_1 , V_3 , V_4 ) ;
}
static inline T_1
F_9 ( unsigned int V_1 , T_2 V_2 )
{
register T_1 V_5 ;
F_4 ( V_1 , V_2 ) ;
V_5 = F_2 ( V_1 + 4 ) ;
return V_5 ;
}
static inline void
F_10 ( unsigned int V_1 , T_2 V_2 , T_1 V_3 )
{
F_4 ( V_1 , V_2 ) ;
F_4 ( V_1 + 4 , V_3 ) ;
}
static inline void
F_11 ( unsigned int V_1 , T_2 V_2 , T_1 * V_3 , int V_4 )
{
F_4 ( V_1 , V_2 ) ;
F_6 ( V_1 + 4 , V_3 , V_4 ) ;
}
static void
F_12 ( unsigned int V_1 , T_2 V_2 , T_1 * V_3 , int V_4 )
{
F_4 ( V_1 , V_2 ) ;
F_8 ( V_1 + 4 , V_3 , V_4 ) ;
}
static T_1
F_13 ( struct V_6 * V_7 , T_1 V_8 )
{
T_2 V_9 = V_8 ;
switch ( V_7 -> V_10 ) {
case V_11 :
V_9 = ( ( V_9 << 8 & 0xf000 ) | ( V_9 & 0xf ) ) ;
case V_12 :
return ( F_1 ( V_7 -> V_13 . V_14 . V_15 , V_9 ) ) ;
case V_16 :
case V_17 :
return ( F_9 ( V_7 -> V_13 . V_14 . V_18 , 0x80 + V_9 ) ) ;
}
return 0 ;
}
static void
F_14 ( struct V_6 * V_7 , T_1 V_8 , T_1 V_19 )
{
T_2 V_9 = V_8 ;
switch ( V_7 -> V_10 ) {
case V_11 :
V_9 = ( ( V_9 << 8 & 0xf000 ) | ( V_9 & 0xf ) ) ;
case V_12 :
F_3 ( V_7 -> V_13 . V_14 . V_15 , V_9 , V_19 ) ;
break;
case V_16 :
case V_17 :
F_10 ( V_7 -> V_13 . V_14 . V_18 , 0x80 + V_9 , V_19 ) ;
break;
}
}
static void
F_15 ( struct V_6 * V_7 , T_1 * V_3 , int V_4 )
{
switch ( V_7 -> V_10 ) {
case V_11 :
case V_12 :
F_5 ( V_7 -> V_13 . V_14 . V_20 , V_3 , V_4 ) ;
break;
case V_16 :
case V_17 :
F_11 ( V_7 -> V_13 . V_14 . V_18 , 0x80 , V_3 , V_4 ) ;
break;
}
}
static void
F_16 ( struct V_6 * V_7 , T_1 * V_3 , int V_4 )
{
switch ( V_7 -> V_10 ) {
case V_11 :
case V_12 :
F_7 ( V_7 -> V_13 . V_14 . V_20 , V_3 , V_4 ) ;
break;
case V_16 :
case V_17 :
F_12 ( V_7 -> V_13 . V_14 . V_18 , 0x80 , V_3 , V_4 ) ;
break;
}
}
static void
F_17 ( struct V_6 * V_7 , int V_21 , T_1 * V_3 , int V_4 )
{
switch ( V_7 -> V_10 ) {
case V_11 :
case V_12 :
F_5 ( V_7 -> V_13 . V_14 . V_22 [ V_21 ] , V_3 , V_4 ) ;
break;
case V_16 :
case V_17 :
F_11 ( V_7 -> V_13 . V_14 . V_18 , V_21 * 0x40 , V_3 , V_4 ) ;
break;
}
}
static void
F_18 ( struct V_6 * V_7 , int V_21 , T_1 * V_3 , int V_4 )
{
switch ( V_7 -> V_10 ) {
case V_11 :
case V_12 :
F_7 ( V_7 -> V_13 . V_14 . V_22 [ V_21 ] , V_3 , V_4 ) ;
break;
case V_16 :
case V_17 :
F_12 ( V_7 -> V_13 . V_14 . V_18 , V_21 * 0x40 , V_3 , V_4 ) ;
break;
}
}
static T_1
F_19 ( struct V_6 * V_7 , int V_21 , T_1 V_8 )
{
T_2 V_9 = V_8 ;
switch ( V_7 -> V_10 ) {
case V_11 :
V_9 = ( ( V_9 << 8 & 0xf000 ) | ( V_9 & 0xf ) ) ;
case V_12 :
return ( F_1 ( V_7 -> V_13 . V_14 . V_21 [ V_21 ] , V_9 ) ) ;
case V_16 :
case V_17 :
return ( F_9 ( V_7 -> V_13 . V_14 . V_18 , V_21 * 0x40 + V_9 ) ) ;
}
return 0 ;
}
static void
F_20 ( struct V_6 * V_7 , int V_21 , T_1 V_8 , T_1 V_19 )
{
T_2 V_9 = V_8 ;
switch ( V_7 -> V_10 ) {
case V_11 :
V_9 = ( ( V_9 << 8 & 0xf000 ) | ( V_9 & 0xf ) ) ;
case V_12 :
F_3 ( V_7 -> V_13 . V_14 . V_21 [ V_21 ] , V_9 , V_19 ) ;
break;
case V_16 :
case V_17 :
F_10 ( V_7 -> V_13 . V_14 . V_18 , V_21 * 0x40 + V_9 , V_19 ) ;
break;
}
}
static T_3
F_21 ( int V_23 , void * V_24 )
{
#define F_22 5
struct V_6 * V_7 = V_24 ;
T_1 V_25 , V_26 ;
int V_27 = 0 ;
T_4 V_28 ;
F_23 ( & V_7 -> V_29 , V_28 ) ;
do {
V_26 = F_19 ( V_7 , 1 , V_30 ) ;
if ( V_26 )
F_24 ( V_7 , V_26 ) ;
V_25 = F_13 ( V_7 , V_31 ) ;
if ( V_25 )
F_25 ( V_7 , V_25 ) ;
V_27 ++ ;
} while ( ( V_26 || V_25 ) && ( V_27 < F_22 ) );
F_20 ( V_7 , 0 , V_32 , 0xFF ) ;
F_20 ( V_7 , 1 , V_32 , 0xFF ) ;
F_14 ( V_7 , V_33 , 0xFF ) ;
F_14 ( V_7 , V_33 , 0x0 ) ;
F_20 ( V_7 , 0 , V_32 , 0x0 ) ;
F_20 ( V_7 , 1 , V_32 , 0x0 ) ;
F_26 ( & V_7 -> V_29 , V_28 ) ;
return V_34 ;
}
static T_3
F_27 ( int V_23 , void * V_24 )
{
struct V_6 * V_7 = V_24 ;
T_1 V_35 , V_36 ;
int V_27 = 0 ;
T_4 V_28 ;
F_23 ( & V_7 -> V_29 , V_28 ) ;
V_35 = F_13 ( V_7 , V_37 - 0x80 ) ;
do {
if ( V_35 & 0x0f ) {
V_36 = F_19 ( V_7 , 1 , V_30 ) ;
if ( V_35 & 0x01 )
V_36 |= 0x01 ;
if ( V_35 & 0x04 )
V_36 |= 0x02 ;
if ( V_35 & 0x08 )
V_36 |= 0x04 ;
if ( V_36 ) {
F_24 ( V_7 , V_36 ) ;
}
}
if ( V_35 & 0x20 ) {
V_36 = 0xfe & F_13 ( V_7 , V_31 ) ;
if ( V_36 ) {
F_25 ( V_7 , V_36 ) ;
}
}
if ( V_35 & 0x10 ) {
V_36 = 0x01 ;
F_25 ( V_7 , V_36 ) ;
}
V_35 = F_13 ( V_7 , V_37 - 0x80 ) ;
V_27 ++ ;
}
while ( ( V_35 & 0x3f ) && ( V_27 < F_22 ) );
F_14 ( V_7 , V_38 - 0x80 , 0xFF ) ;
F_14 ( V_7 , V_38 - 0x80 , 0xC0 ) ;
F_26 ( & V_7 -> V_29 , V_28 ) ;
return V_34 ;
}
static void
F_28 ( struct V_6 * V_7 )
{
unsigned int V_39 ;
switch ( V_7 -> V_10 ) {
case V_11 :
for ( V_39 = 0x0000 ; V_39 < 0xC000 ; V_39 += 0x1000 )
F_29 ( V_39 + V_7 -> V_13 . V_14 . V_21 [ 0 ] , 16 ) ;
F_29 ( 0xC000 + V_7 -> V_13 . V_14 . V_21 [ 0 ] , 1 ) ;
break;
case V_12 :
F_29 ( V_7 -> V_13 . V_14 . V_21 [ 0 ] , 0x100 ) ;
F_29 ( V_7 -> V_13 . V_14 . V_40 , 0x80 ) ;
break;
case V_16 :
F_29 ( V_7 -> V_13 . V_14 . V_18 , 0x8 ) ;
F_29 ( V_7 -> V_13 . V_14 . V_40 , 0x80 ) ;
break;
case V_17 :
F_29 ( V_7 -> V_13 . V_14 . V_18 , 8 ) ;
break;
}
}
static int
F_30 ( struct V_6 * V_7 )
{
unsigned long V_41 , V_42 = V_7 -> V_13 . V_14 . V_40 ;
switch ( V_7 -> V_10 ) {
case V_11 :
F_3 ( V_42 , 0 , 0 ) ;
F_31 ( 10 ) ;
F_3 ( V_42 , 0 , 1 ) ;
F_31 ( 2 ) ;
break;
case V_12 :
V_41 = F_32 ( V_42 + V_43 ) ;
V_41 |= ( V_44 + V_45 ) ;
F_33 ( V_41 , V_42 + V_43 ) ;
V_41 &= ~ ( V_44 + V_45 ) ;
F_31 ( 4 ) ;
F_33 ( V_41 , V_42 + V_43 ) ;
F_31 ( 10 ) ;
F_34 ( V_46 + V_47 + V_48 , V_42 + V_49 ) ;
break;
case V_16 :
V_41 = F_32 ( V_42 + V_43 ) ;
V_41 |= ( V_44 + V_45 ) ;
F_33 ( V_41 , V_42 + V_43 ) ;
V_41 &= ~ ( V_44 + V_45 ) ;
F_14 ( V_7 , V_50 - 0x80 , 0x20 ) ;
F_31 ( 4 ) ;
F_33 ( V_41 , V_42 + V_43 ) ;
F_31 ( 10 ) ;
F_14 ( V_7 , V_50 - 0x80 , 0x00 ) ;
F_14 ( V_7 , V_51 - 0x80 , 0xff ) ;
F_14 ( V_7 , V_52 - 0x80 , 0x0 ) ;
F_14 ( V_7 , V_38 - 0x80 , 0xff ) ;
F_14 ( V_7 , V_53 - 0x80 , 0x1 ) ;
F_34 ( V_54 + V_48 , V_42 + V_49 ) ;
F_14 ( V_7 , V_38 - 0x80 , 0xc0 ) ;
break;
case V_17 :
F_14 ( V_7 , V_50 - 0x80 , 0x20 ) ;
F_31 ( 4 ) ;
F_14 ( V_7 , V_50 - 0x80 , 0x00 ) ;
F_14 ( V_7 , V_51 - 0x80 , 0xff ) ;
F_14 ( V_7 , V_52 - 0x80 , 0x0 ) ;
F_14 ( V_7 , V_38 - 0x80 , 0xff ) ;
F_14 ( V_7 , V_53 - 0x80 , 0x1 ) ;
F_14 ( V_7 , V_38 - 0x80 , 0xc0 ) ;
break;
}
return ( 0 ) ;
}
static int
F_35 ( struct V_6 * V_7 , int V_55 , void * V_56 )
{
T_4 V_28 ;
switch ( V_55 ) {
case V_57 :
F_23 ( & V_7 -> V_29 , V_28 ) ;
F_30 ( V_7 ) ;
F_26 ( & V_7 -> V_29 , V_28 ) ;
return ( 0 ) ;
case V_58 :
F_28 ( V_7 ) ;
return ( 0 ) ;
case V_59 :
F_23 ( & V_7 -> V_29 , V_28 ) ;
F_36 ( V_7 , 1 ) ;
if ( ( V_7 -> V_10 == V_11 ) || ( V_7 -> V_10 == V_12 ) ) {
int V_39 ;
for ( V_39 = 0 ; V_39 < ( 2 + V_60 ) ; V_39 ++ ) {
V_7 -> V_61 [ V_39 ] . V_13 . V_21 . V_62 = 0x1f ;
V_7 -> V_61 [ V_39 ] . V_13 . V_21 . V_63 = 0x23 ;
}
}
F_26 ( & V_7 -> V_29 , V_28 ) ;
return ( 0 ) ;
case V_64 :
return ( 0 ) ;
}
return ( 0 ) ;
}
static int
F_37 ( struct V_65 * V_66 , struct V_6 * V_7 )
{
unsigned int V_39 , V_67 , V_68 = 0 , V_1 = 0 , V_69 = 0 ;
switch ( V_7 -> V_10 ) {
case V_11 :
V_68 = V_7 -> V_13 . V_14 . V_21 [ 0 ] ;
if ( ! F_38 ( V_1 = ( 0xC000 + V_68 ) , V_69 = 1 , L_1 ) )
goto error;
for ( V_39 = 0x0000 ; V_39 < 0xC000 ; V_39 += 0x1000 ) {
if ( ! F_38 ( V_1 = ( V_39 + V_68 ) , V_69 = 16 , L_1 ) )
goto error;
}
if ( V_39 != 0xC000 ) {
for ( V_67 = 0 ; V_67 < V_39 ; V_67 += 0x1000 )
F_29 ( V_67 + V_68 , 16 ) ;
F_29 ( 0xC000 + V_68 , 1 ) ;
goto error;
}
break;
case V_12 :
if ( ! F_38 ( V_1 = V_7 -> V_13 . V_14 . V_21 [ 0 ] , V_69 = 0x100 , L_1 ) )
goto error;
if ( ! F_38 ( V_1 = V_7 -> V_13 . V_14 . V_40 , V_69 = 0x80 , L_1 ) ) {
F_29 ( V_7 -> V_13 . V_14 . V_21 [ 0 ] , 0x100 ) ;
goto error;
}
break;
case V_16 :
if ( ! F_38 ( V_1 = V_7 -> V_13 . V_14 . V_18 , V_69 = 0x8 , L_1 ) )
goto error;
if ( ! F_38 ( V_1 = V_7 -> V_13 . V_14 . V_40 , V_69 = 0x80 , L_1 ) ) {
F_29 ( V_7 -> V_13 . V_14 . V_18 , 8 ) ;
goto error;
}
break;
case V_17 :
if ( ! F_38 ( V_1 = V_7 -> V_13 . V_14 . V_18 , V_69 = 0x8 , L_1 ) )
goto error;
break;
}
return 0 ;
error:
F_39 ( V_70 L_2 ,
V_1 , V_1 + V_69 ) ;
return 1 ;
}
static int F_40 ( struct V_65 * V_66 , struct V_6 * V_7 )
{
F_39 ( V_71 L_3 ) ;
if ( F_9 ( V_66 -> V_72 [ 1 ] , V_73 ) == 1 )
V_7 -> V_10 = V_17 ;
else
V_7 -> V_10 = V_11 ;
F_41 ( V_7 ) ;
V_7 -> V_13 . V_14 . V_40 = V_66 -> V_72 [ 1 ] + 0xC000 ;
V_7 -> V_13 . V_14 . V_18 = V_66 -> V_72 [ 1 ] ;
V_7 -> V_13 . V_14 . V_15 = V_66 -> V_72 [ 1 ] + 0x8000 ;
V_7 -> V_13 . V_14 . V_21 [ 0 ] = V_66 -> V_72 [ 1 ] ;
V_7 -> V_13 . V_14 . V_21 [ 1 ] = V_66 -> V_72 [ 1 ] + 0x4000 ;
V_7 -> V_74 = V_66 -> V_72 [ 0 ] ;
V_7 -> V_13 . V_14 . V_20 = V_7 -> V_13 . V_14 . V_15 ;
V_7 -> V_13 . V_14 . V_22 [ 0 ] = V_7 -> V_13 . V_14 . V_21 [ 0 ] ;
V_7 -> V_13 . V_14 . V_22 [ 1 ] = V_7 -> V_13 . V_14 . V_21 [ 1 ] ;
switch ( V_7 -> V_10 ) {
case V_11 :
F_39 ( V_71 L_4 ) ;
V_7 -> V_75 . V_15 . V_76 = 0x87 ;
F_39 ( V_71
L_5 ,
V_7 -> V_74 , V_7 -> V_13 . V_14 . V_15 , V_7 -> V_13 . V_14 . V_40 ) ;
F_39 ( V_71
L_6 ,
V_7 -> V_13 . V_14 . V_21 [ 0 ] , V_7 -> V_13 . V_14 . V_21 [ 1 ] ) ;
break;
case V_17 :
F_39 ( V_71 L_7 ) ;
F_42 ( V_77 , & V_7 -> V_78 ) ;
F_39 ( V_71
L_8 ,
V_7 -> V_74 , V_7 -> V_13 . V_14 . V_18 ) ;
break;
}
return ( 0 ) ;
}
static int F_43 ( struct V_6 * V_7 )
{
T_5 V_79 = 0 , V_80 = 0 ;
T_1 V_81 = 0 , V_82 ;
T_5 V_83 , V_84 ;
F_39 ( V_70 L_9 ) ;
V_82 = 0 ;
V_84 = V_85 ;
for ( V_83 = 0 ; V_83 < 4 ; V_83 ++ ) {
if ( ( V_86 = F_44 ( V_87 ,
V_84 , V_86 ) ) ) {
if ( F_45 ( V_86 ) )
return 1 ;
V_81 = V_86 -> V_74 ;
V_79 = F_46 ( V_86 , 1 ) ;
V_80 = F_46 ( V_86 , 2 ) ;
V_82 = 1 ;
}
if ( V_82 )
break;
else {
switch ( V_84 ) {
case V_85 :
V_84 = V_88 ;
break;
case V_88 :
V_84 = V_89 ;
break;
case V_89 :
V_84 = V_90 ;
break;
}
}
}
if ( ! V_82 ) {
F_39 ( V_70 L_10 ) ;
return ( 1 ) ;
}
if ( ! V_81 ) {
F_39 ( V_70 L_11 ) ;
return 1 ;
}
V_7 -> V_13 . V_14 . V_91 [ 0 ] = V_79 ;
V_7 -> V_13 . V_14 . V_91 [ 1 ] = V_80 ;
F_41 ( V_7 ) ;
V_80 &= 0xfffe ;
V_7 -> V_13 . V_14 . V_40 = V_79 & 0xfffe ;
V_7 -> V_13 . V_14 . V_18 = V_80 ;
V_7 -> V_13 . V_14 . V_15 = V_80 + 0x80 ;
V_7 -> V_13 . V_14 . V_21 [ 0 ] = V_80 ;
V_7 -> V_13 . V_14 . V_21 [ 1 ] = V_80 + 0x40 ;
V_7 -> V_13 . V_14 . V_20 = V_7 -> V_13 . V_14 . V_15 ;
V_7 -> V_13 . V_14 . V_22 [ 0 ] = V_7 -> V_13 . V_14 . V_21 [ 0 ] ;
V_7 -> V_13 . V_14 . V_22 [ 1 ] = V_7 -> V_13 . V_14 . V_21 [ 1 ] ;
V_7 -> V_74 = V_81 ;
V_7 -> V_92 |= V_93 ;
switch ( V_84 ) {
case V_85 :
F_39 ( V_71 L_12 ) ;
V_7 -> V_10 = V_12 ;
V_7 -> V_75 . V_15 . V_76 = 0x87 ;
F_39 ( V_71
L_5 ,
V_7 -> V_74 , V_7 -> V_13 . V_14 . V_15 , V_7 -> V_13 . V_14 . V_40 ) ;
F_39 ( V_71
L_6 ,
V_7 -> V_13 . V_14 . V_21 [ 0 ] , V_7 -> V_13 . V_14 . V_21 [ 1 ] ) ;
break;
case V_88 :
case V_89 :
case V_90 :
F_39 ( V_71 L_13 ) ;
V_7 -> V_10 = V_16 ;
F_42 ( V_77 , & V_7 -> V_78 ) ;
F_39 ( V_71
L_14 ,
V_7 -> V_74 , V_7 -> V_13 . V_14 . V_18 , V_7 -> V_13 . V_14 . V_40 ) ;
break;
}
return ( 0 ) ;
}
int F_47 ( struct V_65 * V_66 )
{
struct V_6 * V_7 = V_66 -> V_7 ;
char V_94 [ 64 ] ;
T_1 V_36 ;
strcpy ( V_94 , V_95 ) ;
F_39 ( V_71 L_15 , F_48 ( V_94 ) ) ;
if ( V_7 -> V_96 != V_97 )
return ( 0 ) ;
if ( V_66 -> V_72 [ 0 ] ) {
if ( F_40 ( V_66 , V_7 ) )
return ( 0 ) ;
} else {
#ifdef F_49
if ( F_43 ( V_7 ) )
return ( 0 ) ;
#else
F_39 ( V_70 L_16 ) ;
return ( 0 ) ;
#endif
}
if ( F_37 ( V_66 , V_7 ) ) {
return ( 0 ) ;
}
if ( F_30 ( V_7 ) ) {
F_39 ( V_70 L_17 ) ;
F_28 ( V_7 ) ;
return ( 0 ) ;
}
V_7 -> V_98 = & F_13 ;
V_7 -> V_99 = & F_14 ;
V_7 -> V_100 = & F_15 ;
V_7 -> V_101 = & F_16 ;
V_7 -> V_102 = & F_19 ;
V_7 -> V_103 = & F_20 ;
V_7 -> V_104 = & V_105 ;
V_7 -> V_106 = & F_35 ;
switch ( V_7 -> V_10 ) {
case V_11 :
case V_12 :
V_7 -> V_107 = & F_21 ;
F_50 ( V_7 , L_18 ) ;
if ( F_51 ( V_7 , L_18 ) ) {
F_39 ( V_70
L_19 ) ;
F_28 ( V_7 ) ;
return ( 0 ) ;
}
break;
case V_17 :
case V_16 :
V_7 -> V_107 = & F_27 ;
V_36 = F_13 ( V_7 , V_73 - 0x80 ) ;
F_39 ( V_71 L_20 , V_36 ) ;
break;
}
return ( 1 ) ;
}
