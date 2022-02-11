static void F_1 ( struct V_1 * V_2 , int V_3 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
if ( V_3 == - V_7 )
return;
V_5 -> V_3 = V_3 ;
F_2 ( & V_5 -> V_8 ) ;
}
static int F_3 ( struct V_9 * V_10 , T_1 * V_11 ,
struct V_12 * V_13 , unsigned int V_14 )
{
struct V_4 V_5 ;
struct V_15 * V_2 ;
int V_16 ;
F_4 ( & V_5 . V_8 ) ;
V_2 = F_5 ( V_10 , V_17 ) ;
if ( ! V_2 )
return - V_18 ;
F_6 ( V_2 , V_19 ,
F_1 , & V_5 ) ;
F_7 ( V_2 , V_13 , V_11 , V_14 ) ;
V_16 = F_8 ( V_2 ) ;
if ( ( V_16 == - V_7 ) || ( V_16 == - V_20 ) ) {
V_16 = F_9 ( & V_5 . V_8 ) ;
if ( ! V_16 )
V_16 = V_5 . V_3 ;
}
F_10 ( V_2 ) ;
return V_16 ;
}
static int F_11 ( struct V_1 * V_21 )
{
struct V_15 * V_2 = F_12 ( V_21 ) ;
struct V_9 * V_10 = F_13 ( V_2 ) ;
struct V_22 * V_23 = F_14 ( V_10 ) ;
struct V_24 * V_25 = F_15 ( V_2 ) ;
struct V_12 V_13 [ 2 ] ;
unsigned int V_26 =
F_16 ( F_17 ( V_10 ) ) ;
unsigned int V_27 = F_18 ( V_10 ) ;
F_19 ( V_13 , F_20 ( V_13 ) ) ;
F_21 ( & V_13 [ 0 ] , V_23 -> V_28 . V_29 . V_30 , V_26 ) ;
F_21 ( & V_13 [ 1 ] , V_25 -> V_23 , V_27 ) ;
return F_3 ( V_23 -> V_28 . V_29 . V_31 , V_2 -> V_5 , V_13 ,
V_26 + V_27 ) ;
}
static int F_22 ( struct V_1 * V_21 , int V_16 )
{
struct V_15 * V_2 = F_12 ( V_21 ) ;
struct V_9 * V_10 = F_13 ( V_2 ) ;
struct V_22 * V_23 = F_14 ( V_10 ) ;
struct V_24 * V_25 = F_15 ( V_2 ) ;
unsigned int V_27 = F_18 ( V_10 ) ;
if ( V_16 )
goto V_32;
if ( V_25 -> V_33 ) {
unsigned int V_34 = V_25 -> V_35 - V_25 -> V_33 ;
F_23 ( V_25 -> V_11 , V_25 -> V_36 ,
V_34 , V_25 -> V_33 , 0 ) ;
V_25 -> V_37 = V_25 -> V_33 ;
} else
V_25 -> V_37 = 0 ;
if ( V_2 -> V_5 )
memcpy ( V_2 -> V_5 , V_25 -> V_23 , V_27 ) ;
if ( V_25 -> V_38 && V_23 -> V_28 . V_29 . V_39 )
V_16 = F_11 ( V_21 ) ;
V_32:
F_24 ( & V_25 -> V_40 ) ;
return V_16 ;
}
static int F_25 ( struct V_15 * V_2 , unsigned int V_35 ,
unsigned int V_38 )
{
struct V_9 * V_10 = F_13 ( V_2 ) ;
struct V_24 * V_25 = F_15 ( V_2 ) ;
struct V_12 * V_13 ;
unsigned int V_26 =
F_16 ( F_17 ( V_10 ) ) ;
unsigned int V_41 ;
T_2 V_42 ;
T_3 V_14 ;
int V_16 ;
V_14 = ( T_3 ) V_25 -> V_37 + ( T_3 ) V_35 ;
if ( ! V_38 && ( V_14 <= V_26 ) ) {
F_23 ( V_25 -> V_11 + V_25 -> V_37 , V_2 -> V_36 ,
0 , V_35 , 0 ) ;
V_25 -> V_37 += V_35 ;
return 0 ;
}
V_25 -> V_36 = V_2 -> V_36 ;
V_25 -> V_35 = V_35 ;
V_25 -> V_38 = V_38 ;
V_25 -> V_33 = V_38 ? 0 : V_14 & ( V_26 - 1 ) ;
V_25 -> V_43 = V_14 - V_25 -> V_33 ;
if ( ! V_38 && ! V_25 -> V_33 ) {
V_25 -> V_43 -= V_26 ;
V_25 -> V_33 = V_26 ;
}
F_26 ( & V_25 -> V_44 , V_25 -> V_23 , sizeof( V_25 -> V_23 ) ) ;
V_13 = NULL ;
if ( V_25 -> V_37 && V_35 ) {
V_42 = V_2 -> V_45 . V_46 & V_47 ?
V_17 : V_48 ;
V_41 = F_27 ( V_2 -> V_36 ) + 1 ;
V_16 = F_28 ( & V_25 -> V_40 , V_41 , V_42 ) ;
if ( V_16 )
return V_16 ;
F_26 ( & V_25 -> V_49 , V_25 -> V_11 , V_25 -> V_37 ) ;
V_13 = F_29 ( & V_25 -> V_40 , & V_25 -> V_49 ) ;
V_13 = F_29 ( & V_25 -> V_40 , V_2 -> V_36 ) ;
F_30 ( V_13 ) ;
V_13 = V_25 -> V_40 . V_50 ;
} else if ( V_25 -> V_37 ) {
F_26 ( & V_25 -> V_49 , V_25 -> V_11 , V_25 -> V_37 ) ;
V_13 = & V_25 -> V_49 ;
} else if ( V_35 ) {
V_13 = V_2 -> V_36 ;
}
V_25 -> V_51 += ( V_25 -> V_43 << 3 ) ;
memset ( & V_25 -> V_52 , 0 , sizeof( V_25 -> V_52 ) ) ;
F_31 ( & V_25 -> V_52 . V_53 ) ;
V_25 -> V_52 . V_54 = V_55 ;
V_25 -> V_52 . V_28 . V_29 . type = V_25 -> type ;
V_25 -> V_52 . V_28 . V_29 . V_23 = & V_25 -> V_44 ;
V_25 -> V_52 . V_28 . V_29 . V_56 = sizeof( V_25 -> V_23 ) ;
V_25 -> V_52 . V_28 . V_29 . V_36 = V_13 ;
V_25 -> V_52 . V_28 . V_29 . V_57 = V_25 -> V_43 ;
V_25 -> V_52 . V_28 . V_29 . V_38 = V_25 -> V_38 ;
V_25 -> V_52 . V_28 . V_29 . V_51 = V_25 -> V_51 ;
V_25 -> V_58 = 0 ;
V_16 = F_32 ( & V_2 -> V_45 , & V_25 -> V_52 ) ;
return V_16 ;
}
static int F_33 ( struct V_15 * V_2 )
{
struct V_9 * V_10 = F_13 ( V_2 ) ;
struct V_22 * V_23 = F_14 ( V_10 ) ;
struct V_24 * V_25 = F_15 ( V_2 ) ;
struct V_59 * V_60 =
V_59 ( F_17 ( V_10 ) ) ;
unsigned int V_26 =
F_16 ( F_17 ( V_10 ) ) ;
memset ( V_25 , 0 , sizeof( * V_25 ) ) ;
memcpy ( V_25 -> V_23 , V_60 -> V_61 , sizeof( V_25 -> V_23 ) ) ;
V_25 -> type = V_60 -> type ;
V_25 -> V_58 = 1 ;
if ( V_23 -> V_28 . V_29 . V_39 ) {
memcpy ( V_25 -> V_11 , V_23 -> V_28 . V_29 . V_62 , V_26 ) ;
V_25 -> V_37 = V_26 ;
}
return 0 ;
}
static int F_34 ( struct V_15 * V_2 )
{
return F_25 ( V_2 , V_2 -> V_35 , 0 ) ;
}
static int F_35 ( struct V_15 * V_2 )
{
return F_25 ( V_2 , 0 , 1 ) ;
}
static int F_36 ( struct V_15 * V_2 )
{
return F_25 ( V_2 , V_2 -> V_35 , 1 ) ;
}
static int F_37 ( struct V_15 * V_2 )
{
int V_16 ;
V_16 = F_33 ( V_2 ) ;
if ( V_16 )
return V_16 ;
return F_36 ( V_2 ) ;
}
static int F_38 ( struct V_9 * V_10 , const T_1 * V_63 ,
unsigned int V_39 )
{
struct V_22 * V_23 = F_39 ( F_17 ( V_10 ) ) ;
struct V_12 V_13 ;
unsigned int V_26 =
F_16 ( F_17 ( V_10 ) ) ;
unsigned int V_27 = F_18 ( V_10 ) ;
int V_64 , V_16 ;
V_23 -> V_28 . V_29 . V_39 = 0 ;
memset ( V_23 -> V_28 . V_29 . V_63 , 0 , sizeof( V_23 -> V_28 . V_29 . V_63 ) ) ;
if ( V_39 > V_26 ) {
F_26 ( & V_13 , V_63 , V_39 ) ;
V_16 = F_3 ( V_10 , V_23 -> V_28 . V_29 . V_63 , & V_13 , V_39 ) ;
if ( V_16 ) {
F_40 ( V_10 , V_65 ) ;
return - V_66 ;
}
V_39 = V_27 ;
} else
memcpy ( V_23 -> V_28 . V_29 . V_63 , V_63 , V_39 ) ;
for ( V_64 = 0 ; V_64 < V_26 ; V_64 ++ ) {
V_23 -> V_28 . V_29 . V_62 [ V_64 ] = V_23 -> V_28 . V_29 . V_63 [ V_64 ] ^ 0x36 ;
V_23 -> V_28 . V_29 . V_30 [ V_64 ] = V_23 -> V_28 . V_29 . V_63 [ V_64 ] ^ 0x5c ;
}
V_23 -> V_28 . V_29 . V_39 = V_39 ;
return 0 ;
}
static int F_41 ( struct V_67 * V_10 )
{
struct V_22 * V_23 = F_39 ( V_10 ) ;
struct V_9 * V_68 = F_42 ( V_10 ) ;
V_23 -> F_2 = F_22 ;
V_23 -> V_28 . V_29 . V_39 = 0 ;
F_43 ( V_68 , sizeof( struct V_24 ) ) ;
return 0 ;
}
static void F_44 ( struct V_67 * V_10 )
{
}
static int F_45 ( struct V_67 * V_10 )
{
struct V_22 * V_23 = F_39 ( V_10 ) ;
struct V_59 * V_60 = V_59 ( V_10 ) ;
struct V_9 * V_31 ;
V_31 = F_46 ( V_60 -> V_69 ,
V_70 , 0 ) ;
if ( F_47 ( V_31 ) ) {
F_48 ( L_1 ,
V_60 -> V_69 ) ;
return F_49 ( V_31 ) ;
}
V_23 -> V_28 . V_29 . V_31 = V_31 ;
return F_41 ( V_10 ) ;
}
static void F_50 ( struct V_67 * V_10 )
{
struct V_22 * V_23 = F_39 ( V_10 ) ;
if ( V_23 -> V_28 . V_29 . V_31 )
F_51 ( V_23 -> V_28 . V_29 . V_31 ) ;
F_44 ( V_10 ) ;
}
static int F_52 ( struct V_71 * V_72 ,
const struct V_73 * V_74 ,
const struct V_59 * V_75 )
{
struct V_59 * V_76 ;
struct V_77 * V_60 ;
struct V_78 * V_79 ;
struct V_80 * V_45 ;
int V_16 ;
V_76 = F_53 ( sizeof( * V_76 ) , V_17 ) ;
if ( ! V_76 )
return - V_18 ;
* V_76 = * V_75 ;
F_31 ( & V_76 -> V_53 ) ;
strncpy ( V_76 -> V_69 , V_74 -> V_81 , V_82 ) ;
V_60 = & V_76 -> V_60 ;
V_60 -> V_83 = F_38 ;
V_79 = & V_60 -> V_79 ;
V_45 = & V_79 -> V_45 ;
snprintf ( V_45 -> V_84 , V_82 , L_2 , V_74 -> V_81 ) ;
snprintf ( V_45 -> V_85 , V_82 , L_3 ,
V_74 -> V_86 ) ;
V_45 -> V_87 = F_45 ;
V_45 -> V_88 = F_50 ;
V_16 = F_54 ( V_60 ) ;
if ( V_16 ) {
F_55 ( L_4 ,
V_45 -> V_84 , V_16 ) ;
F_56 ( V_76 ) ;
return V_16 ;
}
F_57 ( & V_76 -> V_53 , V_72 ) ;
return V_16 ;
}
static int F_58 ( struct V_71 * V_72 ,
const struct V_73 * V_74 )
{
struct V_59 * V_76 ;
struct V_77 * V_60 ;
struct V_78 * V_79 ;
struct V_80 * V_45 ;
int V_16 ;
V_76 = F_53 ( sizeof( * V_76 ) , V_17 ) ;
if ( ! V_76 )
return - V_18 ;
F_31 ( & V_76 -> V_53 ) ;
V_76 -> V_61 = V_74 -> V_61 ;
V_76 -> type = V_74 -> type ;
V_60 = & V_76 -> V_60 ;
V_60 -> V_61 = F_33 ;
V_60 -> V_89 = F_34 ;
V_60 -> V_38 = F_35 ;
V_60 -> V_90 = F_36 ;
V_60 -> V_91 = F_37 ;
V_79 = & V_60 -> V_79 ;
V_79 -> V_92 = V_74 -> V_27 ;
V_45 = & V_79 -> V_45 ;
snprintf ( V_45 -> V_84 , V_82 , L_5 , V_74 -> V_81 ) ;
snprintf ( V_45 -> V_85 , V_82 , L_5 ,
V_74 -> V_86 ) ;
V_45 -> V_93 = V_70 | V_94 |
V_95 |
V_96 ;
V_45 -> V_97 = V_74 -> V_26 ;
V_45 -> V_98 = sizeof( struct V_22 ) ;
V_45 -> V_99 = V_100 ;
V_45 -> V_101 = & V_102 ;
V_45 -> V_87 = F_41 ;
V_45 -> V_88 = F_44 ;
V_45 -> V_103 = V_104 ;
V_16 = F_54 ( V_60 ) ;
if ( V_16 ) {
F_55 ( L_4 ,
V_45 -> V_84 , V_16 ) ;
F_56 ( V_76 ) ;
return V_16 ;
}
F_57 ( & V_76 -> V_53 , V_72 ) ;
V_16 = F_52 ( V_72 , V_74 , V_76 ) ;
return V_16 ;
}
int F_59 ( struct V_71 * V_72 )
{
int V_64 , V_16 ;
for ( V_64 = 0 ; V_64 < F_20 ( V_105 ) ; V_64 ++ ) {
V_16 = F_58 ( V_72 , & V_105 [ V_64 ] ) ;
if ( V_16 )
return V_16 ;
}
return 0 ;
}
