static int F_1 ( struct V_1 * V_2 , int V_3 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_6 * V_7 = F_3 ( V_5 ) ;
struct V_8 * V_9 = F_4 ( V_5 ) ;
unsigned int V_10 = F_5 ( V_7 ) ;
if ( V_3 )
goto V_11;
if ( V_9 -> V_12 ) {
unsigned int V_13 = V_9 -> V_14 - V_9 -> V_12 ;
F_6 ( V_9 -> V_15 , V_9 -> V_16 ,
V_13 , V_9 -> V_12 , 0 ) ;
V_9 -> V_17 = V_9 -> V_12 ;
} else {
V_9 -> V_17 = 0 ;
}
if ( V_5 -> V_18 )
memcpy ( V_5 -> V_18 , V_9 -> V_19 , V_10 ) ;
V_11:
F_7 ( & V_9 -> V_20 ) ;
return V_3 ;
}
static int F_8 ( struct V_4 * V_5 , unsigned int V_14 ,
unsigned int V_21 )
{
struct V_6 * V_7 = F_3 ( V_5 ) ;
struct V_22 * V_19 = F_9 ( V_7 ) ;
struct V_8 * V_9 = F_4 ( V_5 ) ;
struct V_23 * V_24 ;
unsigned int V_25 =
F_10 ( F_11 ( V_7 ) ) ;
unsigned int V_26 ;
T_1 V_27 ;
T_2 V_28 ;
int V_3 ;
V_28 = ( T_2 ) V_9 -> V_17 + ( T_2 ) V_14 ;
if ( ! V_21 && ( V_28 <= V_25 ) ) {
F_6 ( V_9 -> V_15 + V_9 -> V_17 , V_5 -> V_16 ,
0 , V_14 , 0 ) ;
V_9 -> V_17 += V_14 ;
return 0 ;
}
V_9 -> V_16 = V_5 -> V_16 ;
V_9 -> V_14 = V_14 ;
V_9 -> V_21 = V_21 ;
V_9 -> V_12 = V_21 ? 0 : V_28 & ( V_25 - 1 ) ;
V_9 -> V_29 = V_28 - V_9 -> V_12 ;
if ( ! V_21 && ! V_9 -> V_12 ) {
V_9 -> V_29 -= V_25 ;
V_9 -> V_12 = V_25 ;
}
F_12 ( & V_9 -> V_30 , V_9 -> V_19 , sizeof( V_9 -> V_19 ) ) ;
V_24 = NULL ;
if ( V_9 -> V_17 && V_14 ) {
V_27 = V_5 -> V_31 . V_32 & V_33 ?
V_34 : V_35 ;
V_26 = F_13 ( V_5 -> V_16 ) + 1 ;
V_3 = F_14 ( & V_9 -> V_20 , V_26 , V_27 ) ;
if ( V_3 )
return V_3 ;
F_12 ( & V_9 -> V_36 , V_9 -> V_15 , V_9 -> V_17 ) ;
V_24 = F_15 ( & V_9 -> V_20 , & V_9 -> V_36 ) ;
if ( ! V_24 ) {
V_3 = - V_37 ;
goto V_11;
}
V_24 = F_15 ( & V_9 -> V_20 , V_5 -> V_16 ) ;
if ( ! V_24 ) {
V_3 = - V_37 ;
goto V_11;
}
F_16 ( V_24 ) ;
V_24 = V_9 -> V_20 . V_38 ;
} else if ( V_9 -> V_17 ) {
F_12 ( & V_9 -> V_36 , V_9 -> V_15 , V_9 -> V_17 ) ;
V_24 = & V_9 -> V_36 ;
} else if ( V_14 ) {
V_24 = V_5 -> V_16 ;
}
V_9 -> V_39 += ( V_9 -> V_29 << 3 ) ;
memset ( & V_9 -> V_40 , 0 , sizeof( V_9 -> V_40 ) ) ;
F_17 ( & V_9 -> V_40 . V_41 ) ;
V_9 -> V_40 . V_42 = V_43 ;
V_9 -> V_40 . V_44 . V_45 . type = V_9 -> type ;
V_9 -> V_40 . V_44 . V_45 . V_19 = & V_9 -> V_30 ;
V_9 -> V_40 . V_44 . V_45 . V_46 = sizeof( V_9 -> V_19 ) ;
V_9 -> V_40 . V_44 . V_45 . V_16 = V_24 ;
V_9 -> V_40 . V_44 . V_45 . V_47 = V_9 -> V_29 ;
V_9 -> V_40 . V_44 . V_45 . V_48 = V_19 -> V_44 . V_45 . V_49 ?
& V_19 -> V_44 . V_45 . V_50 : NULL ;
V_9 -> V_40 . V_44 . V_45 . V_51 = V_19 -> V_44 . V_45 . V_49 ?
V_19 -> V_44 . V_45 . V_52 : 0 ;
V_9 -> V_40 . V_44 . V_45 . V_53 = V_9 -> V_53 ;
V_9 -> V_40 . V_44 . V_45 . V_21 = V_9 -> V_21 ;
V_9 -> V_40 . V_44 . V_45 . V_39 = V_9 -> V_39 ;
V_9 -> V_53 = 0 ;
V_3 = F_18 ( & V_5 -> V_31 , & V_9 -> V_40 ) ;
return V_3 ;
V_11:
F_7 ( & V_9 -> V_20 ) ;
return V_3 ;
}
static int F_19 ( struct V_4 * V_5 )
{
struct V_6 * V_7 = F_3 ( V_5 ) ;
struct V_22 * V_19 = F_9 ( V_7 ) ;
struct V_8 * V_9 = F_4 ( V_5 ) ;
struct V_54 * V_55 =
V_54 ( F_11 ( V_7 ) ) ;
unsigned int V_25 =
F_10 ( F_11 ( V_7 ) ) ;
memset ( V_9 , 0 , sizeof( * V_9 ) ) ;
V_9 -> type = V_55 -> type ;
V_9 -> V_53 = 1 ;
if ( V_19 -> V_44 . V_45 . V_49 ) {
memcpy ( V_9 -> V_15 , V_19 -> V_44 . V_45 . V_56 , V_25 ) ;
V_9 -> V_17 = V_25 ;
}
return 0 ;
}
static int F_20 ( struct V_4 * V_5 )
{
return F_8 ( V_5 , V_5 -> V_14 , 0 ) ;
}
static int F_21 ( struct V_4 * V_5 )
{
return F_8 ( V_5 , 0 , 1 ) ;
}
static int F_22 ( struct V_4 * V_5 )
{
return F_8 ( V_5 , V_5 -> V_14 , 1 ) ;
}
static int F_23 ( struct V_4 * V_5 )
{
int V_3 ;
V_3 = F_19 ( V_5 ) ;
if ( V_3 )
return V_3 ;
return F_22 ( V_5 ) ;
}
static int F_24 ( struct V_6 * V_7 , const T_3 * V_57 ,
unsigned int V_49 )
{
struct V_22 * V_19 = F_25 ( F_11 ( V_7 ) ) ;
struct V_58 * V_59 = V_19 -> V_44 . V_45 . V_60 ;
F_26 ( V_61 , V_59 ) ;
unsigned int V_25 = F_27 ( V_59 ) ;
unsigned int V_10 = F_28 ( V_59 ) ;
int V_62 , V_3 ;
V_19 -> V_44 . V_45 . V_49 = 0 ;
memset ( V_19 -> V_44 . V_45 . V_57 , 0 , sizeof( V_19 -> V_44 . V_45 . V_57 ) ) ;
if ( V_49 > V_25 ) {
V_61 -> V_7 = V_59 ;
V_61 -> V_32 = F_29 ( V_7 ) &
V_33 ;
V_3 = F_30 ( V_61 , V_57 , V_49 ,
V_19 -> V_44 . V_45 . V_57 ) ;
if ( V_3 ) {
F_31 ( V_7 , V_63 ) ;
return - V_37 ;
}
V_49 = V_10 ;
} else {
memcpy ( V_19 -> V_44 . V_45 . V_57 , V_57 , V_49 ) ;
}
for ( V_62 = 0 ; V_62 < V_25 ; V_62 ++ ) {
V_19 -> V_44 . V_45 . V_56 [ V_62 ] = V_19 -> V_44 . V_45 . V_57 [ V_62 ] ^ 0x36 ;
V_19 -> V_44 . V_45 . V_48 [ V_62 ] = V_19 -> V_44 . V_45 . V_57 [ V_62 ] ^ 0x5c ;
}
F_12 ( & V_19 -> V_44 . V_45 . V_50 , V_19 -> V_44 . V_45 . V_48 , V_25 ) ;
V_19 -> V_44 . V_45 . V_52 = V_25 ;
V_19 -> V_44 . V_45 . V_49 = V_49 ;
return 0 ;
}
static int F_32 ( struct V_64 * V_7 )
{
struct V_22 * V_19 = F_25 ( V_7 ) ;
struct V_6 * V_65 = F_33 ( V_7 ) ;
V_19 -> V_66 = F_1 ;
V_19 -> V_44 . V_45 . V_49 = 0 ;
F_34 ( V_65 , sizeof( struct V_8 ) ) ;
return 0 ;
}
static void F_35 ( struct V_64 * V_7 )
{
}
static int F_36 ( struct V_64 * V_7 )
{
struct V_22 * V_19 = F_25 ( V_7 ) ;
struct V_54 * V_55 = V_54 ( V_7 ) ;
struct V_58 * V_60 ;
V_60 = F_37 ( V_55 -> V_67 , 0 , 0 ) ;
if ( F_38 ( V_60 ) ) {
F_39 ( L_1 ,
V_55 -> V_67 ) ;
return F_40 ( V_60 ) ;
}
V_19 -> V_44 . V_45 . V_60 = V_60 ;
return F_32 ( V_7 ) ;
}
static void F_41 ( struct V_64 * V_7 )
{
struct V_22 * V_19 = F_25 ( V_7 ) ;
if ( V_19 -> V_44 . V_45 . V_60 )
F_42 ( V_19 -> V_44 . V_45 . V_60 ) ;
F_35 ( V_7 ) ;
}
static int F_43 ( struct V_68 * V_69 ,
const struct V_70 * V_71 ,
const struct V_54 * V_72 )
{
struct V_54 * V_73 ;
struct V_74 * V_55 ;
struct V_75 * V_76 ;
struct V_77 * V_31 ;
int V_3 ;
V_73 = F_44 ( sizeof( * V_73 ) , V_34 ) ;
if ( ! V_73 )
return - V_78 ;
* V_73 = * V_72 ;
F_17 ( & V_73 -> V_41 ) ;
strncpy ( V_73 -> V_67 , V_71 -> V_79 , V_80 ) ;
V_55 = & V_73 -> V_55 ;
V_55 -> V_81 = F_24 ;
V_76 = & V_55 -> V_76 ;
V_31 = & V_76 -> V_31 ;
snprintf ( V_31 -> V_82 , V_80 , L_2 , V_71 -> V_79 ) ;
snprintf ( V_31 -> V_83 , V_80 , L_3 ,
V_71 -> V_84 ) ;
V_31 -> V_85 = F_36 ;
V_31 -> V_86 = F_41 ;
V_3 = F_45 ( V_55 ) ;
if ( V_3 ) {
F_46 ( L_4 ,
V_31 -> V_82 , V_3 ) ;
F_47 ( V_73 ) ;
return V_3 ;
}
F_48 ( & V_73 -> V_41 , V_69 ) ;
return V_3 ;
}
static int F_49 ( struct V_68 * V_69 ,
const struct V_70 * V_71 )
{
struct V_54 * V_73 ;
struct V_74 * V_55 ;
struct V_75 * V_76 ;
struct V_77 * V_31 ;
int V_3 ;
V_73 = F_44 ( sizeof( * V_73 ) , V_34 ) ;
if ( ! V_73 )
return - V_78 ;
F_17 ( & V_73 -> V_41 ) ;
V_73 -> type = V_71 -> type ;
V_55 = & V_73 -> V_55 ;
V_55 -> V_87 = F_19 ;
V_55 -> V_88 = F_20 ;
V_55 -> V_21 = F_21 ;
V_55 -> V_89 = F_22 ;
V_55 -> V_90 = F_23 ;
V_76 = & V_55 -> V_76 ;
V_76 -> V_91 = V_71 -> V_10 ;
V_31 = & V_76 -> V_31 ;
snprintf ( V_31 -> V_82 , V_80 , L_5 , V_71 -> V_79 ) ;
snprintf ( V_31 -> V_83 , V_80 , L_5 ,
V_71 -> V_84 ) ;
V_31 -> V_92 = V_93 | V_94 |
V_95 |
V_96 ;
V_31 -> V_97 = V_71 -> V_25 ;
V_31 -> V_98 = sizeof( struct V_22 ) ;
V_31 -> V_99 = V_100 ;
V_31 -> V_101 = & V_102 ;
V_31 -> V_85 = F_32 ;
V_31 -> V_86 = F_35 ;
V_31 -> V_103 = V_104 ;
V_3 = F_45 ( V_55 ) ;
if ( V_3 ) {
F_46 ( L_4 ,
V_31 -> V_82 , V_3 ) ;
F_47 ( V_73 ) ;
return V_3 ;
}
F_48 ( & V_73 -> V_41 , V_69 ) ;
V_3 = F_43 ( V_69 , V_71 , V_73 ) ;
return V_3 ;
}
int F_50 ( struct V_68 * V_69 )
{
int V_62 , V_3 ;
for ( V_62 = 0 ; V_62 < F_51 ( V_105 ) ; V_62 ++ ) {
V_3 = F_49 ( V_69 , & V_105 [ V_62 ] ) ;
if ( V_3 )
return V_3 ;
}
return 0 ;
}
