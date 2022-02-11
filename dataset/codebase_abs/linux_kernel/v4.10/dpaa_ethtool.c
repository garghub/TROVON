static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
int V_5 ;
if ( ! V_2 -> V_6 ) {
F_2 ( V_2 , L_1 ) ;
return 0 ;
}
V_5 = F_3 ( V_2 -> V_6 , V_4 ) ;
return V_5 ;
}
static int F_4 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
int V_5 ;
if ( ! V_2 -> V_6 ) {
F_5 ( V_2 , L_1 ) ;
return - V_7 ;
}
V_5 = F_6 ( V_2 -> V_6 , V_4 ) ;
if ( V_5 < 0 )
F_5 ( V_2 , L_2 , V_5 ) ;
return V_5 ;
}
static void F_7 ( struct V_1 * V_2 ,
struct V_8 * V_9 )
{
int V_10 ;
F_8 ( V_9 -> V_11 , V_12 ,
sizeof( V_9 -> V_11 ) ) ;
V_10 = snprintf ( V_9 -> V_13 , sizeof( V_9 -> V_13 ) ,
L_3 , 0 ) ;
V_10 = snprintf ( V_9 -> V_14 , sizeof( V_9 -> V_14 ) ,
L_3 , 0 ) ;
if ( V_10 >= sizeof( V_9 -> V_14 ) ) {
F_9 ( V_2 , L_4 , V_10 ) ;
}
F_8 ( V_9 -> V_15 , F_10 ( V_2 -> V_16 . V_17 -> V_17 ) ,
sizeof( V_9 -> V_15 ) ) ;
}
static T_1 F_11 ( struct V_1 * V_2 )
{
return ( (struct V_18 * ) F_12 ( V_2 ) ) -> V_19 ;
}
static void F_13 ( struct V_1 * V_2 ,
T_1 V_19 )
{
( (struct V_18 * ) F_12 ( V_2 ) ) -> V_19 = V_19 ;
}
static int F_14 ( struct V_1 * V_2 )
{
int V_5 ;
if ( ! V_2 -> V_6 ) {
F_5 ( V_2 , L_1 ) ;
return - V_7 ;
}
V_5 = 0 ;
if ( V_2 -> V_6 -> V_20 ) {
V_5 = F_15 ( V_2 -> V_6 ) ;
if ( V_5 < 0 )
F_5 ( V_2 , L_5 ,
V_5 ) ;
}
return V_5 ;
}
static void F_16 ( struct V_1 * V_2 ,
struct V_21 * V_22 )
{
struct V_23 * V_24 ;
struct V_18 * V_25 ;
V_25 = F_12 ( V_2 ) ;
V_24 = V_25 -> V_24 ;
if ( ! V_2 -> V_6 ) {
F_5 ( V_2 , L_1 ) ;
return;
}
V_22 -> V_20 = V_24 -> V_26 ;
V_22 -> V_27 = V_24 -> V_28 ;
V_22 -> V_29 = V_24 -> V_30 ;
}
static int F_17 ( struct V_1 * V_2 ,
struct V_21 * V_22 )
{
struct V_23 * V_24 ;
struct V_31 * V_6 ;
bool V_27 , V_29 ;
struct V_18 * V_25 ;
T_1 V_32 , V_33 ;
int V_5 ;
V_25 = F_12 ( V_2 ) ;
V_24 = V_25 -> V_24 ;
V_6 = V_2 -> V_6 ;
if ( ! V_6 ) {
F_5 ( V_2 , L_1 ) ;
return - V_7 ;
}
if ( ! ( V_6 -> V_34 & V_35 ) ||
( ! ( V_6 -> V_34 & V_36 ) &&
( V_22 -> V_27 != V_22 -> V_29 ) ) )
return - V_37 ;
V_24 -> V_26 = ! ! V_22 -> V_20 ;
V_24 -> V_38 = ! ! V_22 -> V_27 ;
V_24 -> V_39 = ! ! V_22 -> V_29 ;
V_32 = 0 ;
if ( V_22 -> V_27 )
V_32 = V_40 | V_41 ;
if ( V_22 -> V_29 )
V_32 |= V_41 ;
V_33 = V_6 -> V_42 &
( V_40 | V_41 ) ;
if ( V_33 != V_32 ) {
V_6 -> V_42 &= ~ ( V_40
| V_41 ) ;
V_6 -> V_42 |= V_32 ;
if ( V_6 -> V_20 ) {
V_5 = F_15 ( V_6 ) ;
if ( V_5 < 0 )
F_5 ( V_2 , L_5 ,
V_5 ) ;
}
}
F_18 ( V_24 , & V_27 , & V_29 ) ;
V_5 = F_19 ( V_24 , V_27 , V_29 ) ;
if ( V_5 < 0 )
F_5 ( V_2 , L_6 , V_5 ) ;
return V_5 ;
}
static int F_20 ( struct V_1 * V_2 , int type )
{
unsigned int V_43 , V_44 ;
V_44 = F_21 () + 1 ;
V_43 = V_44 * ( V_45 + V_46 ) +
V_47 ;
switch ( type ) {
case V_48 :
return V_43 ;
default:
return - V_49 ;
}
}
static void F_22 ( struct V_50 * V_51 , int V_52 ,
int V_53 , T_2 * V_54 , T_2 * V_55 )
{
int V_56 = V_52 + 1 ;
int V_57 = 0 , V_58 ;
V_55 [ V_57 * V_56 + V_53 ] = V_51 -> V_59 ;
V_55 [ V_57 ++ * V_56 + V_52 ] += V_51 -> V_59 ;
V_55 [ V_57 * V_56 + V_53 ] = V_51 -> V_60 . V_61 ;
V_55 [ V_57 ++ * V_56 + V_52 ] += V_51 -> V_60 . V_61 ;
V_55 [ V_57 * V_56 + V_53 ] = V_51 -> V_60 . V_62 ;
V_55 [ V_57 ++ * V_56 + V_52 ] += V_51 -> V_60 . V_62 ;
V_55 [ V_57 * V_56 + V_53 ] = V_51 -> V_63 ;
V_55 [ V_57 ++ * V_56 + V_52 ] += V_51 -> V_63 ;
V_55 [ V_57 * V_56 + V_53 ] = V_51 -> V_64 ;
V_55 [ V_57 ++ * V_56 + V_52 ] += V_51 -> V_64 ;
V_55 [ V_57 * V_56 + V_53 ] = V_51 -> V_60 . V_65 ;
V_55 [ V_57 ++ * V_56 + V_52 ] += V_51 -> V_60 . V_65 ;
V_55 [ V_57 * V_56 + V_53 ] = V_51 -> V_60 . V_66 ;
V_55 [ V_57 ++ * V_56 + V_52 ] += V_51 -> V_60 . V_66 ;
for ( V_58 = 0 ; V_58 < V_46 ; V_58 ++ ) {
V_55 [ V_57 * V_56 + V_53 ] = V_54 [ V_58 ] ;
V_55 [ V_57 ++ * V_56 + V_52 ] += V_54 [ V_58 ] ;
}
}
static void F_23 ( struct V_1 * V_2 ,
struct V_67 * V_60 , T_2 * V_55 )
{
T_2 V_54 [ V_46 ] , V_68 , V_69 ;
struct V_50 * V_51 ;
struct V_70 V_66 ;
unsigned int V_52 , V_71 ;
struct V_72 V_73 ;
struct V_74 * V_74 ;
struct V_18 * V_25 ;
int V_43 , V_75 , V_58 ;
bool V_76 ;
V_43 = F_20 ( V_2 , V_48 ) ;
V_25 = F_12 ( V_2 ) ;
V_52 = F_21 () ;
memset ( & V_54 , 0 , sizeof( V_54 ) ) ;
memset ( & V_66 , 0 , sizeof( struct V_70 ) ) ;
memset ( & V_73 , 0 , sizeof( struct V_72 ) ) ;
memset ( V_55 , 0 , V_43 * sizeof( T_2 ) ) ;
F_24 (i) {
V_51 = F_25 ( V_25 -> V_51 , V_75 ) ;
for ( V_58 = 0 ; V_58 < V_46 ; V_58 ++ ) {
V_74 = V_25 -> V_77 [ V_58 ] ;
if ( ! V_74 -> V_78 )
continue;
V_54 [ V_58 ] = * ( F_25 ( V_74 -> V_78 , V_75 ) ) ;
}
V_66 . V_79 += V_51 -> V_66 . V_79 ;
V_66 . V_80 += V_51 -> V_66 . V_80 ;
V_66 . V_81 += V_51 -> V_66 . V_81 ;
V_66 . V_82 += V_51 -> V_66 . V_82 ;
V_73 . V_83 += V_51 -> V_73 . V_83 ;
V_73 . V_84 += V_51 -> V_73 . V_84 ;
V_73 . V_85 += V_51 -> V_73 . V_85 ;
V_73 . V_86 += V_51 -> V_73 . V_86 ;
V_73 . V_87 += V_51 -> V_73 . V_87 ;
V_73 . V_88 += V_51 -> V_73 . V_88 ;
V_73 . V_89 += V_51 -> V_73 . V_89 ;
V_73 . V_90 += V_51 -> V_73 . V_90 ;
F_22 ( V_51 , V_52 , V_75 , V_54 , V_55 ) ;
}
V_71 = ( V_52 + 1 ) * ( V_45 + V_46 ) ;
memcpy ( V_55 + V_71 , & V_66 , sizeof( struct V_70 ) ) ;
V_71 += sizeof( struct V_70 ) / sizeof( T_2 ) ;
memcpy ( V_55 + V_71 , & V_73 , sizeof( struct V_72 ) ) ;
V_69 = 0 ;
V_76 = 0 ;
V_68 = F_26 ( V_25 -> V_91 . V_92 ) ;
if ( F_27 ( & V_25 -> V_91 . V_93 , & V_76 ) == 0 ) {
V_69 = V_25 -> V_91 . V_94 ;
V_25 -> V_91 . V_92 = 0 ;
V_25 -> V_91 . V_94 = 0 ;
}
V_71 += sizeof( struct V_72 ) / sizeof( T_2 ) ;
V_55 [ V_71 ++ ] = V_68 ;
V_55 [ V_71 ++ ] = V_69 ;
V_55 [ V_71 ++ ] = V_76 ;
}
static void F_28 ( struct V_1 * V_2 , T_1 V_95 ,
T_3 * V_55 )
{
unsigned int V_75 , V_58 , V_52 , V_96 ;
char V_97 [ V_98 ] ;
T_3 * V_99 ;
memset ( V_97 , 0 , sizeof( V_97 ) ) ;
V_99 = V_55 ;
V_52 = F_21 () ;
V_96 = V_47 * V_98 ;
for ( V_75 = 0 ; V_75 < V_45 ; V_75 ++ ) {
for ( V_58 = 0 ; V_58 < V_52 ; V_58 ++ ) {
snprintf ( V_97 , V_98 , L_7 ,
V_100 [ V_75 ] , V_58 ) ;
memcpy ( V_99 , V_97 , V_98 ) ;
V_99 += V_98 ;
}
snprintf ( V_97 , V_98 , L_8 ,
V_100 [ V_75 ] ) ;
memcpy ( V_99 , V_97 , V_98 ) ;
V_99 += V_98 ;
}
for ( V_75 = 0 ; V_75 < V_46 ; V_75 ++ ) {
for ( V_58 = 0 ; V_58 < V_52 ; V_58 ++ ) {
snprintf ( V_97 , V_98 ,
L_9 , 'a' + V_75 , V_58 ) ;
memcpy ( V_99 , V_97 , V_98 ) ;
V_99 += V_98 ;
}
snprintf ( V_97 , V_98 , L_10 ,
'a' + V_75 ) ;
memcpy ( V_99 , V_97 , V_98 ) ;
V_99 += V_98 ;
}
memcpy ( V_99 , V_101 , V_96 ) ;
}
