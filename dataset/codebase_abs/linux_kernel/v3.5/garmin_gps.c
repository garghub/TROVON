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
struct V_10 * V_11 = F_7 ( & V_7 -> V_7 ) ;
if ( V_11 && V_9 ) {
F_8 ( V_12 , & V_7 -> V_13 ,
V_14 , V_9 , V_8 ) ;
F_9 ( V_11 , V_8 , V_9 ) ;
F_10 ( V_11 ) ;
}
F_11 ( V_11 ) ;
}
static int F_12 ( struct V_15 * V_16 ,
unsigned char * V_8 , unsigned int V_17 )
{
int V_18 = 0 ;
int V_19 = 0 ;
unsigned long V_20 ;
struct V_21 * V_22 ;
if ( V_17 ) {
V_22 = F_13 ( sizeof( struct V_21 ) + V_17 ,
V_23 ) ;
if ( V_22 == NULL ) {
F_14 ( & V_16 -> V_7 -> V_13 , L_1 ) ;
return 0 ;
}
V_22 -> V_24 = V_17 ;
memcpy ( V_22 -> V_8 , V_8 , V_17 ) ;
F_15 ( & V_16 -> V_25 , V_20 ) ;
V_16 -> V_20 |= V_26 ;
V_19 = F_16 ( & V_16 -> V_27 ) ;
V_22 -> V_28 = V_16 -> V_29 ++ ;
F_17 ( & V_22 -> V_30 , & V_16 -> V_27 ) ;
V_18 = V_16 -> V_18 ;
F_18 ( & V_16 -> V_25 , V_20 ) ;
F_19 ( L_2 ,
V_14 , V_22 -> V_28 , V_17 ) ;
if ( V_19 && ( V_18 == V_31 ) )
F_20 ( V_16 ) ;
}
return V_19 ;
}
static struct V_21 * F_21 ( struct V_15 * V_16 )
{
unsigned long V_20 ;
struct V_21 * V_19 = NULL ;
F_15 ( & V_16 -> V_25 , V_20 ) ;
if ( ! F_16 ( & V_16 -> V_27 ) ) {
V_19 = (struct V_21 * ) V_16 -> V_27 . V_32 ;
F_22 ( & V_19 -> V_30 ) ;
}
F_18 ( & V_16 -> V_25 , V_20 ) ;
return V_19 ;
}
static void F_23 ( struct V_15 * V_16 )
{
unsigned long V_20 ;
struct V_21 * V_19 = NULL ;
F_15 ( & V_16 -> V_25 , V_20 ) ;
while ( ! F_16 ( & V_16 -> V_27 ) ) {
V_19 = (struct V_21 * ) V_16 -> V_27 . V_32 ;
F_22 ( & V_19 -> V_30 ) ;
F_24 ( V_19 ) ;
}
F_18 ( & V_16 -> V_25 , V_20 ) ;
}
static int F_25 ( struct V_15 * V_16 , T_1 V_33 )
{
T_1 V_22 [ 10 ] ;
T_1 V_34 = 0 ;
T_1 * V_35 = V_22 ;
unsigned V_36 = 0 ;
F_19 ( L_3 , V_14 , 0xFF & V_33 ) ;
* V_35 ++ = V_37 ;
* V_35 ++ = V_38 ;
V_34 += V_38 ;
* V_35 ++ = 2 ;
V_34 += 2 ;
* V_35 ++ = V_33 ;
V_34 += V_33 ;
if ( V_33 == V_37 )
* V_35 ++ = V_37 ;
* V_35 ++ = 0 ;
* V_35 ++ = 0xFF & ( - V_34 ) ;
* V_35 ++ = V_37 ;
* V_35 ++ = V_39 ;
V_36 = V_35 - V_22 ;
F_6 ( V_16 -> V_7 , V_22 , V_36 ) ;
return 0 ;
}
static int F_26 ( struct V_15 * V_16 , int V_40 )
{
unsigned long V_20 ;
const T_1 * V_41 = V_16 -> V_42 + V_43 ;
V_2 * V_44 = ( V_2 * ) V_16 -> V_42 ;
int V_34 = 0 ;
int V_45 = 0 ;
int V_46 = V_41 [ 0 ] ;
int V_24 = V_41 [ 1 ] ;
F_8 ( V_12 , & V_16 -> V_7 -> V_13 ,
V_14 , V_40 - V_43 , V_41 ) ;
if ( V_24 != ( V_40 - V_43 - 3 ) ) {
F_19 ( L_4 ,
V_14 , V_24 , ( V_40 - V_43 - 3 ) ) ;
return - V_47 ;
}
V_34 += * V_41 ++ ;
V_34 += * V_41 ++ ;
if ( ( T_1 * ) & ( V_44 [ 3 ] ) != V_41 ) {
F_19 ( L_5 ,
V_14 , & ( V_44 [ 4 ] ) , V_41 ) ;
return - V_47 ;
}
while ( V_45 < V_24 ) {
V_34 += * V_41 ++ ;
V_45 ++ ;
}
if ( ( 0xff & ( V_34 + * V_41 ) ) != 0 ) {
F_19 ( L_6 ,
V_14 , 0xff & - V_34 , 0xff & * V_41 ) ;
return - V_47 ;
}
V_44 [ 0 ] = F_27 ( V_48 ) ;
V_44 [ 1 ] = F_27 ( V_46 ) ;
V_44 [ 2 ] = F_27 ( V_24 ) ;
F_28 ( V_16 -> V_7 , V_16 -> V_42 ,
V_49 + V_24 , 0 ) ;
if ( F_5 ( V_16 -> V_42 ) ) {
F_15 ( & V_16 -> V_25 , V_20 ) ;
V_16 -> V_20 |= V_50 ;
F_18 ( & V_16 -> V_25 , V_20 ) ;
F_23 ( V_16 ) ;
}
return V_40 ;
}
static int F_29 ( struct V_15 * V_16 ,
const unsigned char * V_3 , int V_40 )
{
unsigned long V_20 ;
int V_51 = 0 ;
int V_52 = 0 ;
T_1 * V_53 ;
int V_24 ;
int V_54 ;
int V_55 ;
T_1 V_8 ;
F_15 ( & V_16 -> V_25 , V_20 ) ;
V_53 = V_16 -> V_42 ;
V_24 = V_16 -> V_56 ;
V_54 = V_16 -> V_20 & V_57 ;
V_55 = V_16 -> V_20 & V_58 ;
F_18 ( & V_16 -> V_25 , V_20 ) ;
if ( V_24 == 0 )
V_24 = V_43 ;
while ( V_51 < V_40 ) {
V_8 = * ( V_3 + V_51 ) ;
V_51 ++ ;
if ( V_8 == V_37 ) {
if ( V_55 ) {
V_55 = 0 ;
V_24 = V_43 ;
V_54 = 1 ;
} else if ( V_54 ) {
V_53 [ V_24 ++ ] = V_8 ;
V_54 = 0 ;
} else {
V_54 = 1 ;
}
} else if ( V_8 == V_39 ) {
if ( V_54 ) {
V_8 = V_53 [ V_43 ] ;
if ( V_8 == V_38 ) {
V_52 = V_38 ;
F_19 ( L_7 ) ;
} else if ( V_8 == V_59 ) {
V_52 = V_59 ;
F_19 ( L_8 ) ;
} else {
F_19 ( L_9 ,
0xFF & V_8 ) ;
F_26 ( V_16 , V_24 ) ;
}
V_55 = 1 ;
V_24 = V_43 ;
V_54 = 0 ;
} else {
V_53 [ V_24 ++ ] = V_8 ;
}
} else if ( ! V_55 ) {
if ( V_54 ) {
V_24 = V_43 ;
V_54 = 0 ;
}
V_53 [ V_24 ++ ] = V_8 ;
}
if ( V_24 >= V_60 ) {
F_19 ( L_10 , V_14 ) ;
V_55 = 1 ;
V_24 = V_43 ;
V_54 = 0 ;
}
}
F_15 ( & V_16 -> V_25 , V_20 ) ;
V_16 -> V_56 = V_24 ;
if ( V_55 )
V_16 -> V_20 |= V_58 ;
else
V_16 -> V_20 &= ~ V_58 ;
if ( V_54 )
V_16 -> V_20 |= V_57 ;
else
V_16 -> V_20 &= ~ V_57 ;
F_18 ( & V_16 -> V_25 , V_20 ) ;
if ( V_52 ) {
if ( F_20 ( V_16 ) > 0 )
V_16 -> V_18 = V_61 ;
else
V_16 -> V_18 = V_31 ;
}
return V_40 ;
}
static int F_30 ( struct V_15 * V_16 ,
const unsigned char * V_3 , int V_40 )
{
const unsigned char * V_62 ;
unsigned char * V_63 ;
int V_46 = 0 ;
int V_64 = 0 ;
int V_34 = 0 ;
int V_65 = 0 ;
int V_66 ;
F_19 ( L_11 , V_14 ,
V_16 -> V_18 , V_40 ) ;
V_66 = V_16 -> V_67 ;
if ( ( V_66 + V_40 ) > V_68 ) {
F_19 ( L_12 ) ;
V_16 -> V_67 = 0 ;
return - 4 ;
}
memcpy ( V_16 -> V_69 + V_66 , V_3 , V_40 ) ;
V_66 += V_40 ;
V_16 -> V_67 = V_66 ;
if ( V_66 >= V_49 ) {
V_46 = F_3 ( V_16 -> V_69 ) ;
V_64 = F_4 ( V_16 -> V_69 ) ;
V_65 = V_49 + V_64 ;
if ( V_66 < V_65 )
return 0 ;
} else {
return 0 ;
}
F_19 ( L_13 , V_14 , V_66 , V_65 ) ;
F_8 ( V_12 , & V_16 -> V_7 -> V_13 ,
V_14 , V_66 , V_16 -> V_69 ) ;
V_16 -> V_67 = 0 ;
if ( V_48 != F_1 ( V_16 -> V_69 ) ) {
F_19 ( L_14 ,
F_1 ( V_16 -> V_69 ) ) ;
return - 1 ;
}
if ( V_46 > 255 ) {
F_19 ( L_15 , V_46 ) ;
return - 2 ;
}
if ( V_64 > 255 ) {
F_19 ( L_16 , V_64 ) ;
return - 3 ;
}
V_66 = 0 ;
V_62 = V_16 -> V_69 + V_49 ;
for ( V_65 = 0 ; V_65 < V_64 ; V_65 ++ ) {
if ( * V_62 ++ == V_37 )
V_66 ++ ;
}
V_62 = V_16 -> V_69 + V_49 ;
if ( V_66 > ( V_49 - 2 ) ) {
V_63 = V_16 -> V_69 + V_68 - V_64 ;
memcpy ( V_63 , V_62 , V_64 ) ;
V_62 = V_63 ;
}
V_63 = V_16 -> V_69 ;
* V_63 ++ = V_37 ;
* V_63 ++ = V_46 ;
V_34 += V_46 ;
* V_63 ++ = V_64 ;
V_34 += V_64 ;
if ( V_64 == V_37 )
* V_63 ++ = V_37 ;
for ( V_65 = 0 ; V_65 < V_64 ; V_65 ++ ) {
T_1 V_70 = * V_62 ++ ;
* V_63 ++ = V_70 ;
V_34 += V_70 ;
if ( V_70 == V_37 )
* V_63 ++ = V_37 ;
}
V_34 = 0xFF & - V_34 ;
* V_63 ++ = V_34 ;
if ( V_34 == V_37 )
* V_63 ++ = V_37 ;
* V_63 ++ = V_37 ;
* V_63 ++ = V_39 ;
V_65 = V_63 - V_16 -> V_69 ;
F_6 ( V_16 -> V_7 , V_16 -> V_69 , V_65 ) ;
V_16 -> V_33 = V_46 ;
V_16 -> V_18 = V_71 ;
return V_65 ;
}
static int F_20 ( struct V_15 * V_16 )
{
int V_19 = 0 ;
struct V_21 * V_22 = NULL ;
while ( ( V_22 = F_21 ( V_16 ) ) != NULL ) {
F_19 ( L_17 , V_14 , V_22 -> V_28 ) ;
V_19 = F_30 ( V_16 , V_22 -> V_8 , V_22 -> V_24 ) ;
if ( V_19 > 0 ) {
F_24 ( V_22 ) ;
return V_19 ;
}
F_24 ( V_22 ) ;
}
return V_19 ;
}
static int F_31 ( struct V_15 * V_16 ,
const unsigned char * V_3 , int V_40 )
{
unsigned long V_20 ;
T_1 * V_53 ;
int V_51 = 0 ;
int V_19 = V_40 ;
int V_72 ;
while ( V_51 < V_40 ) {
if ( V_16 -> V_56 >= V_49 )
V_72 = V_49
+ F_4 ( V_16 -> V_42 ) ;
else
V_72 = V_49 ;
if ( V_72 >= V_60 ) {
F_19 ( L_18 , V_14 , V_72 ) ;
V_16 -> V_56 = 0 ;
V_40 = 0 ;
V_19 = - V_47 ;
} else {
V_72 -= V_16 -> V_56 ;
if ( V_72 > ( V_40 - V_51 ) )
V_72 = ( V_40 - V_51 ) ;
if ( V_72 > 0 ) {
V_53 = V_16 -> V_42
+ V_16 -> V_56 ;
memcpy ( V_53 , V_3 + V_51 , V_72 ) ;
V_16 -> V_56 += V_72 ;
V_51 += V_72 ;
}
}
if ( V_16 -> V_56 >= V_49 ) {
V_72 = V_49 +
F_4 ( V_16 -> V_42 ) ;
if ( V_16 -> V_56 >= V_72 ) {
F_28 ( V_16 -> V_7 ,
V_16 -> V_42 ,
V_72 , 0 ) ;
V_16 -> V_56 = 0 ;
if ( F_5 ( V_16 -> V_42 ) ) {
F_15 ( & V_16 -> V_25 ,
V_20 ) ;
V_16 -> V_20 |= V_50 ;
F_18 (
& V_16 -> V_25 , V_20 ) ;
F_23 ( V_16 ) ;
}
}
}
}
return V_19 ;
}
static void F_32 ( struct V_6 * V_7 )
{
struct V_15 * V_16 = F_33 ( V_7 ) ;
V_2 * V_22 = ( V_2 * ) V_16 -> V_73 ;
V_22 [ 0 ] = F_27 ( V_74 ) ;
V_22 [ 1 ] = F_27 ( V_75 ) ;
V_22 [ 2 ] = F_27 ( 12 ) ;
V_22 [ 3 ] = F_27 ( V_76 << 16 | V_77 ) ;
V_22 [ 4 ] = F_27 ( V_16 -> V_78 ) ;
V_22 [ 5 ] = F_27 ( V_16 -> V_79 ) ;
F_6 ( V_7 , ( T_1 * ) V_22 , 6 * 4 ) ;
}
static int F_34 ( struct V_6 * V_7 )
{
unsigned long V_20 ;
int V_80 ;
struct V_15 * V_16 = F_33 ( V_7 ) ;
F_15 ( & V_16 -> V_25 , V_20 ) ;
V_16 -> V_20 &= ~ ( V_81 ) ;
V_16 -> V_18 = V_82 ;
V_16 -> V_79 = 0 ;
F_18 ( & V_16 -> V_25 , V_20 ) ;
F_35 ( V_7 -> V_83 ) ;
F_19 ( L_19 , V_14 ) ;
V_80 = F_36 ( V_7 -> V_84 -> V_13 ) ;
if ( V_80 )
F_19 ( L_20 ,
V_14 , V_80 ) ;
return V_80 ;
}
static int F_37 ( struct V_15 * V_16 )
{
unsigned long V_20 ;
int V_80 = 0 ;
F_23 ( V_16 ) ;
F_15 ( & V_16 -> V_25 , V_20 ) ;
V_16 -> V_56 = 0 ;
V_16 -> V_67 = 0 ;
F_18 ( & V_16 -> V_25 , V_20 ) ;
return V_80 ;
}
static int F_38 ( struct V_6 * V_7 )
{
struct V_85 * V_84 = V_7 -> V_84 ;
struct V_15 * V_16 = F_33 ( V_7 ) ;
int V_80 = 0 ;
int V_65 = 0 ;
if ( V_80 == 0 ) {
F_35 ( V_7 -> V_83 ) ;
F_19 ( L_21 , V_14 ) ;
V_80 = F_39 ( V_7 -> V_83 , V_86 ) ;
if ( V_80 )
F_14 ( & V_84 -> V_13 -> V_13 ,
L_22 ,
V_14 , V_80 ) ;
}
if ( V_80 == 0 ) {
F_19 ( L_23 , V_14 ) ;
V_16 -> V_18 = V_61 ;
for ( V_65 = 0 ; V_65 < 3 ; V_65 ++ ) {
V_80 = F_28 ( V_7 ,
V_87 ,
sizeof( V_87 ) , 0 ) ;
if ( V_80 < 0 )
break;
}
if ( V_80 > 0 )
V_80 = 0 ;
}
return V_80 ;
}
static int F_40 ( struct V_10 * V_11 , struct V_6 * V_7 )
{
unsigned long V_20 ;
int V_80 = 0 ;
struct V_15 * V_16 = F_33 ( V_7 ) ;
F_15 ( & V_16 -> V_25 , V_20 ) ;
V_16 -> V_78 = V_88 ;
V_16 -> V_40 = 0 ;
V_16 -> V_20 &= V_89 ;
F_18 ( & V_16 -> V_25 , V_20 ) ;
F_35 ( V_7 -> V_90 ) ;
F_35 ( V_7 -> V_91 ) ;
if ( V_16 -> V_18 == V_82 )
V_80 = F_38 ( V_7 ) ;
V_16 -> V_18 = V_61 ;
return V_80 ;
}
static void F_41 ( struct V_6 * V_7 )
{
struct V_85 * V_84 = V_7 -> V_84 ;
struct V_15 * V_16 = F_33 ( V_7 ) ;
F_19 ( L_24 , V_14 ,
V_7 -> V_92 , V_16 -> V_78 ,
V_16 -> V_18 , V_16 -> V_20 ) ;
if ( ! V_84 )
return;
F_42 ( & V_7 -> V_84 -> V_93 ) ;
if ( ! V_7 -> V_84 -> V_94 )
F_37 ( V_16 ) ;
F_35 ( V_7 -> V_91 ) ;
F_35 ( V_7 -> V_90 ) ;
if ( V_16 -> V_18 != V_82 )
V_16 -> V_18 = V_95 ;
F_43 ( & V_7 -> V_84 -> V_93 ) ;
}
static void F_44 ( struct V_96 * V_96 )
{
struct V_6 * V_7 = V_96 -> V_97 ;
if ( V_7 ) {
struct V_15 * V_16 =
F_33 ( V_7 ) ;
if ( V_48 == F_1 ( V_96 -> V_98 ) ) {
if ( V_16 -> V_78 == V_99 ) {
F_25 ( V_16 ,
( ( T_1 * ) V_96 -> V_98 ) [ 4 ] ) ;
}
}
F_45 ( V_7 ) ;
}
F_24 ( V_96 -> V_98 ) ;
}
static int F_28 ( struct V_6 * V_7 ,
const unsigned char * V_3 , int V_40 ,
int V_100 )
{
unsigned long V_20 ;
struct V_85 * V_84 = V_7 -> V_84 ;
struct V_15 * V_16 = F_33 ( V_7 ) ;
struct V_96 * V_96 ;
unsigned char * V_101 ;
int V_80 ;
F_15 ( & V_16 -> V_25 , V_20 ) ;
V_16 -> V_20 &= ~ V_50 ;
F_18 ( & V_16 -> V_25 , V_20 ) ;
V_101 = F_13 ( V_40 , V_23 ) ;
if ( ! V_101 ) {
F_14 ( & V_7 -> V_13 , L_1 ) ;
return - V_102 ;
}
V_96 = F_46 ( 0 , V_23 ) ;
if ( ! V_96 ) {
F_14 ( & V_7 -> V_13 , L_25 ) ;
F_24 ( V_101 ) ;
return - V_102 ;
}
memcpy ( V_101 , V_3 , V_40 ) ;
F_8 ( V_12 , & V_7 -> V_13 , V_14 , V_40 , V_101 ) ;
F_47 ( V_96 , V_84 -> V_13 ,
F_48 ( V_84 -> V_13 ,
V_7 -> V_103 ) ,
V_101 , V_40 ,
F_44 ,
V_100 ? NULL : V_7 ) ;
V_96 -> V_104 |= V_105 ;
if ( V_48 == F_1 ( V_101 ) ) {
F_15 ( & V_16 -> V_25 , V_20 ) ;
V_16 -> V_20 |= V_106 ;
F_18 ( & V_16 -> V_25 , V_20 ) ;
if ( V_16 -> V_78 == V_99 ) {
F_23 ( V_16 ) ;
V_16 -> V_18 = V_31 ;
}
}
V_80 = F_39 ( V_96 , V_23 ) ;
if ( V_80 ) {
F_14 ( & V_7 -> V_13 ,
L_26 ,
V_14 , V_80 ) ;
V_40 = V_80 ;
}
F_49 ( V_96 ) ;
return V_40 ;
}
static int F_50 ( struct V_10 * V_11 , struct V_6 * V_7 ,
const unsigned char * V_3 , int V_40 )
{
int V_46 , V_107 , V_72 ;
struct V_15 * V_16 = F_33 ( V_7 ) ;
V_2 * V_73 = ( V_2 * ) V_16 -> V_73 ;
F_8 ( V_12 , & V_7 -> V_13 , V_14 , V_40 , V_3 ) ;
if ( V_16 -> V_18 == V_82 )
return - V_108 ;
if ( V_40 >= V_49 ) {
V_72 = V_109 ;
if ( V_40 < V_72 )
V_72 = V_40 ;
memcpy ( V_16 -> V_73 , V_3 , V_72 ) ;
V_107 = F_4 ( V_16 -> V_73 ) ;
V_46 = F_3 ( V_16 -> V_73 ) ;
if ( V_40 == ( V_49 + V_107 )
&& V_74 ==
F_1 ( V_16 -> V_73 ) ) {
F_19 ( L_27 ,
V_14 , V_46 ) ;
F_37 ( V_16 ) ;
switch ( V_46 ) {
case V_110 :
if ( V_107 != 4 )
return - V_47 ;
V_12 = F_51 ( V_73 [ 3 ] ) ;
F_19 ( L_28 ,
V_14 , V_12 ) ;
break;
case V_111 :
if ( V_107 != 4 )
return - V_47 ;
V_16 -> V_78 = F_51 ( V_73 [ 3 ] ) ;
F_19 ( L_29 ,
V_14 , V_16 -> V_78 ) ;
break;
case V_112 :
F_32 ( V_7 ) ;
break;
case V_113 :
F_34 ( V_7 ) ;
break;
case V_114 :
if ( V_107 != 4 )
return - V_47 ;
V_88 = F_51 ( V_73 [ 3 ] ) ;
F_19 ( L_30 ,
V_14 ,
V_16 -> V_78 ) ;
break;
}
return V_40 ;
}
}
if ( V_16 -> V_78 == V_99 ) {
return F_29 ( V_16 , V_3 , V_40 ) ;
} else {
return F_31 ( V_16 , V_3 , V_40 ) ;
}
}
static int F_52 ( struct V_10 * V_11 )
{
struct V_6 * V_7 = V_11 -> V_115 ;
struct V_15 * V_16 = F_33 ( V_7 ) ;
return V_68 - V_16 -> V_67 ;
}
static void F_53 ( struct V_15 * V_16 ,
unsigned char * V_8 , unsigned V_17 ,
int V_116 )
{
unsigned long V_20 ;
if ( V_16 -> V_20 & V_50 ) {
F_19 ( L_31 , V_14 ) ;
} else if ( V_16 -> V_18 != V_95 &&
V_16 -> V_18 != V_82 ) {
if ( V_16 -> V_20 & V_26 ) {
F_12 ( V_16 , V_8 , V_17 ) ;
} else if ( V_116 ||
F_1 ( V_8 ) == V_48 ) {
F_15 ( & V_16 -> V_25 , V_20 ) ;
V_16 -> V_20 |= V_117 ;
F_18 ( & V_16 -> V_25 , V_20 ) ;
if ( V_16 -> V_78 == V_99 ) {
F_12 ( V_16 , V_8 , V_17 ) ;
} else {
F_6 ( V_16 -> V_7 , V_8 ,
V_17 ) ;
}
}
}
}
static void F_54 ( struct V_96 * V_96 )
{
unsigned long V_20 ;
struct V_6 * V_7 = V_96 -> V_97 ;
struct V_85 * V_84 = V_7 -> V_84 ;
struct V_15 * V_16 = F_33 ( V_7 ) ;
unsigned char * V_8 = V_96 -> V_98 ;
int V_80 = V_96 -> V_80 ;
int V_118 ;
if ( ! V_84 ) {
F_19 ( L_32 , V_14 ) ;
return;
}
if ( V_80 ) {
F_19 ( L_33 ,
V_14 , V_80 ) ;
return;
}
F_8 ( V_12 , & V_7 -> V_13 ,
V_14 , V_96 -> V_9 , V_8 ) ;
F_53 ( V_16 , V_8 , V_96 -> V_9 , 1 ) ;
if ( V_96 -> V_9 == 0 &&
0 != ( V_16 -> V_20 & V_119 ) ) {
F_15 ( & V_16 -> V_25 , V_20 ) ;
V_16 -> V_20 &= ~ V_119 ;
F_18 ( & V_16 -> V_25 , V_20 ) ;
V_118 = F_39 ( V_7 -> V_91 , V_23 ) ;
if ( V_118 )
F_14 ( & V_7 -> V_13 ,
L_34 ,
V_14 , V_118 ) ;
} else if ( V_96 -> V_9 > 0 ) {
if ( 0 == ( V_16 -> V_20 & V_120 ) ) {
V_118 = F_39 ( V_7 -> V_91 , V_23 ) ;
if ( V_118 )
F_14 ( & V_7 -> V_13 ,
L_35
L_36 , V_14 , V_118 ) ;
}
} else {
F_19 ( L_37 , V_14 ) ;
F_15 ( & V_16 -> V_25 , V_20 ) ;
V_16 -> V_20 &= ~ V_121 ;
F_18 ( & V_16 -> V_25 , V_20 ) ;
}
}
static void F_55 ( struct V_96 * V_96 )
{
unsigned long V_20 ;
int V_118 ;
struct V_6 * V_7 = V_96 -> V_97 ;
struct V_15 * V_16 = F_33 ( V_7 ) ;
unsigned char * V_8 = V_96 -> V_98 ;
int V_80 = V_96 -> V_80 ;
switch ( V_80 ) {
case 0 :
break;
case - V_122 :
case - V_123 :
case - V_124 :
F_19 ( L_38 ,
V_14 , V_80 ) ;
return;
default:
F_19 ( L_39 ,
V_14 , V_80 ) ;
return;
}
F_8 ( V_12 , & V_7 -> V_13 , V_14 ,
V_96 -> V_9 , V_96 -> V_98 ) ;
if ( V_96 -> V_9 == sizeof( V_125 ) &&
0 == memcmp ( V_8 , V_125 ,
sizeof( V_125 ) ) ) {
F_19 ( L_40 , V_14 ) ;
if ( 0 == ( V_16 -> V_20 & V_121 ) ) {
V_118 = F_39 ( V_7 -> V_91 , V_23 ) ;
if ( V_118 ) {
F_14 ( & V_7 -> V_13 ,
L_41 ,
V_14 , V_118 ) ;
} else {
F_15 ( & V_16 -> V_25 , V_20 ) ;
V_16 -> V_20 |= V_121 ;
F_18 ( & V_16 -> V_25 ,
V_20 ) ;
}
} else {
F_15 ( & V_16 -> V_25 , V_20 ) ;
V_16 -> V_20 |= V_119 ;
F_18 ( & V_16 -> V_25 , V_20 ) ;
}
} else if ( V_96 -> V_9 == ( 4 + sizeof( V_126 ) )
&& 0 == memcmp ( V_8 , V_126 ,
sizeof( V_126 ) ) ) {
F_15 ( & V_16 -> V_25 , V_20 ) ;
V_16 -> V_20 |= V_89 ;
F_18 ( & V_16 -> V_25 , V_20 ) ;
V_16 -> V_79 = F_2 (
( V_2 * ) ( V_8 + V_49 ) ) ;
F_19 ( L_42 ,
V_14 , V_16 -> V_79 ) ;
}
F_53 ( V_16 , V_8 , V_96 -> V_9 , 0 ) ;
V_118 = F_39 ( V_96 , V_23 ) ;
if ( V_118 )
F_14 ( & V_96 -> V_13 -> V_13 ,
L_43 ,
V_14 , V_118 ) ;
}
static int F_56 ( struct V_15 * V_16 )
{
unsigned long V_20 ;
struct V_21 * V_22 ;
if ( ( V_16 -> V_20 & V_120 ) == 0 ) {
V_22 = F_21 ( V_16 ) ;
if ( V_22 != NULL ) {
F_6 ( V_16 -> V_7 , V_22 -> V_8 , V_22 -> V_24 ) ;
F_24 ( V_22 ) ;
F_57 ( & V_16 -> V_127 , ( 1 ) + V_128 ) ;
} else {
F_15 ( & V_16 -> V_25 , V_20 ) ;
V_16 -> V_20 &= ~ V_26 ;
F_18 ( & V_16 -> V_25 , V_20 ) ;
}
}
return 0 ;
}
static void F_58 ( struct V_10 * V_11 )
{
struct V_6 * V_7 = V_11 -> V_115 ;
struct V_15 * V_16 = F_33 ( V_7 ) ;
F_59 ( & V_16 -> V_25 ) ;
V_16 -> V_20 |= V_26 | V_120 ;
F_60 ( & V_16 -> V_25 ) ;
}
static void F_61 ( struct V_10 * V_11 )
{
struct V_6 * V_7 = V_11 -> V_115 ;
struct V_15 * V_16 = F_33 ( V_7 ) ;
int V_80 ;
F_59 ( & V_16 -> V_25 ) ;
V_16 -> V_20 &= ~ V_120 ;
F_60 ( & V_16 -> V_25 ) ;
if ( V_16 -> V_78 == V_129 )
F_56 ( V_16 ) ;
if ( 0 != ( V_16 -> V_20 & V_121 ) ) {
V_80 = F_39 ( V_7 -> V_91 , V_86 ) ;
if ( V_80 )
F_14 ( & V_7 -> V_13 ,
L_34 ,
V_14 , V_80 ) ;
}
}
static void F_62 ( unsigned long V_8 )
{
struct V_15 * V_16 = (struct V_15 * ) V_8 ;
if ( V_16 -> V_78 == V_129 )
if ( V_16 -> V_20 & V_26 )
F_56 ( V_16 ) ;
}
static int F_63 ( struct V_85 * V_84 )
{
int V_80 = 0 ;
struct V_6 * V_7 = V_84 -> V_7 [ 0 ] ;
struct V_15 * V_16 = NULL ;
V_16 = F_64 ( sizeof( struct V_15 ) , V_86 ) ;
if ( V_16 == NULL ) {
F_14 ( & V_7 -> V_13 , L_44 , V_14 ) ;
return - V_102 ;
}
F_65 ( & V_16 -> V_127 ) ;
F_66 ( & V_16 -> V_25 ) ;
F_67 ( & V_16 -> V_27 ) ;
V_16 -> V_127 . V_8 = ( unsigned long ) V_16 ;
V_16 -> V_127 . V_130 = F_62 ;
V_16 -> V_7 = V_7 ;
V_16 -> V_18 = 0 ;
V_16 -> V_20 = 0 ;
V_16 -> V_40 = 0 ;
F_68 ( V_7 , V_16 ) ;
V_80 = F_38 ( V_7 ) ;
return V_80 ;
}
static void F_69 ( struct V_85 * V_84 )
{
struct V_6 * V_7 = V_84 -> V_7 [ 0 ] ;
struct V_15 * V_16 = F_33 ( V_7 ) ;
F_35 ( V_7 -> V_83 ) ;
F_70 ( & V_16 -> V_127 ) ;
}
static void F_71 ( struct V_85 * V_84 )
{
struct V_6 * V_7 = V_84 -> V_7 [ 0 ] ;
struct V_15 * V_16 = F_33 ( V_7 ) ;
F_24 ( V_16 ) ;
}
