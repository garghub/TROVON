static void
F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * * V_6 , unsigned int * V_7 )
{
struct V_5 * V_8 = V_6 ? * V_6 : NULL ;
unsigned int V_9 = V_7 ? * V_7 : 0 ;
T_1 V_10 = 0UL ;
unsigned int V_11 = 0 ;
int V_12 ;
memcpy ( V_2 , & V_4 -> V_13 , sizeof( struct V_14 ) ) ;
if ( V_8 ) {
V_10 = F_2 ( V_8 ) ;
V_11 = F_3 ( V_8 ) ;
}
for ( V_12 = 0 ; V_12 < V_15 ; V_12 ++ ) {
if ( V_8 ) {
V_2 -> V_10 [ V_12 ] = F_4 ( V_10 + V_9 ) ;
V_9 += V_16 ;
if ( V_9 == ( V_11 + V_8 -> V_9 ) ) {
V_9 = 0 ;
V_8 = F_5 ( V_8 ) ;
if ( V_8 ) {
V_10 = F_2 ( V_8 ) ;
V_11 = F_3 ( V_8 ) ;
}
}
} else {
V_2 -> V_10 [ V_12 ] = 0ULL ;
}
}
if ( V_6 ) {
* V_6 = V_8 ;
* V_7 = V_9 ;
}
if ( V_9 == V_11 ) {
V_9 = 0 ;
if ( V_8 ) {
V_8 = F_5 ( V_8 ) ;
if ( V_8 )
V_10 = F_2 ( V_8 ) ;
}
}
V_2 -> V_10 [ V_12 ] = V_8 ? F_4 ( V_10 + V_9 ) : 0ULL ;
}
static struct V_17 *
F_6 ( struct V_18 * V_19 , struct V_20 * V_21 ,
unsigned int V_22 , unsigned int V_23 , unsigned int V_24 )
{
struct V_25 * V_26 ;
struct V_27 * V_28 ;
unsigned int V_29 = ( V_22 << V_30 ) + V_21 -> V_31 ;
unsigned int V_32 = V_23 << V_30 ;
unsigned int V_33 = F_7 ( sizeof( struct V_25 ) +
sizeof( struct V_27 ) + V_32 , 16 ) ;
struct V_17 * V_34 ;
V_34 = F_8 ( V_33 , V_35 ) ;
if ( ! V_34 )
return NULL ;
V_26 = (struct V_25 * ) F_9 ( V_34 , V_33 ) ;
F_10 ( V_26 , V_33 , 0 , V_24 ) ;
V_26 -> V_36 . V_37 = F_11 ( F_12 ( V_38 ) |
F_13 ( 0 ) ) ;
V_26 -> V_39 = F_11 ( F_14 ( V_40 ) |
F_15 ( 0 ) |
F_16 ( 1 ) ) ;
V_26 -> V_32 = F_11 ( F_17 ( V_32 >> 5 ) ) ;
V_26 -> V_41 = F_11 ( F_18 ( V_29 >> 5 ) ) ;
V_26 -> V_42 = F_11 ( F_19 ( V_33 - sizeof( V_26 -> V_36 ) , 16 ) ) ;
V_28 = (struct V_27 * ) ( V_26 + 1 ) ;
V_28 -> V_43 = F_11 ( F_14 ( V_44 ) ) ;
V_28 -> V_11 = F_11 ( V_32 ) ;
return V_34 ;
}
static int
F_20 ( struct V_20 * V_21 , struct V_45 * V_46 ,
struct V_3 * V_4 , unsigned int V_22 ,
unsigned int V_23 , struct V_5 * * V_6 ,
unsigned int * V_7 )
{
struct V_18 * V_19 = V_46 -> V_47 . V_19 ;
struct V_17 * V_34 ;
struct V_25 * V_26 ;
struct V_27 * V_28 ;
struct V_1 * V_2 ;
unsigned int V_12 ;
V_34 = F_6 ( V_19 , V_21 , V_22 , V_23 , V_46 -> V_24 ) ;
if ( ! V_34 )
return - V_48 ;
V_26 = (struct V_25 * ) V_34 -> V_49 ;
V_28 = (struct V_27 * ) ( V_26 + 1 ) ;
V_2 = (struct V_1 * ) ( V_28 + 1 ) ;
for ( V_12 = 0 ; V_12 < V_23 ; V_12 ++ , V_2 ++ )
F_1 ( V_2 , V_4 , V_6 , V_7 ) ;
F_21 ( & V_46 -> V_50 , V_34 ) ;
return 0 ;
}
static int
F_22 ( struct V_20 * V_21 , struct V_45 * V_46 ,
struct V_3 * V_4 )
{
unsigned int V_51 = V_4 -> V_22 ;
unsigned int V_23 = V_4 -> V_23 ;
unsigned int V_12 , V_52 ;
struct V_5 * V_8 = V_4 -> V_53 ;
unsigned int V_9 = 0 ;
int V_54 = 0 ;
for ( V_12 = 0 ; V_12 < V_23 ; V_12 += V_52 , V_51 += V_52 ) {
V_52 = V_23 - V_12 ;
if ( V_52 > V_55 )
V_52 = V_55 ;
V_54 = F_20 ( V_21 , V_46 , V_4 , V_51 , V_52 ,
& V_8 , & V_9 ) ;
if ( V_54 < 0 )
break;
}
return V_54 ;
}
static int F_23 ( struct V_5 * V_8 ,
unsigned int V_56 )
{
unsigned int V_57 = V_56 - 1 ;
unsigned int V_12 ;
for ( V_12 = 0 ; V_12 < V_56 ; V_12 ++ , V_8 = F_5 ( V_8 ) ) {
unsigned int V_11 = V_8 -> V_58 + V_8 -> V_9 ;
if ( ( V_8 -> V_9 & 0x3 ) || ( V_12 && V_8 -> V_9 ) ||
( ( V_12 != V_57 ) && ( V_11 != V_16 ) ) ) {
return - V_59 ;
}
}
return 0 ;
}
static int
F_24 ( struct V_45 * V_46 , struct V_3 * V_4 ,
unsigned int V_60 )
{
struct V_18 * V_19 = V_46 -> V_47 . V_19 ;
struct V_20 * V_21 = F_25 ( V_19 ) ;
struct V_5 * V_53 = V_4 -> V_53 ;
unsigned int V_61 = V_4 -> V_56 ;
unsigned int V_62 = V_53 -> V_9 ;
int V_54 ;
if ( ( V_60 < V_63 ) || ( ! V_61 ) ) {
F_26 ( L_1 ,
V_21 , V_21 -> V_64 . V_65 ,
V_60 , V_4 -> V_56 ) ;
return - V_59 ;
}
if ( F_23 ( V_53 , V_61 ) < 0 )
return - V_59 ;
V_4 -> V_66 = ( V_60 + V_53 -> V_9 +
( 1 << V_67 ) - 1 ) >> V_67 ;
V_54 = F_27 ( V_21 , V_4 -> V_66 , 0 , & V_4 -> V_22 ,
& V_4 -> V_68 , 0 ) ;
if ( V_54 < 0 )
return V_54 ;
V_4 -> V_23 = V_54 ;
V_53 -> V_9 = 0 ;
V_54 = F_28 ( & V_21 -> V_69 -> V_70 , V_53 , V_61 , V_71 ) ;
V_53 -> V_9 = V_62 ;
if ( ! V_54 ) {
F_29 ( L_2 ,
V_72 , 0 , V_60 , V_61 ) ;
goto V_73;
}
F_30 ( V_21 , V_4 -> V_68 , V_46 -> V_24 , V_53 -> V_9 ,
V_60 , & V_4 -> V_13 ) ;
V_54 = F_22 ( V_21 , V_46 , V_4 ) ;
if ( V_54 < 0 ) {
F_31 ( & V_46 -> V_50 ) ;
F_32 ( & V_21 -> V_69 -> V_70 , V_53 , V_61 , V_71 ) ;
goto V_73;
}
return 0 ;
V_73:
F_33 ( V_21 , V_4 -> V_22 ) ;
return - V_59 ;
}
void
F_34 ( struct V_74 * V_75 , struct V_76 * V_39 ,
struct V_77 * V_78 )
{
struct V_45 * V_46 = V_75 -> V_79 ;
struct V_18 * V_19 = V_46 -> V_47 . V_19 ;
struct V_80 * V_81 = F_35 ( V_39 ) ;
struct V_3 * V_4 = & V_81 -> V_4 ;
int V_54 = - V_59 ;
if ( ( ! V_81 -> V_82 ) ||
( ! F_36 ( V_83 , & V_46 -> V_47 . V_84 ) ) )
goto V_85;
V_81 -> V_82 = false ;
V_4 -> V_53 = V_39 -> V_86 . V_87 ;
V_4 -> V_56 = V_39 -> V_86 . V_88 ;
V_54 = F_24 ( V_46 , V_4 , V_39 -> V_86 . V_89 ) ;
if ( V_54 < 0 ) {
F_29 ( L_3 ,
V_46 , V_39 , V_39 -> V_86 . V_89 , V_4 -> V_56 ) ;
V_4 -> V_53 = NULL ;
V_4 -> V_56 = 0 ;
} else {
V_81 -> V_90 = true ;
}
V_85:
F_26 ( L_4 , V_19 , V_39 , V_4 -> V_68 ) ;
V_78 -> V_91 = V_4 -> V_68 ;
}
void F_37 ( struct V_74 * V_75 , struct V_76 * V_39 )
{
struct V_80 * V_81 = F_35 ( V_39 ) ;
if ( V_81 -> V_90 ) {
struct V_3 * V_4 = & V_81 -> V_4 ;
if ( V_4 -> V_53 ) {
struct V_45 * V_46 = V_75 -> V_79 ;
struct V_18 * V_19 = V_46 -> V_47 . V_19 ;
struct V_20 * V_21 = F_25 ( V_19 ) ;
F_33 ( V_21 , V_4 -> V_22 ) ;
F_32 ( & V_21 -> V_69 -> V_70 , V_4 -> V_53 ,
V_4 -> V_56 , V_71 ) ;
} else {
F_38 ( F_39 ( & V_81 -> V_8 ) ) ;
}
V_81 -> V_90 = false ;
}
}
int F_40 ( struct V_18 * V_19 )
{
struct V_92 * V_93 = & V_19 -> V_93 ;
struct V_94 * V_95 = V_19 -> V_93 . V_96 [ 0 ] ;
struct V_97 V_64 ;
unsigned int V_98 ;
int V_54 , V_12 ;
if ( ! V_93 -> V_99 -> V_100 . V_101 ) {
F_41 ( L_5 , V_95 -> V_102 ) ;
return - V_103 ;
}
V_98 = V_93 -> V_99 -> V_100 . V_101 >> V_30 ;
memset ( & V_64 , 0 , sizeof( struct V_97 ) ) ;
for ( V_12 = 0 ; V_12 < 4 ; V_12 ++ )
V_64 . V_104 [ V_12 ] = ( V_93 -> V_105 >> ( V_12 << 3 ) )
& 0xF ;
F_42 ( V_93 -> V_106 , & V_64 ) ;
V_54 = F_43 ( V_93 -> V_107 , V_19 -> V_93 . V_96 [ 0 ] ,
V_19 -> V_93 . V_69 , & V_19 -> V_93 , & V_64 ,
V_98 , V_93 -> V_108 ,
V_93 -> V_99 -> V_100 . V_109 , 2 ) ;
if ( V_54 >= 0 ) {
struct V_20 * V_21 = (struct V_20 * ) ( * V_93 -> V_107 ) ;
if ( ( V_21 -> V_64 . V_65 < V_110 ) &&
( V_21 -> V_98 >= 1024 ) )
F_44 ( V_111 , & V_19 -> V_84 ) ;
V_54 = 0 ;
}
return V_54 ;
}
