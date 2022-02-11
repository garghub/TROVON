static inline int F_1 ( const T_1 * V_1 )
{
return F_2 ( ( V_2 * ) ( V_1 ) ) ;
}
static inline int F_3 ( const T_1 * V_1 )
{
return F_2 ( ( V_2 * ) ( V_1 + 4 ) ) ;
}
static inline int F_4 ( const T_1 * V_1 )
{
return F_2 ( ( V_2 * ) ( V_1 + 8 ) ) ;
}
static inline int F_5 ( const unsigned char * V_3 )
{
if ( 0 == memcmp ( V_3 , V_4 ,
sizeof( V_4 ) ) ||
0 == memcmp ( V_3 , V_5 ,
sizeof( V_5 ) ) )
return 1 ;
else
return 0 ;
}
static void F_6 ( struct V_6 * V_7 ,
char * V_8 , unsigned int V_9 )
{
if ( V_9 ) {
F_7 ( & V_7 -> V_10 , V_11 , V_9 , V_8 ) ;
F_8 ( & V_7 -> V_7 , V_8 , V_9 ) ;
F_9 ( & V_7 -> V_7 ) ;
}
}
static int F_10 ( struct V_12 * V_13 ,
unsigned char * V_8 , unsigned int V_14 )
{
int V_15 = 0 ;
int V_16 = 0 ;
unsigned long V_17 ;
struct V_18 * V_19 ;
if ( V_14 ) {
V_19 = F_11 ( sizeof( struct V_18 ) + V_14 ,
V_20 ) ;
if ( ! V_19 )
return 0 ;
V_19 -> V_21 = V_14 ;
memcpy ( V_19 -> V_8 , V_8 , V_14 ) ;
F_12 ( & V_13 -> V_22 , V_17 ) ;
V_13 -> V_17 |= V_23 ;
V_16 = F_13 ( & V_13 -> V_24 ) ;
V_19 -> V_25 = V_13 -> V_26 ++ ;
F_14 ( & V_19 -> V_27 , & V_13 -> V_24 ) ;
V_15 = V_13 -> V_15 ;
F_15 ( & V_13 -> V_22 , V_17 ) ;
F_16 ( & V_13 -> V_7 -> V_10 ,
L_1 , V_11 ,
V_19 -> V_25 , V_14 ) ;
if ( V_16 && ( V_15 == V_28 ) )
F_17 ( V_13 ) ;
}
return V_16 ;
}
static struct V_18 * F_18 ( struct V_12 * V_13 )
{
unsigned long V_17 ;
struct V_18 * V_16 = NULL ;
F_12 ( & V_13 -> V_22 , V_17 ) ;
if ( ! F_13 ( & V_13 -> V_24 ) ) {
V_16 = (struct V_18 * ) V_13 -> V_24 . V_29 ;
F_19 ( & V_16 -> V_27 ) ;
}
F_15 ( & V_13 -> V_22 , V_17 ) ;
return V_16 ;
}
static void F_20 ( struct V_12 * V_13 )
{
unsigned long V_17 ;
struct V_18 * V_16 = NULL ;
F_12 ( & V_13 -> V_22 , V_17 ) ;
while ( ! F_13 ( & V_13 -> V_24 ) ) {
V_16 = (struct V_18 * ) V_13 -> V_24 . V_29 ;
F_19 ( & V_16 -> V_27 ) ;
F_21 ( V_16 ) ;
}
F_15 ( & V_13 -> V_22 , V_17 ) ;
}
static int F_22 ( struct V_12 * V_13 , T_1 V_30 )
{
T_1 V_19 [ 10 ] ;
T_1 V_31 = 0 ;
T_1 * V_32 = V_19 ;
unsigned V_33 = 0 ;
F_16 ( & V_13 -> V_7 -> V_10 , L_2 , V_11 ,
0xFF & V_30 ) ;
* V_32 ++ = V_34 ;
* V_32 ++ = V_35 ;
V_31 += V_35 ;
* V_32 ++ = 2 ;
V_31 += 2 ;
* V_32 ++ = V_30 ;
V_31 += V_30 ;
if ( V_30 == V_34 )
* V_32 ++ = V_34 ;
* V_32 ++ = 0 ;
* V_32 ++ = 0xFF & ( - V_31 ) ;
* V_32 ++ = V_34 ;
* V_32 ++ = V_36 ;
V_33 = V_32 - V_19 ;
F_6 ( V_13 -> V_7 , V_19 , V_33 ) ;
return 0 ;
}
static int F_23 ( struct V_12 * V_13 , int V_37 )
{
struct V_38 * V_10 = & V_13 -> V_7 -> V_10 ;
unsigned long V_17 ;
const T_1 * V_39 = V_13 -> V_40 + V_41 ;
V_2 * V_42 = ( V_2 * ) V_13 -> V_40 ;
int V_31 = 0 ;
int V_43 = 0 ;
int V_44 = V_39 [ 0 ] ;
int V_21 = V_39 [ 1 ] ;
F_7 ( & V_13 -> V_7 -> V_10 , V_11 ,
V_37 - V_41 , V_39 ) ;
if ( V_21 != ( V_37 - V_41 - 3 ) ) {
F_16 ( V_10 , L_3 ,
V_11 , V_21 , ( V_37 - V_41 - 3 ) ) ;
return - V_45 ;
}
V_31 += * V_39 ++ ;
V_31 += * V_39 ++ ;
if ( ( T_1 * ) & ( V_42 [ 3 ] ) != V_39 ) {
F_16 ( V_10 , L_4 , V_11 ,
& ( V_42 [ 4 ] ) , V_39 ) ;
return - V_45 ;
}
while ( V_43 < V_21 ) {
V_31 += * V_39 ++ ;
V_43 ++ ;
}
if ( ( 0xff & ( V_31 + * V_39 ) ) != 0 ) {
F_16 ( V_10 , L_5 ,
V_11 , 0xff & - V_31 , 0xff & * V_39 ) ;
return - V_45 ;
}
V_42 [ 0 ] = F_24 ( V_46 ) ;
V_42 [ 1 ] = F_24 ( V_44 ) ;
V_42 [ 2 ] = F_24 ( V_21 ) ;
F_25 ( V_13 -> V_7 , V_13 -> V_40 ,
V_47 + V_21 , 0 ) ;
if ( F_5 ( V_13 -> V_40 ) ) {
F_12 ( & V_13 -> V_22 , V_17 ) ;
V_13 -> V_17 |= V_48 ;
F_15 ( & V_13 -> V_22 , V_17 ) ;
F_20 ( V_13 ) ;
}
return V_37 ;
}
static int F_26 ( struct V_12 * V_13 ,
const unsigned char * V_3 , int V_37 )
{
struct V_38 * V_10 = & V_13 -> V_7 -> V_10 ;
unsigned long V_17 ;
int V_49 = 0 ;
int V_50 = 0 ;
T_1 * V_51 ;
int V_21 ;
int V_52 ;
int V_53 ;
T_1 V_8 ;
F_12 ( & V_13 -> V_22 , V_17 ) ;
V_51 = V_13 -> V_40 ;
V_21 = V_13 -> V_54 ;
V_52 = V_13 -> V_17 & V_55 ;
V_53 = V_13 -> V_17 & V_56 ;
F_15 ( & V_13 -> V_22 , V_17 ) ;
if ( V_21 == 0 )
V_21 = V_41 ;
while ( V_49 < V_37 ) {
V_8 = * ( V_3 + V_49 ) ;
V_49 ++ ;
if ( V_8 == V_34 ) {
if ( V_53 ) {
V_53 = 0 ;
V_21 = V_41 ;
V_52 = 1 ;
} else if ( V_52 ) {
V_51 [ V_21 ++ ] = V_8 ;
V_52 = 0 ;
} else {
V_52 = 1 ;
}
} else if ( V_8 == V_36 ) {
if ( V_52 ) {
V_8 = V_51 [ V_41 ] ;
if ( V_8 == V_35 ) {
V_50 = V_35 ;
F_16 ( V_10 , L_6 ) ;
} else if ( V_8 == V_57 ) {
V_50 = V_57 ;
F_16 ( V_10 , L_7 ) ;
} else {
F_16 ( V_10 , L_8 ,
0xFF & V_8 ) ;
F_23 ( V_13 , V_21 ) ;
}
V_53 = 1 ;
V_21 = V_41 ;
V_52 = 0 ;
} else {
V_51 [ V_21 ++ ] = V_8 ;
}
} else if ( ! V_53 ) {
if ( V_52 ) {
V_21 = V_41 ;
V_52 = 0 ;
}
V_51 [ V_21 ++ ] = V_8 ;
}
if ( V_21 >= V_58 ) {
F_16 ( V_10 , L_9 , V_11 ) ;
V_53 = 1 ;
V_21 = V_41 ;
V_52 = 0 ;
}
}
F_12 ( & V_13 -> V_22 , V_17 ) ;
V_13 -> V_54 = V_21 ;
if ( V_53 )
V_13 -> V_17 |= V_56 ;
else
V_13 -> V_17 &= ~ V_56 ;
if ( V_52 )
V_13 -> V_17 |= V_55 ;
else
V_13 -> V_17 &= ~ V_55 ;
F_15 ( & V_13 -> V_22 , V_17 ) ;
if ( V_50 ) {
if ( F_17 ( V_13 ) > 0 )
V_13 -> V_15 = V_59 ;
else
V_13 -> V_15 = V_28 ;
}
return V_37 ;
}
static int F_27 ( struct V_12 * V_13 ,
const unsigned char * V_3 , int V_37 )
{
struct V_38 * V_10 = & V_13 -> V_7 -> V_10 ;
const unsigned char * V_60 ;
unsigned char * V_61 ;
int V_44 = 0 ;
int V_62 = 0 ;
int V_31 = 0 ;
int V_63 = 0 ;
int V_64 ;
F_16 ( V_10 , L_10 , V_11 ,
V_13 -> V_15 , V_37 ) ;
V_64 = V_13 -> V_65 ;
if ( ( V_64 + V_37 ) > V_66 ) {
F_16 ( V_10 , L_11 ) ;
V_13 -> V_65 = 0 ;
return - 4 ;
}
memcpy ( V_13 -> V_67 + V_64 , V_3 , V_37 ) ;
V_64 += V_37 ;
V_13 -> V_65 = V_64 ;
if ( V_64 >= V_47 ) {
V_44 = F_3 ( V_13 -> V_67 ) ;
V_62 = F_4 ( V_13 -> V_67 ) ;
V_63 = V_47 + V_62 ;
if ( V_64 < V_63 )
return 0 ;
} else {
return 0 ;
}
F_16 ( V_10 , L_12 , V_11 , V_64 , V_63 ) ;
F_7 ( & V_13 -> V_7 -> V_10 , V_11 , V_64 ,
V_13 -> V_67 ) ;
V_13 -> V_65 = 0 ;
if ( V_46 != F_1 ( V_13 -> V_67 ) ) {
F_16 ( V_10 , L_13 ,
F_1 ( V_13 -> V_67 ) ) ;
return - 1 ;
}
if ( V_44 > 255 ) {
F_16 ( V_10 , L_14 , V_44 ) ;
return - 2 ;
}
if ( V_62 > 255 ) {
F_16 ( V_10 , L_15 , V_62 ) ;
return - 3 ;
}
V_64 = 0 ;
V_60 = V_13 -> V_67 + V_47 ;
for ( V_63 = 0 ; V_63 < V_62 ; V_63 ++ ) {
if ( * V_60 ++ == V_34 )
V_64 ++ ;
}
V_60 = V_13 -> V_67 + V_47 ;
if ( V_64 > ( V_47 - 2 ) ) {
V_61 = V_13 -> V_67 + V_66 - V_62 ;
memcpy ( V_61 , V_60 , V_62 ) ;
V_60 = V_61 ;
}
V_61 = V_13 -> V_67 ;
* V_61 ++ = V_34 ;
* V_61 ++ = V_44 ;
V_31 += V_44 ;
* V_61 ++ = V_62 ;
V_31 += V_62 ;
if ( V_62 == V_34 )
* V_61 ++ = V_34 ;
for ( V_63 = 0 ; V_63 < V_62 ; V_63 ++ ) {
T_1 V_68 = * V_60 ++ ;
* V_61 ++ = V_68 ;
V_31 += V_68 ;
if ( V_68 == V_34 )
* V_61 ++ = V_34 ;
}
V_31 = 0xFF & - V_31 ;
* V_61 ++ = V_31 ;
if ( V_31 == V_34 )
* V_61 ++ = V_34 ;
* V_61 ++ = V_34 ;
* V_61 ++ = V_36 ;
V_63 = V_61 - V_13 -> V_67 ;
F_6 ( V_13 -> V_7 , V_13 -> V_67 , V_63 ) ;
V_13 -> V_30 = V_44 ;
V_13 -> V_15 = V_69 ;
return V_63 ;
}
static int F_17 ( struct V_12 * V_13 )
{
int V_16 = 0 ;
struct V_18 * V_19 = NULL ;
while ( ( V_19 = F_18 ( V_13 ) ) != NULL ) {
F_16 ( & V_13 -> V_7 -> V_10 , L_16 , V_11 , V_19 -> V_25 ) ;
V_16 = F_27 ( V_13 , V_19 -> V_8 , V_19 -> V_21 ) ;
if ( V_16 > 0 ) {
F_21 ( V_19 ) ;
return V_16 ;
}
F_21 ( V_19 ) ;
}
return V_16 ;
}
static int F_28 ( struct V_12 * V_13 ,
const unsigned char * V_3 , int V_37 )
{
unsigned long V_17 ;
T_1 * V_51 ;
int V_49 = 0 ;
int V_16 = V_37 ;
int V_70 ;
while ( V_49 < V_37 ) {
if ( V_13 -> V_54 >= V_47 )
V_70 = V_47
+ F_4 ( V_13 -> V_40 ) ;
else
V_70 = V_47 ;
if ( V_70 >= V_58 ) {
F_16 ( & V_13 -> V_7 -> V_10 ,
L_17 ,
V_11 , V_70 ) ;
V_13 -> V_54 = 0 ;
V_37 = 0 ;
V_16 = - V_45 ;
} else {
V_70 -= V_13 -> V_54 ;
if ( V_70 > ( V_37 - V_49 ) )
V_70 = ( V_37 - V_49 ) ;
if ( V_70 > 0 ) {
V_51 = V_13 -> V_40
+ V_13 -> V_54 ;
memcpy ( V_51 , V_3 + V_49 , V_70 ) ;
V_13 -> V_54 += V_70 ;
V_49 += V_70 ;
}
}
if ( V_13 -> V_54 >= V_47 ) {
V_70 = V_47 +
F_4 ( V_13 -> V_40 ) ;
if ( V_13 -> V_54 >= V_70 ) {
F_25 ( V_13 -> V_7 ,
V_13 -> V_40 ,
V_70 , 0 ) ;
V_13 -> V_54 = 0 ;
if ( F_5 ( V_13 -> V_40 ) ) {
F_12 ( & V_13 -> V_22 ,
V_17 ) ;
V_13 -> V_17 |= V_48 ;
F_15 (
& V_13 -> V_22 , V_17 ) ;
F_20 ( V_13 ) ;
}
}
}
}
return V_16 ;
}
static void F_29 ( struct V_6 * V_7 )
{
struct V_12 * V_13 = F_30 ( V_7 ) ;
V_2 * V_19 = ( V_2 * ) V_13 -> V_71 ;
V_19 [ 0 ] = F_24 ( V_72 ) ;
V_19 [ 1 ] = F_24 ( V_73 ) ;
V_19 [ 2 ] = F_24 ( 12 ) ;
V_19 [ 3 ] = F_24 ( V_74 << 16 | V_75 ) ;
V_19 [ 4 ] = F_24 ( V_13 -> V_76 ) ;
V_19 [ 5 ] = F_24 ( V_13 -> V_77 ) ;
F_6 ( V_7 , ( T_1 * ) V_19 , 6 * 4 ) ;
}
static int F_31 ( struct V_6 * V_7 )
{
unsigned long V_17 ;
int V_78 ;
struct V_12 * V_13 = F_30 ( V_7 ) ;
F_12 ( & V_13 -> V_22 , V_17 ) ;
V_13 -> V_17 &= ~ ( V_79 ) ;
V_13 -> V_15 = V_80 ;
V_13 -> V_77 = 0 ;
F_15 ( & V_13 -> V_22 , V_17 ) ;
F_32 ( V_7 -> V_81 ) ;
F_16 ( & V_7 -> V_10 , L_18 , V_11 ) ;
V_78 = F_33 ( V_7 -> V_82 -> V_10 ) ;
if ( V_78 )
F_16 ( & V_7 -> V_10 , L_19 ,
V_11 , V_78 ) ;
return V_78 ;
}
static int F_34 ( struct V_12 * V_13 )
{
unsigned long V_17 ;
int V_78 = 0 ;
F_20 ( V_13 ) ;
F_12 ( & V_13 -> V_22 , V_17 ) ;
V_13 -> V_54 = 0 ;
V_13 -> V_65 = 0 ;
F_15 ( & V_13 -> V_22 , V_17 ) ;
return V_78 ;
}
static int F_35 ( struct V_6 * V_7 )
{
struct V_83 * V_82 = V_7 -> V_82 ;
struct V_12 * V_13 = F_30 ( V_7 ) ;
int V_78 = 0 ;
int V_63 = 0 ;
if ( V_78 == 0 ) {
F_32 ( V_7 -> V_81 ) ;
F_16 ( & V_82 -> V_10 -> V_10 , L_20 , V_11 ) ;
V_78 = F_36 ( V_7 -> V_81 , V_84 ) ;
if ( V_78 )
F_37 ( & V_82 -> V_10 -> V_10 ,
L_21 ,
V_11 , V_78 ) ;
}
if ( V_78 == 0 ) {
F_16 ( & V_82 -> V_10 -> V_10 , L_22 , V_11 ) ;
V_13 -> V_15 = V_59 ;
for ( V_63 = 0 ; V_63 < 3 ; V_63 ++ ) {
V_78 = F_25 ( V_7 ,
V_85 ,
sizeof( V_85 ) , 0 ) ;
if ( V_78 < 0 )
break;
}
if ( V_78 > 0 )
V_78 = 0 ;
}
return V_78 ;
}
static int F_38 ( struct V_86 * V_87 , struct V_6 * V_7 )
{
unsigned long V_17 ;
int V_78 = 0 ;
struct V_12 * V_13 = F_30 ( V_7 ) ;
F_12 ( & V_13 -> V_22 , V_17 ) ;
V_13 -> V_76 = V_88 ;
V_13 -> V_37 = 0 ;
V_13 -> V_17 &= V_89 ;
F_15 ( & V_13 -> V_22 , V_17 ) ;
F_32 ( V_7 -> V_90 ) ;
F_32 ( V_7 -> V_91 ) ;
if ( V_13 -> V_15 == V_80 )
V_78 = F_35 ( V_7 ) ;
V_13 -> V_15 = V_59 ;
return V_78 ;
}
static void F_39 ( struct V_6 * V_7 )
{
struct V_12 * V_13 = F_30 ( V_7 ) ;
F_16 ( & V_7 -> V_10 , L_23 ,
V_11 , V_13 -> V_76 , V_13 -> V_15 ,
V_13 -> V_17 ) ;
F_34 ( V_13 ) ;
F_32 ( V_7 -> V_91 ) ;
F_32 ( V_7 -> V_90 ) ;
if ( V_13 -> V_15 != V_80 )
V_13 -> V_15 = V_92 ;
}
static void F_40 ( struct V_93 * V_93 )
{
struct V_6 * V_7 = V_93 -> V_94 ;
if ( V_7 ) {
struct V_12 * V_13 =
F_30 ( V_7 ) ;
if ( V_46 == F_1 ( V_93 -> V_95 ) ) {
if ( V_13 -> V_76 == V_96 ) {
F_22 ( V_13 ,
( ( T_1 * ) V_93 -> V_95 ) [ 4 ] ) ;
}
}
F_41 ( V_7 ) ;
}
F_21 ( V_93 -> V_95 ) ;
}
static int F_25 ( struct V_6 * V_7 ,
const unsigned char * V_3 , int V_37 ,
int V_97 )
{
unsigned long V_17 ;
struct V_83 * V_82 = V_7 -> V_82 ;
struct V_12 * V_13 = F_30 ( V_7 ) ;
struct V_93 * V_93 ;
unsigned char * V_98 ;
int V_78 ;
F_12 ( & V_13 -> V_22 , V_17 ) ;
V_13 -> V_17 &= ~ V_48 ;
F_15 ( & V_13 -> V_22 , V_17 ) ;
V_98 = F_11 ( V_37 , V_20 ) ;
if ( ! V_98 )
return - V_99 ;
V_93 = F_42 ( 0 , V_20 ) ;
if ( ! V_93 ) {
F_21 ( V_98 ) ;
return - V_99 ;
}
memcpy ( V_98 , V_3 , V_37 ) ;
F_7 ( & V_7 -> V_10 , V_11 , V_37 , V_98 ) ;
F_43 ( V_93 , V_82 -> V_10 ,
F_44 ( V_82 -> V_10 ,
V_7 -> V_100 ) ,
V_98 , V_37 ,
F_40 ,
V_97 ? NULL : V_7 ) ;
V_93 -> V_101 |= V_102 ;
if ( V_46 == F_1 ( V_98 ) ) {
F_12 ( & V_13 -> V_22 , V_17 ) ;
V_13 -> V_17 |= V_103 ;
F_15 ( & V_13 -> V_22 , V_17 ) ;
if ( V_13 -> V_76 == V_96 ) {
F_20 ( V_13 ) ;
V_13 -> V_15 = V_28 ;
}
}
V_78 = F_36 ( V_93 , V_20 ) ;
if ( V_78 ) {
F_37 ( & V_7 -> V_10 ,
L_24 ,
V_11 , V_78 ) ;
V_37 = V_78 ;
}
F_45 ( V_93 ) ;
return V_37 ;
}
static int F_46 ( struct V_86 * V_87 , struct V_6 * V_7 ,
const unsigned char * V_3 , int V_37 )
{
struct V_38 * V_10 = & V_7 -> V_10 ;
int V_44 , V_104 , V_70 ;
struct V_12 * V_13 = F_30 ( V_7 ) ;
V_2 * V_71 = ( V_2 * ) V_13 -> V_71 ;
F_7 ( V_10 , V_11 , V_37 , V_3 ) ;
if ( V_13 -> V_15 == V_80 )
return - V_105 ;
if ( V_37 >= V_47 ) {
V_70 = V_106 ;
if ( V_37 < V_70 )
V_70 = V_37 ;
memcpy ( V_13 -> V_71 , V_3 , V_70 ) ;
V_104 = F_4 ( V_13 -> V_71 ) ;
V_44 = F_3 ( V_13 -> V_71 ) ;
if ( V_37 == ( V_47 + V_104 )
&& V_72 ==
F_1 ( V_13 -> V_71 ) ) {
F_16 ( V_10 , L_25 ,
V_11 , V_44 ) ;
F_34 ( V_13 ) ;
switch ( V_44 ) {
case V_107 :
if ( V_104 != 4 )
return - V_45 ;
V_13 -> V_76 = F_47 ( V_71 [ 3 ] ) ;
F_16 ( V_10 , L_26 ,
V_11 , V_13 -> V_76 ) ;
break;
case V_108 :
F_29 ( V_7 ) ;
break;
case V_109 :
F_31 ( V_7 ) ;
break;
case V_110 :
if ( V_104 != 4 )
return - V_45 ;
V_88 = F_47 ( V_71 [ 3 ] ) ;
F_16 ( V_10 , L_27 ,
V_11 ,
V_13 -> V_76 ) ;
break;
}
return V_37 ;
}
}
if ( V_13 -> V_76 == V_96 ) {
return F_26 ( V_13 , V_3 , V_37 ) ;
} else {
return F_28 ( V_13 , V_3 , V_37 ) ;
}
}
static int F_48 ( struct V_86 * V_87 )
{
struct V_6 * V_7 = V_87 -> V_111 ;
struct V_12 * V_13 = F_30 ( V_7 ) ;
return V_66 - V_13 -> V_65 ;
}
static void F_49 ( struct V_12 * V_13 ,
unsigned char * V_8 , unsigned V_14 ,
int V_112 )
{
unsigned long V_17 ;
if ( V_13 -> V_17 & V_48 ) {
F_16 ( & V_13 -> V_7 -> V_10 , L_28 , V_11 ) ;
} else if ( V_13 -> V_15 != V_92 &&
V_13 -> V_15 != V_80 ) {
if ( V_13 -> V_17 & V_23 ) {
F_10 ( V_13 , V_8 , V_14 ) ;
} else if ( V_112 ||
F_1 ( V_8 ) == V_46 ) {
F_12 ( & V_13 -> V_22 , V_17 ) ;
V_13 -> V_17 |= V_113 ;
F_15 ( & V_13 -> V_22 , V_17 ) ;
if ( V_13 -> V_76 == V_96 ) {
F_10 ( V_13 , V_8 , V_14 ) ;
} else {
F_6 ( V_13 -> V_7 , V_8 ,
V_14 ) ;
}
}
}
}
static void F_50 ( struct V_93 * V_93 )
{
unsigned long V_17 ;
struct V_6 * V_7 = V_93 -> V_94 ;
struct V_12 * V_13 = F_30 ( V_7 ) ;
unsigned char * V_8 = V_93 -> V_95 ;
int V_78 = V_93 -> V_78 ;
int V_114 ;
if ( V_78 ) {
F_16 ( & V_93 -> V_10 -> V_10 , L_29 ,
V_11 , V_78 ) ;
return;
}
F_7 ( & V_7 -> V_10 , V_11 , V_93 -> V_9 , V_8 ) ;
F_49 ( V_13 , V_8 , V_93 -> V_9 , 1 ) ;
if ( V_93 -> V_9 == 0 &&
0 != ( V_13 -> V_17 & V_115 ) ) {
F_12 ( & V_13 -> V_22 , V_17 ) ;
V_13 -> V_17 &= ~ V_115 ;
F_15 ( & V_13 -> V_22 , V_17 ) ;
V_114 = F_36 ( V_7 -> V_91 , V_20 ) ;
if ( V_114 )
F_37 ( & V_7 -> V_10 ,
L_30 ,
V_11 , V_114 ) ;
} else if ( V_93 -> V_9 > 0 ) {
if ( 0 == ( V_13 -> V_17 & V_116 ) ) {
V_114 = F_36 ( V_7 -> V_91 , V_20 ) ;
if ( V_114 )
F_37 ( & V_7 -> V_10 ,
L_30 ,
V_11 , V_114 ) ;
}
} else {
F_16 ( & V_7 -> V_10 , L_31 , V_11 ) ;
F_12 ( & V_13 -> V_22 , V_17 ) ;
V_13 -> V_17 &= ~ V_117 ;
F_15 ( & V_13 -> V_22 , V_17 ) ;
}
}
static void F_51 ( struct V_93 * V_93 )
{
unsigned long V_17 ;
int V_114 ;
struct V_6 * V_7 = V_93 -> V_94 ;
struct V_12 * V_13 = F_30 ( V_7 ) ;
unsigned char * V_8 = V_93 -> V_95 ;
int V_78 = V_93 -> V_78 ;
switch ( V_78 ) {
case 0 :
break;
case - V_118 :
case - V_119 :
case - V_120 :
F_16 ( & V_93 -> V_10 -> V_10 , L_32 ,
V_11 , V_78 ) ;
return;
default:
F_16 ( & V_93 -> V_10 -> V_10 , L_33 ,
V_11 , V_78 ) ;
return;
}
F_7 ( & V_7 -> V_10 , V_11 , V_93 -> V_9 ,
V_93 -> V_95 ) ;
if ( V_93 -> V_9 == sizeof( V_121 ) &&
0 == memcmp ( V_8 , V_121 ,
sizeof( V_121 ) ) ) {
F_16 ( & V_7 -> V_10 , L_34 , V_11 ) ;
if ( 0 == ( V_13 -> V_17 & V_117 ) ) {
V_114 = F_36 ( V_7 -> V_91 , V_20 ) ;
if ( V_114 ) {
F_37 ( & V_7 -> V_10 ,
L_35 ,
V_11 , V_114 ) ;
} else {
F_12 ( & V_13 -> V_22 , V_17 ) ;
V_13 -> V_17 |= V_117 ;
F_15 ( & V_13 -> V_22 ,
V_17 ) ;
}
} else {
F_12 ( & V_13 -> V_22 , V_17 ) ;
V_13 -> V_17 |= V_115 ;
F_15 ( & V_13 -> V_22 , V_17 ) ;
}
} else if ( V_93 -> V_9 == ( 4 + sizeof( V_122 ) )
&& 0 == memcmp ( V_8 , V_122 ,
sizeof( V_122 ) ) ) {
F_12 ( & V_13 -> V_22 , V_17 ) ;
V_13 -> V_17 |= V_89 ;
F_15 ( & V_13 -> V_22 , V_17 ) ;
V_13 -> V_77 = F_2 (
( V_2 * ) ( V_8 + V_47 ) ) ;
F_16 ( & V_7 -> V_10 , L_36 ,
V_11 , V_13 -> V_77 ) ;
}
F_49 ( V_13 , V_8 , V_93 -> V_9 , 0 ) ;
V_114 = F_36 ( V_93 , V_20 ) ;
if ( V_114 )
F_37 ( & V_93 -> V_10 -> V_10 ,
L_37 ,
V_11 , V_114 ) ;
}
static int F_52 ( struct V_12 * V_13 )
{
unsigned long V_17 ;
struct V_18 * V_19 ;
if ( ( V_13 -> V_17 & V_116 ) == 0 ) {
V_19 = F_18 ( V_13 ) ;
if ( V_19 != NULL ) {
F_6 ( V_13 -> V_7 , V_19 -> V_8 , V_19 -> V_21 ) ;
F_21 ( V_19 ) ;
F_53 ( & V_13 -> V_123 , ( 1 ) + V_124 ) ;
} else {
F_12 ( & V_13 -> V_22 , V_17 ) ;
V_13 -> V_17 &= ~ V_23 ;
F_15 ( & V_13 -> V_22 , V_17 ) ;
}
}
return 0 ;
}
static void F_54 ( struct V_86 * V_87 )
{
struct V_6 * V_7 = V_87 -> V_111 ;
struct V_12 * V_13 = F_30 ( V_7 ) ;
F_55 ( & V_13 -> V_22 ) ;
V_13 -> V_17 |= V_23 | V_116 ;
F_56 ( & V_13 -> V_22 ) ;
}
static void F_57 ( struct V_86 * V_87 )
{
struct V_6 * V_7 = V_87 -> V_111 ;
struct V_12 * V_13 = F_30 ( V_7 ) ;
int V_78 ;
F_55 ( & V_13 -> V_22 ) ;
V_13 -> V_17 &= ~ V_116 ;
F_56 ( & V_13 -> V_22 ) ;
if ( V_13 -> V_76 == V_125 )
F_52 ( V_13 ) ;
if ( 0 != ( V_13 -> V_17 & V_117 ) ) {
V_78 = F_36 ( V_7 -> V_91 , V_84 ) ;
if ( V_78 )
F_37 ( & V_7 -> V_10 ,
L_30 ,
V_11 , V_78 ) ;
}
}
static void F_58 ( unsigned long V_8 )
{
struct V_12 * V_13 = (struct V_12 * ) V_8 ;
if ( V_13 -> V_76 == V_125 )
if ( V_13 -> V_17 & V_23 )
F_52 ( V_13 ) ;
}
static int F_59 ( struct V_6 * V_7 )
{
int V_78 ;
struct V_12 * V_13 ;
V_13 = F_60 ( sizeof( struct V_12 ) , V_84 ) ;
if ( ! V_13 )
return - V_99 ;
F_61 ( & V_13 -> V_123 ) ;
F_62 ( & V_13 -> V_22 ) ;
F_63 ( & V_13 -> V_24 ) ;
V_13 -> V_123 . V_8 = ( unsigned long ) V_13 ;
V_13 -> V_123 . V_126 = F_58 ;
V_13 -> V_7 = V_7 ;
V_13 -> V_15 = 0 ;
V_13 -> V_17 = 0 ;
V_13 -> V_37 = 0 ;
F_64 ( V_7 , V_13 ) ;
V_78 = F_35 ( V_7 ) ;
return V_78 ;
}
static int F_65 ( struct V_6 * V_7 )
{
struct V_12 * V_13 = F_30 ( V_7 ) ;
F_32 ( V_7 -> V_81 ) ;
F_66 ( & V_13 -> V_123 ) ;
F_21 ( V_13 ) ;
return 0 ;
}
