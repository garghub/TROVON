static void F_1 ( void * V_1 , const void * V_2 , T_1 V_3 )
__dm_written_to_disk( V_2 )
{
memcpy ( V_1 , V_2 , V_3 ) ;
F_2 ( V_2 ) ;
}
static void F_3 ( void * V_4 , T_1 V_5 , unsigned V_6 ,
unsigned V_7 , void * V_8 )
__dm_written_to_disk( V_8 )
{
if ( V_7 < V_6 )
memmove ( V_4 + ( V_5 * ( V_7 + 1 ) ) ,
V_4 + ( V_5 * V_7 ) ,
( V_6 - V_7 ) * V_5 ) ;
F_1 ( V_4 + ( V_5 * V_7 ) , V_8 , V_5 ) ;
}
static int bsearch ( struct V_9 * V_10 , T_2 V_11 , int V_12 )
{
int V_13 = - 1 , V_14 = F_4 ( V_10 -> V_15 . V_16 ) ;
while ( V_14 - V_13 > 1 ) {
int V_17 = V_13 + ( ( V_14 - V_13 ) / 2 ) ;
T_2 V_18 = F_5 ( V_10 -> V_19 [ V_17 ] ) ;
if ( V_18 == V_11 )
return V_17 ;
if ( V_18 < V_11 )
V_13 = V_17 ;
else
V_14 = V_17 ;
}
return V_12 ? V_14 : V_13 ;
}
int F_6 ( struct V_9 * V_10 , T_2 V_11 )
{
return bsearch ( V_10 , V_11 , 0 ) ;
}
void F_7 ( struct V_20 * V_21 , struct V_9 * V_10 ,
struct V_22 * V_23 )
{
unsigned V_24 ;
T_3 V_16 = F_4 ( V_10 -> V_15 . V_16 ) ;
if ( F_4 ( V_10 -> V_15 . V_25 ) & V_26 )
for ( V_24 = 0 ; V_24 < V_16 ; V_24 ++ )
F_8 ( V_21 , F_9 ( V_10 , V_24 ) ) ;
else if ( V_23 -> V_27 )
for ( V_24 = 0 ; V_24 < V_16 ; V_24 ++ )
V_23 -> V_27 ( V_23 -> V_28 , F_10 ( V_10 , V_24 ) ) ;
}
static int F_11 ( T_1 V_29 , struct V_9 * V_30 , unsigned V_7 ,
T_2 V_11 , void * V_31 )
__dm_written_to_disk( V_31 )
{
T_3 V_16 = F_4 ( V_30 -> V_15 . V_16 ) ;
T_4 V_32 = F_12 ( V_11 ) ;
if ( V_7 > V_16 ||
V_7 >= F_4 ( V_30 -> V_15 . V_33 ) ) {
F_13 ( L_1 ) ;
F_2 ( V_31 ) ;
return - V_34 ;
}
F_14 ( & V_32 ) ;
F_3 ( V_30 -> V_19 , sizeof( * V_30 -> V_19 ) , V_16 , V_7 , & V_32 ) ;
F_3 ( F_15 ( V_30 ) , V_29 , V_16 , V_7 , V_31 ) ;
V_30 -> V_15 . V_16 = F_16 ( V_16 + 1 ) ;
return 0 ;
}
static T_3 F_17 ( T_1 V_29 , T_1 V_35 )
{
T_3 V_36 , V_10 ;
T_1 V_5 = sizeof( T_2 ) + V_29 ;
V_35 -= sizeof( struct V_37 ) ;
V_36 = V_35 / V_5 ;
V_10 = V_36 / 3 ;
return 3 * V_10 ;
}
int F_18 ( struct V_38 * V_39 , T_5 * V_40 )
{
int V_41 ;
struct V_42 * V_43 ;
struct V_9 * V_10 ;
T_1 V_35 ;
T_3 V_33 ;
V_41 = F_19 ( V_39 , & V_43 ) ;
if ( V_41 < 0 )
return V_41 ;
V_35 = F_20 ( F_21 ( V_39 -> V_21 ) ) ;
V_33 = F_17 ( V_39 -> V_44 . V_45 , V_35 ) ;
V_10 = F_22 ( V_43 ) ;
memset ( V_10 , 0 , V_35 ) ;
V_10 -> V_15 . V_25 = F_16 ( V_46 ) ;
V_10 -> V_15 . V_16 = F_16 ( 0 ) ;
V_10 -> V_15 . V_33 = F_16 ( V_33 ) ;
V_10 -> V_15 . V_29 = F_16 ( V_39 -> V_44 . V_45 ) ;
* V_40 = F_23 ( V_43 ) ;
return F_24 ( V_39 , V_43 ) ;
}
static int F_25 ( struct V_47 * V_48 , struct V_49 * * V_50 )
{
if ( V_48 -> V_51 < 0 ) {
F_13 ( L_2 ) ;
return - V_52 ;
}
* V_50 = V_48 -> V_53 + V_48 -> V_51 ;
return 0 ;
}
static int F_26 ( struct V_47 * V_48 )
{
return V_48 -> V_51 >= 0 ;
}
static int F_27 ( struct V_47 * V_48 , T_5 V_43 , unsigned V_54 )
{
int V_41 ;
T_3 V_55 ;
if ( V_48 -> V_51 >= V_56 - 1 ) {
F_13 ( L_3 ) ;
return - V_34 ;
}
V_41 = F_28 ( V_48 -> V_21 , V_43 , & V_55 ) ;
if ( V_41 )
return V_41 ;
if ( V_55 > 1 )
F_29 ( V_48 -> V_21 , V_43 ) ;
else {
struct V_49 * V_50 = V_48 -> V_53 + ++ V_48 -> V_51 ;
V_41 = F_30 ( V_48 -> V_21 , V_43 , & V_57 , & V_50 -> V_43 ) ;
if ( V_41 ) {
V_48 -> V_51 -- ;
return V_41 ;
}
V_50 -> V_10 = F_22 ( V_50 -> V_43 ) ;
V_50 -> V_54 = V_54 ;
V_50 -> V_58 = F_4 ( V_50 -> V_10 -> V_15 . V_16 ) ;
V_50 -> V_59 = 0 ;
}
return 0 ;
}
static void F_31 ( struct V_47 * V_48 )
{
struct V_49 * V_50 = V_48 -> V_53 + V_48 -> V_51 -- ;
F_29 ( V_48 -> V_21 , F_23 ( V_50 -> V_43 ) ) ;
F_32 ( V_48 -> V_21 , V_50 -> V_43 ) ;
}
static bool F_33 ( struct V_38 * V_39 , struct V_49 * V_50 )
{
return V_50 -> V_54 < ( V_39 -> V_60 - 1 ) ;
}
int F_34 ( struct V_38 * V_39 , T_5 V_40 )
{
int V_41 ;
struct V_47 * V_48 ;
V_48 = F_35 ( sizeof( * V_48 ) , V_61 ) ;
if ( ! V_48 )
return - V_34 ;
V_48 -> V_21 = V_39 -> V_21 ;
V_48 -> V_51 = - 1 ;
V_41 = F_27 ( V_48 , V_40 , 0 ) ;
if ( V_41 )
goto V_62;
while ( F_26 ( V_48 ) ) {
T_3 V_25 ;
struct V_49 * V_50 ;
T_5 V_43 ;
V_41 = F_25 ( V_48 , & V_50 ) ;
if ( V_41 )
goto V_62;
if ( V_50 -> V_59 >= V_50 -> V_58 ) {
F_31 ( V_48 ) ;
continue;
}
V_25 = F_4 ( V_50 -> V_10 -> V_15 . V_25 ) ;
if ( V_25 & V_26 ) {
V_43 = F_9 ( V_50 -> V_10 , V_50 -> V_59 ) ;
V_50 -> V_59 ++ ;
V_41 = F_27 ( V_48 , V_43 , V_50 -> V_54 ) ;
if ( V_41 )
goto V_62;
} else if ( F_33 ( V_39 , V_50 ) ) {
V_43 = F_9 ( V_50 -> V_10 , V_50 -> V_59 ) ;
V_50 -> V_59 ++ ;
V_41 = F_27 ( V_48 , V_43 , V_50 -> V_54 + 1 ) ;
if ( V_41 )
goto V_62;
} else {
if ( V_39 -> V_44 . V_63 ) {
unsigned V_24 ;
for ( V_24 = 0 ; V_24 < V_50 -> V_58 ; V_24 ++ )
V_39 -> V_44 . V_63 ( V_39 -> V_44 . V_28 ,
F_10 ( V_50 -> V_10 , V_24 ) ) ;
}
V_50 -> V_59 = V_50 -> V_58 ;
}
}
V_62:
F_36 ( V_48 ) ;
return V_41 ;
}
static int F_37 ( struct V_64 * V_48 , T_5 V_65 , T_2 V_11 ,
int (* F_38)( struct V_9 * , T_2 ) ,
T_2 * V_66 , void * V_67 , T_1 V_29 )
{
int V_24 , V_41 ;
T_3 V_25 , V_16 ;
do {
V_41 = F_39 ( V_48 , V_65 ) ;
if ( V_41 < 0 )
return V_41 ;
V_24 = F_38 ( F_40 ( V_48 ) , V_11 ) ;
V_25 = F_4 ( F_40 ( V_48 ) -> V_15 . V_25 ) ;
V_16 = F_4 ( F_40 ( V_48 ) -> V_15 . V_16 ) ;
if ( V_24 < 0 || V_24 >= V_16 )
return - V_68 ;
if ( V_25 & V_26 )
V_65 = F_9 ( F_40 ( V_48 ) , V_24 ) ;
} while ( ! ( V_25 & V_46 ) );
* V_66 = F_5 ( F_40 ( V_48 ) -> V_19 [ V_24 ] ) ;
memcpy ( V_67 , F_10 ( F_40 ( V_48 ) , V_24 ) , V_29 ) ;
return 0 ;
}
int F_41 ( struct V_38 * V_39 , T_5 V_40 ,
T_2 * V_19 , void * V_69 )
{
unsigned V_54 , V_70 = V_39 -> V_60 - 1 ;
int V_41 = - V_68 ;
T_2 V_71 ;
T_4 V_72 ;
struct V_64 V_53 ;
F_42 ( & V_53 , V_39 ) ;
for ( V_54 = 0 ; V_54 < V_39 -> V_60 ; V_54 ++ ) {
T_1 V_45 ;
void * V_73 ;
if ( V_54 == V_70 ) {
V_73 = V_69 ;
V_45 = V_39 -> V_44 . V_45 ;
} else {
V_73 = & V_72 ;
V_45 = sizeof( T_2 ) ;
}
V_41 = F_37 ( & V_53 , V_40 , V_19 [ V_54 ] ,
F_6 , & V_71 ,
V_73 , V_45 ) ;
if ( ! V_41 ) {
if ( V_71 != V_19 [ V_54 ] ) {
F_43 ( & V_53 ) ;
return - V_68 ;
}
} else {
F_43 ( & V_53 ) ;
return V_41 ;
}
V_40 = F_5 ( V_72 ) ;
}
F_43 ( & V_53 ) ;
return V_41 ;
}
static int F_44 ( struct V_74 * V_48 , T_5 V_40 ,
unsigned V_75 , T_2 V_11 )
{
int V_41 ;
T_1 V_45 ;
unsigned V_76 , V_77 ;
struct V_42 * V_78 , * V_79 , * V_80 ;
struct V_9 * V_81 , * V_82 , * V_83 ;
T_4 V_84 ;
V_78 = F_45 ( V_48 ) ;
V_41 = F_19 ( V_48 -> V_39 , & V_79 ) ;
if ( V_41 < 0 )
return V_41 ;
V_81 = F_22 ( V_78 ) ;
V_82 = F_22 ( V_79 ) ;
V_76 = F_4 ( V_81 -> V_15 . V_16 ) / 2 ;
V_77 = F_4 ( V_81 -> V_15 . V_16 ) - V_76 ;
V_81 -> V_15 . V_16 = F_16 ( V_76 ) ;
V_82 -> V_15 . V_25 = V_81 -> V_15 . V_25 ;
V_82 -> V_15 . V_16 = F_16 ( V_77 ) ;
V_82 -> V_15 . V_33 = V_81 -> V_15 . V_33 ;
V_82 -> V_15 . V_29 = V_81 -> V_15 . V_29 ;
memcpy ( V_82 -> V_19 , V_81 -> V_19 + V_76 , V_77 * sizeof( V_82 -> V_19 [ 0 ] ) ) ;
V_45 = F_4 ( V_81 -> V_15 . V_25 ) & V_26 ?
sizeof( T_2 ) : V_48 -> V_39 -> V_44 . V_45 ;
memcpy ( F_10 ( V_82 , 0 ) , F_10 ( V_81 , V_76 ) ,
V_45 * V_77 ) ;
V_80 = F_46 ( V_48 ) ;
V_83 = F_22 ( V_80 ) ;
V_84 = F_12 ( F_23 ( V_78 ) ) ;
F_14 ( & V_84 ) ;
F_1 ( F_10 ( V_83 , V_75 ) ,
& V_84 , sizeof( T_4 ) ) ;
V_84 = F_12 ( F_23 ( V_79 ) ) ;
F_14 ( & V_84 ) ;
V_41 = F_11 ( sizeof( T_4 ) , V_83 , V_75 + 1 ,
F_5 ( V_82 -> V_19 [ 0 ] ) , & V_84 ) ;
if ( V_41 )
return V_41 ;
if ( V_11 < F_5 ( V_82 -> V_19 [ 0 ] ) ) {
F_24 ( V_48 -> V_39 , V_79 ) ;
V_48 -> V_85 [ 1 ] = V_78 ;
} else {
F_24 ( V_48 -> V_39 , V_78 ) ;
V_48 -> V_85 [ 1 ] = V_79 ;
}
return 0 ;
}
static int F_47 ( struct V_74 * V_48 , T_2 V_11 )
{
int V_41 ;
T_1 V_45 ;
unsigned V_76 , V_77 ;
struct V_42 * V_78 , * V_79 , * V_86 ;
struct V_9 * V_83 , * V_81 , * V_82 ;
T_4 V_87 ;
V_86 = F_45 ( V_48 ) ;
V_41 = F_19 ( V_48 -> V_39 , & V_78 ) ;
if ( V_41 < 0 )
return V_41 ;
V_41 = F_19 ( V_48 -> V_39 , & V_79 ) ;
if ( V_41 < 0 ) {
return V_41 ;
}
V_83 = F_22 ( V_86 ) ;
V_81 = F_22 ( V_78 ) ;
V_82 = F_22 ( V_79 ) ;
V_76 = F_4 ( V_83 -> V_15 . V_16 ) / 2 ;
V_77 = F_4 ( V_83 -> V_15 . V_16 ) - V_76 ;
V_81 -> V_15 . V_25 = V_83 -> V_15 . V_25 ;
V_81 -> V_15 . V_16 = F_16 ( V_76 ) ;
V_81 -> V_15 . V_33 = V_83 -> V_15 . V_33 ;
V_81 -> V_15 . V_29 = V_83 -> V_15 . V_29 ;
V_82 -> V_15 . V_25 = V_83 -> V_15 . V_25 ;
V_82 -> V_15 . V_16 = F_16 ( V_77 ) ;
V_82 -> V_15 . V_33 = V_83 -> V_15 . V_33 ;
V_82 -> V_15 . V_29 = V_83 -> V_15 . V_29 ;
memcpy ( V_81 -> V_19 , V_83 -> V_19 , V_76 * sizeof( V_83 -> V_19 [ 0 ] ) ) ;
memcpy ( V_82 -> V_19 , V_83 -> V_19 + V_76 , V_77 * sizeof( V_83 -> V_19 [ 0 ] ) ) ;
V_45 = F_4 ( V_83 -> V_15 . V_25 ) & V_26 ?
sizeof( T_4 ) : V_48 -> V_39 -> V_44 . V_45 ;
memcpy ( F_10 ( V_81 , 0 ) , F_10 ( V_83 , 0 ) , V_76 * V_45 ) ;
memcpy ( F_10 ( V_82 , 0 ) , F_10 ( V_83 , V_76 ) ,
V_77 * V_45 ) ;
V_83 -> V_15 . V_25 = F_16 ( V_26 ) ;
V_83 -> V_15 . V_16 = F_16 ( 2 ) ;
V_83 -> V_15 . V_33 = F_16 (
F_17 ( sizeof( T_4 ) ,
F_20 (
F_21 ( V_48 -> V_39 -> V_21 ) ) ) ) ;
V_83 -> V_15 . V_29 = F_16 ( sizeof( T_4 ) ) ;
V_87 = F_12 ( F_23 ( V_78 ) ) ;
F_14 ( & V_87 ) ;
V_83 -> V_19 [ 0 ] = V_81 -> V_19 [ 0 ] ;
F_1 ( F_10 ( V_83 , 0 ) , & V_87 , sizeof( T_4 ) ) ;
V_87 = F_12 ( F_23 ( V_79 ) ) ;
F_14 ( & V_87 ) ;
V_83 -> V_19 [ 1 ] = V_82 -> V_19 [ 0 ] ;
F_1 ( F_10 ( V_83 , 1 ) , & V_87 , sizeof( T_4 ) ) ;
if ( V_48 -> V_85 [ 0 ] != V_86 ) {
F_24 ( V_48 -> V_39 , V_48 -> V_85 [ 0 ] ) ;
V_48 -> V_85 [ 0 ] = V_86 ;
}
if ( V_11 < F_5 ( V_82 -> V_19 [ 0 ] ) ) {
F_24 ( V_48 -> V_39 , V_79 ) ;
V_48 -> V_85 [ 1 ] = V_78 ;
} else {
F_24 ( V_48 -> V_39 , V_78 ) ;
V_48 -> V_85 [ 1 ] = V_79 ;
}
V_48 -> V_88 = 2 ;
return 0 ;
}
static int F_48 ( struct V_74 * V_48 , T_5 V_40 ,
struct V_22 * V_23 ,
T_2 V_11 , unsigned * V_7 )
{
int V_41 , V_24 = * V_7 , V_51 = 1 ;
struct V_9 * V_30 ;
for (; ; ) {
V_41 = F_49 ( V_48 , V_40 , V_23 ) ;
if ( V_41 < 0 )
return V_41 ;
V_30 = F_22 ( F_45 ( V_48 ) ) ;
if ( F_50 ( V_48 ) && V_24 >= 0 ) {
T_4 V_84 = F_12 ( F_23 ( F_45 ( V_48 ) ) ) ;
F_14 ( & V_84 ) ;
F_1 ( F_10 ( F_22 ( F_46 ( V_48 ) ) , V_24 ) ,
& V_84 , sizeof( T_4 ) ) ;
}
V_30 = F_22 ( F_45 ( V_48 ) ) ;
if ( V_30 -> V_15 . V_16 == V_30 -> V_15 . V_33 ) {
if ( V_51 )
V_41 = F_47 ( V_48 , V_11 ) ;
else
V_41 = F_44 ( V_48 , V_40 , V_24 , V_11 ) ;
if ( V_41 < 0 )
return V_41 ;
}
V_30 = F_22 ( F_45 ( V_48 ) ) ;
V_24 = F_6 ( V_30 , V_11 ) ;
if ( F_4 ( V_30 -> V_15 . V_25 ) & V_46 )
break;
if ( V_24 < 0 ) {
V_30 -> V_19 [ 0 ] = F_12 ( V_11 ) ;
V_24 = 0 ;
}
V_40 = F_9 ( V_30 , V_24 ) ;
V_51 = 0 ;
}
if ( V_24 < 0 || F_5 ( V_30 -> V_19 [ V_24 ] ) != V_11 )
V_24 ++ ;
* V_7 = V_24 ;
return 0 ;
}
static int F_51 ( struct V_38 * V_39 , T_5 V_40 ,
T_2 * V_19 , void * V_31 , T_5 * V_89 ,
int * V_90 )
__dm_written_to_disk( V_31 )
{
int V_41 , V_91 ;
unsigned V_54 , V_7 = - 1 , V_70 = V_39 -> V_60 - 1 ;
T_5 V_65 = V_40 ;
struct V_74 V_53 ;
struct V_9 * V_10 ;
struct V_22 V_92 ;
V_92 . V_28 = NULL ;
V_92 . V_45 = sizeof( T_4 ) ;
V_92 . V_27 = NULL ;
V_92 . V_63 = NULL ;
V_92 . V_93 = NULL ;
F_52 ( & V_53 , V_39 ) ;
for ( V_54 = 0 ; V_54 < ( V_39 -> V_60 - 1 ) ; V_54 ++ ) {
V_41 = F_48 ( & V_53 , V_65 , & V_92 , V_19 [ V_54 ] , & V_7 ) ;
if ( V_41 < 0 )
goto V_94;
V_10 = F_22 ( F_45 ( & V_53 ) ) ;
V_91 = ( ( V_7 >= F_4 ( V_10 -> V_15 . V_16 ) ) ||
( F_5 ( V_10 -> V_19 [ V_7 ] ) != V_19 [ V_54 ] ) ) ;
if ( V_91 ) {
T_5 V_95 ;
T_4 V_96 ;
V_41 = F_18 ( V_39 , & V_95 ) ;
if ( V_41 < 0 )
goto V_94;
V_96 = F_12 ( V_95 ) ;
F_14 ( & V_96 ) ;
V_41 = F_11 ( sizeof( T_2 ) , V_10 , V_7 ,
V_19 [ V_54 ] , & V_96 ) ;
if ( V_41 )
goto V_94;
}
if ( V_54 < V_70 )
V_65 = F_9 ( V_10 , V_7 ) ;
}
V_41 = F_48 ( & V_53 , V_65 , & V_39 -> V_44 ,
V_19 [ V_54 ] , & V_7 ) ;
if ( V_41 < 0 )
goto V_94;
V_10 = F_22 ( F_45 ( & V_53 ) ) ;
V_91 = ( ( V_7 >= F_4 ( V_10 -> V_15 . V_16 ) ) ||
( F_5 ( V_10 -> V_19 [ V_7 ] ) != V_19 [ V_54 ] ) ) ;
if ( V_91 ) {
if ( V_90 )
* V_90 = 1 ;
V_41 = F_11 ( V_39 -> V_44 . V_45 , V_10 , V_7 ,
V_19 [ V_54 ] , V_31 ) ;
if ( V_41 )
goto V_97;
} else {
if ( V_90 )
* V_90 = 0 ;
if ( V_39 -> V_44 . V_63 &&
( ! V_39 -> V_44 . V_93 ||
! V_39 -> V_44 . V_93 (
V_39 -> V_44 . V_28 ,
F_10 ( V_10 , V_7 ) ,
V_31 ) ) ) {
V_39 -> V_44 . V_63 ( V_39 -> V_44 . V_28 ,
F_10 ( V_10 , V_7 ) ) ;
}
F_1 ( F_10 ( V_10 , V_7 ) ,
V_31 , V_39 -> V_44 . V_45 ) ;
}
* V_89 = F_53 ( & V_53 ) ;
F_54 ( & V_53 ) ;
return 0 ;
V_94:
F_2 ( V_31 ) ;
V_97:
F_54 ( & V_53 ) ;
return V_41 ;
}
int F_55 ( struct V_38 * V_39 , T_5 V_40 ,
T_2 * V_19 , void * V_31 , T_5 * V_89 )
__dm_written_to_disk( V_31 )
{
return F_51 ( V_39 , V_40 , V_19 , V_31 , V_89 , NULL ) ;
}
int F_56 ( struct V_38 * V_39 , T_5 V_40 ,
T_2 * V_19 , void * V_31 , T_5 * V_89 ,
int * V_90 )
__dm_written_to_disk( V_31 )
{
return F_51 ( V_39 , V_40 , V_19 , V_31 , V_89 , V_90 ) ;
}
static int F_57 ( struct V_64 * V_48 , T_5 V_65 ,
T_2 * V_66 , T_5 * V_98 )
{
int V_24 , V_41 ;
T_3 V_25 ;
do {
V_41 = F_39 ( V_48 , V_65 ) ;
if ( V_41 < 0 )
return V_41 ;
V_25 = F_4 ( F_40 ( V_48 ) -> V_15 . V_25 ) ;
V_24 = F_4 ( F_40 ( V_48 ) -> V_15 . V_16 ) ;
if ( ! V_24 )
return - V_68 ;
else
V_24 -- ;
* V_66 = F_5 ( F_40 ( V_48 ) -> V_19 [ V_24 ] ) ;
if ( V_98 || V_25 & V_26 )
V_65 = F_9 ( F_40 ( V_48 ) , V_24 ) ;
} while ( V_25 & V_26 );
if ( V_98 )
* V_98 = V_65 ;
return 0 ;
}
int F_58 ( struct V_38 * V_39 , T_5 V_40 ,
T_2 * V_99 )
{
int V_41 = 0 , V_88 = 0 , V_54 ;
struct V_64 V_53 ;
F_42 ( & V_53 , V_39 ) ;
for ( V_54 = 0 ; V_54 < V_39 -> V_60 ; V_54 ++ ) {
V_41 = F_57 ( & V_53 , V_40 , V_99 + V_54 ,
V_54 == V_39 -> V_60 - 1 ? NULL : & V_40 ) ;
if ( V_41 == - V_68 ) {
V_41 = 0 ;
break;
} else if ( V_41 )
break;
V_88 ++ ;
}
F_43 ( & V_53 ) ;
return V_41 ? V_41 : V_88 ;
}
