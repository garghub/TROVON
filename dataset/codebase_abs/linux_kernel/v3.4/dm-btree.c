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
static int F_11 ( T_1 V_29 , struct V_9 * V_9 , unsigned V_7 ,
T_2 V_11 , void * V_30 )
__dm_written_to_disk( V_30 )
{
T_3 V_16 = F_4 ( V_9 -> V_15 . V_16 ) ;
T_4 V_31 = F_12 ( V_11 ) ;
if ( V_7 > V_16 ||
V_7 >= F_4 ( V_9 -> V_15 . V_32 ) ) {
F_13 ( L_1 ) ;
F_2 ( V_30 ) ;
return - V_33 ;
}
F_14 ( & V_31 ) ;
F_3 ( V_9 -> V_19 , sizeof( * V_9 -> V_19 ) , V_16 , V_7 , & V_31 ) ;
F_3 ( F_15 ( V_9 ) , V_29 , V_16 , V_7 , V_30 ) ;
V_9 -> V_15 . V_16 = F_16 ( V_16 + 1 ) ;
return 0 ;
}
static T_3 F_17 ( T_1 V_29 , T_1 V_34 )
{
T_3 V_35 , V_10 ;
T_1 V_5 = sizeof( T_2 ) + V_29 ;
V_34 -= sizeof( struct V_36 ) ;
V_35 = V_34 / V_5 ;
V_10 = V_35 / 3 ;
return 3 * V_10 ;
}
int F_18 ( struct V_37 * V_38 , T_5 * V_39 )
{
int V_40 ;
struct V_41 * V_42 ;
struct V_9 * V_10 ;
T_1 V_34 ;
T_3 V_32 ;
V_40 = F_19 ( V_38 , & V_42 ) ;
if ( V_40 < 0 )
return V_40 ;
V_34 = F_20 ( F_21 ( V_38 -> V_21 ) ) ;
V_32 = F_17 ( V_38 -> V_43 . V_44 , V_34 ) ;
V_10 = F_22 ( V_42 ) ;
memset ( V_10 , 0 , V_34 ) ;
V_10 -> V_15 . V_25 = F_16 ( V_45 ) ;
V_10 -> V_15 . V_16 = F_16 ( 0 ) ;
V_10 -> V_15 . V_32 = F_16 ( V_32 ) ;
V_10 -> V_15 . V_29 = F_16 ( V_38 -> V_43 . V_44 ) ;
* V_39 = F_23 ( V_42 ) ;
return F_24 ( V_38 , V_42 ) ;
}
static int F_25 ( struct V_46 * V_47 , struct V_48 * * V_49 )
{
if ( V_47 -> V_50 < 0 ) {
F_13 ( L_2 ) ;
return - V_51 ;
}
* V_49 = V_47 -> V_52 + V_47 -> V_50 ;
return 0 ;
}
static int F_26 ( struct V_46 * V_47 )
{
return V_47 -> V_50 >= 0 ;
}
static int F_27 ( struct V_46 * V_47 , T_5 V_42 , unsigned V_53 )
{
int V_40 ;
T_3 V_54 ;
if ( V_47 -> V_50 >= V_55 - 1 ) {
F_13 ( L_3 ) ;
return - V_33 ;
}
V_40 = F_28 ( V_47 -> V_21 , V_42 , & V_54 ) ;
if ( V_40 )
return V_40 ;
if ( V_54 > 1 )
F_29 ( V_47 -> V_21 , V_42 ) ;
else {
struct V_48 * V_49 = V_47 -> V_52 + ++ V_47 -> V_50 ;
V_40 = F_30 ( V_47 -> V_21 , V_42 , & V_56 , & V_49 -> V_42 ) ;
if ( V_40 ) {
V_47 -> V_50 -- ;
return V_40 ;
}
V_49 -> V_10 = F_22 ( V_49 -> V_42 ) ;
V_49 -> V_53 = V_53 ;
V_49 -> V_57 = F_4 ( V_49 -> V_10 -> V_15 . V_16 ) ;
V_49 -> V_58 = 0 ;
}
return 0 ;
}
static void F_31 ( struct V_46 * V_47 )
{
struct V_48 * V_49 = V_47 -> V_52 + V_47 -> V_50 -- ;
F_29 ( V_47 -> V_21 , F_23 ( V_49 -> V_42 ) ) ;
F_32 ( V_47 -> V_21 , V_49 -> V_42 ) ;
}
int F_33 ( struct V_37 * V_38 , T_5 V_39 )
{
int V_40 ;
struct V_46 * V_47 ;
V_47 = F_34 ( sizeof( * V_47 ) , V_59 ) ;
if ( ! V_47 )
return - V_33 ;
V_47 -> V_21 = V_38 -> V_21 ;
V_47 -> V_50 = - 1 ;
V_40 = F_27 ( V_47 , V_39 , 1 ) ;
if ( V_40 )
goto V_60;
while ( F_26 ( V_47 ) ) {
T_3 V_25 ;
struct V_48 * V_49 ;
T_5 V_42 ;
V_40 = F_25 ( V_47 , & V_49 ) ;
if ( V_40 )
goto V_60;
if ( V_49 -> V_58 >= V_49 -> V_57 ) {
F_31 ( V_47 ) ;
continue;
}
V_25 = F_4 ( V_49 -> V_10 -> V_15 . V_25 ) ;
if ( V_25 & V_26 ) {
V_42 = F_9 ( V_49 -> V_10 , V_49 -> V_58 ) ;
V_49 -> V_58 ++ ;
V_40 = F_27 ( V_47 , V_42 , V_49 -> V_53 ) ;
if ( V_40 )
goto V_60;
} else if ( V_49 -> V_53 != ( V_38 -> V_61 - 1 ) ) {
V_42 = F_9 ( V_49 -> V_10 , V_49 -> V_58 ) ;
V_49 -> V_58 ++ ;
V_40 = F_27 ( V_47 , V_42 , V_49 -> V_53 + 1 ) ;
if ( V_40 )
goto V_60;
} else {
if ( V_38 -> V_43 . V_62 ) {
unsigned V_24 ;
for ( V_24 = 0 ; V_24 < V_49 -> V_57 ; V_24 ++ )
V_38 -> V_43 . V_62 ( V_38 -> V_43 . V_28 ,
F_10 ( V_49 -> V_10 , V_24 ) ) ;
}
V_49 -> V_58 = V_49 -> V_57 ;
}
}
V_60:
F_35 ( V_47 ) ;
return V_40 ;
}
static int F_36 ( struct V_63 * V_47 , T_5 V_64 , T_2 V_11 ,
int (* F_37)( struct V_9 * , T_2 ) ,
T_2 * V_65 , void * V_66 , T_1 V_29 )
{
int V_24 , V_40 ;
T_3 V_25 , V_16 ;
do {
V_40 = F_38 ( V_47 , V_64 ) ;
if ( V_40 < 0 )
return V_40 ;
V_24 = F_37 ( F_39 ( V_47 ) , V_11 ) ;
V_25 = F_4 ( F_39 ( V_47 ) -> V_15 . V_25 ) ;
V_16 = F_4 ( F_39 ( V_47 ) -> V_15 . V_16 ) ;
if ( V_24 < 0 || V_24 >= V_16 )
return - V_67 ;
if ( V_25 & V_26 )
V_64 = F_9 ( F_39 ( V_47 ) , V_24 ) ;
} while ( ! ( V_25 & V_45 ) );
* V_65 = F_5 ( F_39 ( V_47 ) -> V_19 [ V_24 ] ) ;
memcpy ( V_66 , F_10 ( F_39 ( V_47 ) , V_24 ) , V_29 ) ;
return 0 ;
}
int F_40 ( struct V_37 * V_38 , T_5 V_39 ,
T_2 * V_19 , void * V_68 )
{
unsigned V_53 , V_69 = V_38 -> V_61 - 1 ;
int V_40 = - V_67 ;
T_2 V_70 ;
T_4 V_71 ;
struct V_63 V_52 ;
F_41 ( & V_52 , V_38 ) ;
for ( V_53 = 0 ; V_53 < V_38 -> V_61 ; V_53 ++ ) {
T_1 V_44 ;
void * V_72 ;
if ( V_53 == V_69 ) {
V_72 = V_68 ;
V_44 = V_38 -> V_43 . V_44 ;
} else {
V_72 = & V_71 ;
V_44 = sizeof( T_2 ) ;
}
V_40 = F_36 ( & V_52 , V_39 , V_19 [ V_53 ] ,
F_6 , & V_70 ,
V_72 , V_44 ) ;
if ( ! V_40 ) {
if ( V_70 != V_19 [ V_53 ] ) {
F_42 ( & V_52 ) ;
return - V_67 ;
}
} else {
F_42 ( & V_52 ) ;
return V_40 ;
}
V_39 = F_5 ( V_71 ) ;
}
F_42 ( & V_52 ) ;
return V_40 ;
}
static int F_43 ( struct V_73 * V_47 , T_5 V_39 ,
unsigned V_74 , T_2 V_11 )
{
int V_40 ;
T_1 V_44 ;
unsigned V_75 , V_76 ;
struct V_41 * V_77 , * V_78 , * V_79 ;
struct V_9 * V_80 , * V_81 , * V_82 ;
T_4 V_83 ;
V_77 = F_44 ( V_47 ) ;
V_40 = F_19 ( V_47 -> V_38 , & V_78 ) ;
if ( V_40 < 0 )
return V_40 ;
V_80 = F_22 ( V_77 ) ;
V_81 = F_22 ( V_78 ) ;
V_75 = F_4 ( V_80 -> V_15 . V_16 ) / 2 ;
V_76 = F_4 ( V_80 -> V_15 . V_16 ) - V_75 ;
V_80 -> V_15 . V_16 = F_16 ( V_75 ) ;
V_81 -> V_15 . V_25 = V_80 -> V_15 . V_25 ;
V_81 -> V_15 . V_16 = F_16 ( V_76 ) ;
V_81 -> V_15 . V_32 = V_80 -> V_15 . V_32 ;
V_81 -> V_15 . V_29 = V_80 -> V_15 . V_29 ;
memcpy ( V_81 -> V_19 , V_80 -> V_19 + V_75 , V_76 * sizeof( V_81 -> V_19 [ 0 ] ) ) ;
V_44 = F_4 ( V_80 -> V_15 . V_25 ) & V_26 ?
sizeof( T_2 ) : V_47 -> V_38 -> V_43 . V_44 ;
memcpy ( F_10 ( V_81 , 0 ) , F_10 ( V_80 , V_75 ) ,
V_44 * V_76 ) ;
V_79 = F_45 ( V_47 ) ;
V_82 = F_22 ( V_79 ) ;
V_83 = F_12 ( F_23 ( V_77 ) ) ;
F_14 ( & V_83 ) ;
F_1 ( F_10 ( V_82 , V_74 ) ,
& V_83 , sizeof( T_4 ) ) ;
V_83 = F_12 ( F_23 ( V_78 ) ) ;
F_14 ( & V_83 ) ;
V_40 = F_11 ( sizeof( T_4 ) , V_82 , V_74 + 1 ,
F_5 ( V_81 -> V_19 [ 0 ] ) , & V_83 ) ;
if ( V_40 )
return V_40 ;
if ( V_11 < F_5 ( V_81 -> V_19 [ 0 ] ) ) {
F_24 ( V_47 -> V_38 , V_78 ) ;
V_47 -> V_84 [ 1 ] = V_77 ;
} else {
F_24 ( V_47 -> V_38 , V_77 ) ;
V_47 -> V_84 [ 1 ] = V_78 ;
}
return 0 ;
}
static int F_46 ( struct V_73 * V_47 , T_2 V_11 )
{
int V_40 ;
T_1 V_44 ;
unsigned V_75 , V_76 ;
struct V_41 * V_77 , * V_78 , * V_85 ;
struct V_9 * V_82 , * V_80 , * V_81 ;
T_4 V_86 ;
V_85 = F_44 ( V_47 ) ;
V_40 = F_19 ( V_47 -> V_38 , & V_77 ) ;
if ( V_40 < 0 )
return V_40 ;
V_40 = F_19 ( V_47 -> V_38 , & V_78 ) ;
if ( V_40 < 0 ) {
return V_40 ;
}
V_82 = F_22 ( V_85 ) ;
V_80 = F_22 ( V_77 ) ;
V_81 = F_22 ( V_78 ) ;
V_75 = F_4 ( V_82 -> V_15 . V_16 ) / 2 ;
V_76 = F_4 ( V_82 -> V_15 . V_16 ) - V_75 ;
V_80 -> V_15 . V_25 = V_82 -> V_15 . V_25 ;
V_80 -> V_15 . V_16 = F_16 ( V_75 ) ;
V_80 -> V_15 . V_32 = V_82 -> V_15 . V_32 ;
V_80 -> V_15 . V_29 = V_82 -> V_15 . V_29 ;
V_81 -> V_15 . V_25 = V_82 -> V_15 . V_25 ;
V_81 -> V_15 . V_16 = F_16 ( V_76 ) ;
V_81 -> V_15 . V_32 = V_82 -> V_15 . V_32 ;
V_81 -> V_15 . V_29 = V_82 -> V_15 . V_29 ;
memcpy ( V_80 -> V_19 , V_82 -> V_19 , V_75 * sizeof( V_82 -> V_19 [ 0 ] ) ) ;
memcpy ( V_81 -> V_19 , V_82 -> V_19 + V_75 , V_76 * sizeof( V_82 -> V_19 [ 0 ] ) ) ;
V_44 = F_4 ( V_82 -> V_15 . V_25 ) & V_26 ?
sizeof( T_4 ) : V_47 -> V_38 -> V_43 . V_44 ;
memcpy ( F_10 ( V_80 , 0 ) , F_10 ( V_82 , 0 ) , V_75 * V_44 ) ;
memcpy ( F_10 ( V_81 , 0 ) , F_10 ( V_82 , V_75 ) ,
V_76 * V_44 ) ;
V_82 -> V_15 . V_25 = F_16 ( V_26 ) ;
V_82 -> V_15 . V_16 = F_16 ( 2 ) ;
V_82 -> V_15 . V_32 = F_16 (
F_17 ( sizeof( T_4 ) ,
F_20 (
F_21 ( V_47 -> V_38 -> V_21 ) ) ) ) ;
V_82 -> V_15 . V_29 = F_16 ( sizeof( T_4 ) ) ;
V_86 = F_12 ( F_23 ( V_77 ) ) ;
F_14 ( & V_86 ) ;
V_82 -> V_19 [ 0 ] = V_80 -> V_19 [ 0 ] ;
F_1 ( F_10 ( V_82 , 0 ) , & V_86 , sizeof( T_4 ) ) ;
V_86 = F_12 ( F_23 ( V_78 ) ) ;
F_14 ( & V_86 ) ;
V_82 -> V_19 [ 1 ] = V_81 -> V_19 [ 0 ] ;
F_1 ( F_10 ( V_82 , 1 ) , & V_86 , sizeof( T_4 ) ) ;
if ( V_47 -> V_84 [ 0 ] != V_85 ) {
F_24 ( V_47 -> V_38 , V_47 -> V_84 [ 0 ] ) ;
V_47 -> V_84 [ 0 ] = V_85 ;
}
if ( V_11 < F_5 ( V_81 -> V_19 [ 0 ] ) ) {
F_24 ( V_47 -> V_38 , V_78 ) ;
V_47 -> V_84 [ 1 ] = V_77 ;
} else {
F_24 ( V_47 -> V_38 , V_77 ) ;
V_47 -> V_84 [ 1 ] = V_78 ;
}
V_47 -> V_87 = 2 ;
return 0 ;
}
static int F_47 ( struct V_73 * V_47 , T_5 V_39 ,
struct V_22 * V_23 ,
T_2 V_11 , unsigned * V_7 )
{
int V_40 , V_24 = * V_7 , V_50 = 1 ;
struct V_9 * V_9 ;
for (; ; ) {
V_40 = F_48 ( V_47 , V_39 , V_23 ) ;
if ( V_40 < 0 )
return V_40 ;
V_9 = F_22 ( F_44 ( V_47 ) ) ;
if ( F_49 ( V_47 ) && V_24 >= 0 ) {
T_4 V_83 = F_12 ( F_23 ( F_44 ( V_47 ) ) ) ;
F_14 ( & V_83 ) ;
F_1 ( F_10 ( F_22 ( F_45 ( V_47 ) ) , V_24 ) ,
& V_83 , sizeof( T_4 ) ) ;
}
V_9 = F_22 ( F_44 ( V_47 ) ) ;
if ( V_9 -> V_15 . V_16 == V_9 -> V_15 . V_32 ) {
if ( V_50 )
V_40 = F_46 ( V_47 , V_11 ) ;
else
V_40 = F_43 ( V_47 , V_39 , V_24 , V_11 ) ;
if ( V_40 < 0 )
return V_40 ;
}
V_9 = F_22 ( F_44 ( V_47 ) ) ;
V_24 = F_6 ( V_9 , V_11 ) ;
if ( F_4 ( V_9 -> V_15 . V_25 ) & V_45 )
break;
if ( V_24 < 0 ) {
V_9 -> V_19 [ 0 ] = F_12 ( V_11 ) ;
V_24 = 0 ;
}
V_39 = F_9 ( V_9 , V_24 ) ;
V_50 = 0 ;
}
if ( V_24 < 0 || F_5 ( V_9 -> V_19 [ V_24 ] ) != V_11 )
V_24 ++ ;
* V_7 = V_24 ;
return 0 ;
}
static int F_50 ( struct V_37 * V_38 , T_5 V_39 ,
T_2 * V_19 , void * V_30 , T_5 * V_88 ,
int * V_89 )
__dm_written_to_disk( V_30 )
{
int V_40 , V_90 ;
unsigned V_53 , V_7 = - 1 , V_69 = V_38 -> V_61 - 1 ;
T_5 V_64 = V_39 ;
struct V_73 V_52 ;
struct V_9 * V_10 ;
struct V_22 V_91 ;
V_91 . V_28 = NULL ;
V_91 . V_44 = sizeof( T_4 ) ;
V_91 . V_27 = NULL ;
V_91 . V_62 = NULL ;
V_91 . V_92 = NULL ;
F_51 ( & V_52 , V_38 ) ;
for ( V_53 = 0 ; V_53 < ( V_38 -> V_61 - 1 ) ; V_53 ++ ) {
V_40 = F_47 ( & V_52 , V_64 , & V_91 , V_19 [ V_53 ] , & V_7 ) ;
if ( V_40 < 0 )
goto V_93;
V_10 = F_22 ( F_44 ( & V_52 ) ) ;
V_90 = ( ( V_7 >= F_4 ( V_10 -> V_15 . V_16 ) ) ||
( F_5 ( V_10 -> V_19 [ V_7 ] ) != V_19 [ V_53 ] ) ) ;
if ( V_90 ) {
T_5 V_94 ;
T_4 V_95 ;
V_40 = F_18 ( V_38 , & V_94 ) ;
if ( V_40 < 0 )
goto V_93;
V_95 = F_12 ( V_94 ) ;
F_14 ( & V_95 ) ;
V_40 = F_11 ( sizeof( T_2 ) , V_10 , V_7 ,
V_19 [ V_53 ] , & V_95 ) ;
if ( V_40 )
goto V_93;
}
if ( V_53 < V_69 )
V_64 = F_9 ( V_10 , V_7 ) ;
}
V_40 = F_47 ( & V_52 , V_64 , & V_38 -> V_43 ,
V_19 [ V_53 ] , & V_7 ) ;
if ( V_40 < 0 )
goto V_93;
V_10 = F_22 ( F_44 ( & V_52 ) ) ;
V_90 = ( ( V_7 >= F_4 ( V_10 -> V_15 . V_16 ) ) ||
( F_5 ( V_10 -> V_19 [ V_7 ] ) != V_19 [ V_53 ] ) ) ;
if ( V_90 ) {
if ( V_89 )
* V_89 = 1 ;
V_40 = F_11 ( V_38 -> V_43 . V_44 , V_10 , V_7 ,
V_19 [ V_53 ] , V_30 ) ;
if ( V_40 )
goto V_96;
} else {
if ( V_89 )
* V_89 = 0 ;
if ( V_38 -> V_43 . V_62 &&
( ! V_38 -> V_43 . V_92 ||
! V_38 -> V_43 . V_92 (
V_38 -> V_43 . V_28 ,
F_10 ( V_10 , V_7 ) ,
V_30 ) ) ) {
V_38 -> V_43 . V_62 ( V_38 -> V_43 . V_28 ,
F_10 ( V_10 , V_7 ) ) ;
}
F_1 ( F_10 ( V_10 , V_7 ) ,
V_30 , V_38 -> V_43 . V_44 ) ;
}
* V_88 = F_52 ( & V_52 ) ;
F_53 ( & V_52 ) ;
return 0 ;
V_93:
F_2 ( V_30 ) ;
V_96:
F_53 ( & V_52 ) ;
return V_40 ;
}
int F_54 ( struct V_37 * V_38 , T_5 V_39 ,
T_2 * V_19 , void * V_30 , T_5 * V_88 )
__dm_written_to_disk( V_30 )
{
return F_50 ( V_38 , V_39 , V_19 , V_30 , V_88 , NULL ) ;
}
int F_55 ( struct V_37 * V_38 , T_5 V_39 ,
T_2 * V_19 , void * V_30 , T_5 * V_88 ,
int * V_89 )
__dm_written_to_disk( V_30 )
{
return F_50 ( V_38 , V_39 , V_19 , V_30 , V_88 , V_89 ) ;
}
static int F_56 ( struct V_63 * V_47 , T_5 V_64 ,
T_2 * V_65 , T_5 * V_97 )
{
int V_24 , V_40 ;
T_3 V_25 ;
do {
V_40 = F_38 ( V_47 , V_64 ) ;
if ( V_40 < 0 )
return V_40 ;
V_25 = F_4 ( F_39 ( V_47 ) -> V_15 . V_25 ) ;
V_24 = F_4 ( F_39 ( V_47 ) -> V_15 . V_16 ) ;
if ( ! V_24 )
return - V_67 ;
else
V_24 -- ;
* V_65 = F_5 ( F_39 ( V_47 ) -> V_19 [ V_24 ] ) ;
if ( V_97 || V_25 & V_26 )
V_64 = F_9 ( F_39 ( V_47 ) , V_24 ) ;
} while ( V_25 & V_26 );
if ( V_97 )
* V_97 = V_64 ;
return 0 ;
}
int F_57 ( struct V_37 * V_38 , T_5 V_39 ,
T_2 * V_98 )
{
int V_40 = 0 , V_87 = 0 , V_53 ;
struct V_63 V_52 ;
F_41 ( & V_52 , V_38 ) ;
for ( V_53 = 0 ; V_53 < V_38 -> V_61 ; V_53 ++ ) {
V_40 = F_56 ( & V_52 , V_39 , V_98 + V_53 ,
V_53 == V_38 -> V_61 - 1 ? NULL : & V_39 ) ;
if ( V_40 == - V_67 ) {
V_40 = 0 ;
break;
} else if ( V_40 )
break;
V_87 ++ ;
}
F_42 ( & V_52 ) ;
return V_40 ? V_40 : V_87 ;
}
