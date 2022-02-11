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
static int F_7 ( struct V_9 * V_10 , T_2 V_11 )
{
return bsearch ( V_10 , V_11 , 1 ) ;
}
void F_8 ( struct V_20 * V_21 , struct V_9 * V_10 ,
struct V_22 * V_23 )
{
unsigned V_24 ;
T_3 V_16 = F_4 ( V_10 -> V_15 . V_16 ) ;
if ( F_4 ( V_10 -> V_15 . V_25 ) & V_26 )
for ( V_24 = 0 ; V_24 < V_16 ; V_24 ++ )
F_9 ( V_21 , F_10 ( V_10 , V_24 ) ) ;
else if ( V_23 -> V_27 )
for ( V_24 = 0 ; V_24 < V_16 ; V_24 ++ )
V_23 -> V_27 ( V_23 -> V_28 , F_11 ( V_10 , V_24 ) ) ;
}
static int F_12 ( T_1 V_29 , struct V_9 * V_30 , unsigned V_7 ,
T_2 V_11 , void * V_31 )
__dm_written_to_disk( V_31 )
{
T_3 V_16 = F_4 ( V_30 -> V_15 . V_16 ) ;
T_4 V_32 = F_13 ( V_11 ) ;
if ( V_7 > V_16 ||
V_7 >= F_4 ( V_30 -> V_15 . V_33 ) ) {
F_14 ( L_1 ) ;
F_2 ( V_31 ) ;
return - V_34 ;
}
F_15 ( & V_32 ) ;
F_3 ( V_30 -> V_19 , sizeof( * V_30 -> V_19 ) , V_16 , V_7 , & V_32 ) ;
F_3 ( F_16 ( V_30 ) , V_29 , V_16 , V_7 , V_31 ) ;
V_30 -> V_15 . V_16 = F_17 ( V_16 + 1 ) ;
return 0 ;
}
static T_3 F_18 ( T_1 V_29 , T_1 V_35 )
{
T_3 V_36 , V_10 ;
T_1 V_5 = sizeof( T_2 ) + V_29 ;
V_35 -= sizeof( struct V_37 ) ;
V_36 = V_35 / V_5 ;
V_10 = V_36 / 3 ;
return 3 * V_10 ;
}
int F_19 ( struct V_38 * V_39 , T_5 * V_40 )
{
int V_41 ;
struct V_42 * V_43 ;
struct V_9 * V_10 ;
T_1 V_35 ;
T_3 V_33 ;
V_41 = F_20 ( V_39 , & V_43 ) ;
if ( V_41 < 0 )
return V_41 ;
V_35 = F_21 ( F_22 ( V_39 -> V_21 ) ) ;
V_33 = F_18 ( V_39 -> V_44 . V_45 , V_35 ) ;
V_10 = F_23 ( V_43 ) ;
memset ( V_10 , 0 , V_35 ) ;
V_10 -> V_15 . V_25 = F_17 ( V_46 ) ;
V_10 -> V_15 . V_16 = F_17 ( 0 ) ;
V_10 -> V_15 . V_33 = F_17 ( V_33 ) ;
V_10 -> V_15 . V_29 = F_17 ( V_39 -> V_44 . V_45 ) ;
* V_40 = F_24 ( V_43 ) ;
F_25 ( V_39 , V_43 ) ;
return 0 ;
}
static int F_26 ( struct V_47 * V_48 , struct V_49 * * V_50 )
{
if ( V_48 -> V_51 < 0 ) {
F_14 ( L_2 ) ;
return - V_52 ;
}
* V_50 = V_48 -> V_53 + V_48 -> V_51 ;
return 0 ;
}
static int F_27 ( struct V_47 * V_48 )
{
return V_48 -> V_51 >= 0 ;
}
static void F_28 ( struct V_47 * V_48 , struct V_49 * V_50 )
{
unsigned V_24 ;
struct V_54 * V_55 = F_22 ( V_48 -> V_21 ) ;
for ( V_24 = 0 ; V_24 < V_50 -> V_56 ; V_24 ++ )
F_29 ( V_55 , F_10 ( V_50 -> V_10 , V_24 ) ) ;
}
static bool F_30 ( struct V_38 * V_39 , struct V_49 * V_50 )
{
return V_50 -> V_57 < ( V_39 -> V_58 - 1 ) ;
}
static int F_31 ( struct V_47 * V_48 , T_5 V_43 , unsigned V_57 )
{
int V_41 ;
T_3 V_59 ;
if ( V_48 -> V_51 >= V_60 - 1 ) {
F_14 ( L_3 ) ;
return - V_34 ;
}
V_41 = F_32 ( V_48 -> V_21 , V_43 , & V_59 ) ;
if ( V_41 )
return V_41 ;
if ( V_59 > 1 )
F_33 ( V_48 -> V_21 , V_43 ) ;
else {
T_3 V_25 ;
struct V_49 * V_50 = V_48 -> V_53 + ++ V_48 -> V_51 ;
V_41 = F_34 ( V_48 -> V_21 , V_43 , & V_61 , & V_50 -> V_43 ) ;
if ( V_41 ) {
V_48 -> V_51 -- ;
return V_41 ;
}
V_50 -> V_10 = F_23 ( V_50 -> V_43 ) ;
V_50 -> V_57 = V_57 ;
V_50 -> V_56 = F_4 ( V_50 -> V_10 -> V_15 . V_16 ) ;
V_50 -> V_62 = 0 ;
V_25 = F_4 ( V_50 -> V_10 -> V_15 . V_25 ) ;
if ( V_25 & V_26 || F_30 ( V_48 -> V_39 , V_50 ) )
F_28 ( V_48 , V_50 ) ;
}
return 0 ;
}
static void F_35 ( struct V_47 * V_48 )
{
struct V_49 * V_50 = V_48 -> V_53 + V_48 -> V_51 -- ;
F_33 ( V_48 -> V_21 , F_24 ( V_50 -> V_43 ) ) ;
F_36 ( V_48 -> V_21 , V_50 -> V_43 ) ;
}
static void F_37 ( struct V_47 * V_48 )
{
struct V_49 * V_50 ;
while ( F_27 ( V_48 ) ) {
V_50 = V_48 -> V_53 + V_48 -> V_51 -- ;
F_36 ( V_48 -> V_21 , V_50 -> V_43 ) ;
}
}
int F_38 ( struct V_38 * V_39 , T_5 V_40 )
{
int V_41 ;
struct V_47 * V_48 ;
V_48 = F_39 ( sizeof( * V_48 ) , V_63 ) ;
if ( ! V_48 )
return - V_34 ;
V_48 -> V_39 = V_39 ;
V_48 -> V_21 = V_39 -> V_21 ;
V_48 -> V_51 = - 1 ;
V_41 = F_31 ( V_48 , V_40 , 0 ) ;
if ( V_41 )
goto V_64;
while ( F_27 ( V_48 ) ) {
T_3 V_25 ;
struct V_49 * V_50 ;
T_5 V_43 ;
V_41 = F_26 ( V_48 , & V_50 ) ;
if ( V_41 )
goto V_64;
if ( V_50 -> V_62 >= V_50 -> V_56 ) {
F_35 ( V_48 ) ;
continue;
}
V_25 = F_4 ( V_50 -> V_10 -> V_15 . V_25 ) ;
if ( V_25 & V_26 ) {
V_43 = F_10 ( V_50 -> V_10 , V_50 -> V_62 ) ;
V_50 -> V_62 ++ ;
V_41 = F_31 ( V_48 , V_43 , V_50 -> V_57 ) ;
if ( V_41 )
goto V_64;
} else if ( F_30 ( V_39 , V_50 ) ) {
V_43 = F_10 ( V_50 -> V_10 , V_50 -> V_62 ) ;
V_50 -> V_62 ++ ;
V_41 = F_31 ( V_48 , V_43 , V_50 -> V_57 + 1 ) ;
if ( V_41 )
goto V_64;
} else {
if ( V_39 -> V_44 . V_65 ) {
unsigned V_24 ;
for ( V_24 = 0 ; V_24 < V_50 -> V_56 ; V_24 ++ )
V_39 -> V_44 . V_65 ( V_39 -> V_44 . V_28 ,
F_11 ( V_50 -> V_10 , V_24 ) ) ;
}
F_35 ( V_48 ) ;
}
}
V_64:
if ( V_41 ) {
F_37 ( V_48 ) ;
}
F_40 ( V_48 ) ;
return V_41 ;
}
static int F_41 ( struct V_66 * V_48 , T_5 V_67 , T_2 V_11 ,
int (* F_42)( struct V_9 * , T_2 ) ,
T_2 * V_68 , void * V_69 , T_1 V_29 )
{
int V_24 , V_41 ;
T_3 V_25 , V_16 ;
do {
V_41 = F_43 ( V_48 , V_67 ) ;
if ( V_41 < 0 )
return V_41 ;
V_24 = F_42 ( F_44 ( V_48 ) , V_11 ) ;
V_25 = F_4 ( F_44 ( V_48 ) -> V_15 . V_25 ) ;
V_16 = F_4 ( F_44 ( V_48 ) -> V_15 . V_16 ) ;
if ( V_24 < 0 || V_24 >= V_16 )
return - V_70 ;
if ( V_25 & V_26 )
V_67 = F_10 ( F_44 ( V_48 ) , V_24 ) ;
} while ( ! ( V_25 & V_46 ) );
* V_68 = F_5 ( F_44 ( V_48 ) -> V_19 [ V_24 ] ) ;
memcpy ( V_69 , F_11 ( F_44 ( V_48 ) , V_24 ) , V_29 ) ;
return 0 ;
}
int F_45 ( struct V_38 * V_39 , T_5 V_40 ,
T_2 * V_19 , void * V_71 )
{
unsigned V_57 , V_72 = V_39 -> V_58 - 1 ;
int V_41 = - V_70 ;
T_2 V_73 ;
T_4 V_74 ;
struct V_66 V_53 ;
F_46 ( & V_53 , V_39 ) ;
for ( V_57 = 0 ; V_57 < V_39 -> V_58 ; V_57 ++ ) {
T_1 V_45 ;
void * V_75 ;
if ( V_57 == V_72 ) {
V_75 = V_71 ;
V_45 = V_39 -> V_44 . V_45 ;
} else {
V_75 = & V_74 ;
V_45 = sizeof( T_2 ) ;
}
V_41 = F_41 ( & V_53 , V_40 , V_19 [ V_57 ] ,
F_6 , & V_73 ,
V_75 , V_45 ) ;
if ( ! V_41 ) {
if ( V_73 != V_19 [ V_57 ] ) {
F_47 ( & V_53 ) ;
return - V_70 ;
}
} else {
F_47 ( & V_53 ) ;
return V_41 ;
}
V_40 = F_5 ( V_74 ) ;
}
F_47 ( & V_53 ) ;
return V_41 ;
}
static int F_48 ( struct V_38 * V_39 , T_5 V_40 ,
T_2 V_11 , T_2 * V_73 , void * V_71 )
{
int V_41 , V_24 ;
T_3 V_25 , V_16 ;
struct V_42 * V_30 ;
struct V_9 * V_10 ;
V_41 = F_49 ( V_39 , V_40 , & V_30 ) ;
if ( V_41 )
return V_41 ;
V_10 = F_23 ( V_30 ) ;
V_25 = F_4 ( V_10 -> V_15 . V_25 ) ;
V_16 = F_4 ( V_10 -> V_15 . V_16 ) ;
if ( V_25 & V_26 ) {
V_24 = F_6 ( V_10 , V_11 ) ;
if ( V_24 < 0 ) {
V_24 = 0 ;
}
if ( V_24 >= V_16 ) {
V_41 = - V_70 ;
goto V_64;
}
V_41 = F_48 ( V_39 , F_10 ( V_10 , V_24 ) , V_11 , V_73 , V_71 ) ;
if ( V_41 == - V_70 && V_24 < ( V_16 - 1 ) ) {
V_24 ++ ;
V_41 = F_48 ( V_39 , F_10 ( V_10 , V_24 ) , V_11 , V_73 , V_71 ) ;
}
} else {
V_24 = F_7 ( V_10 , V_11 ) ;
if ( V_24 < 0 || V_24 >= V_16 ) {
V_41 = - V_70 ;
goto V_64;
}
* V_73 = F_5 ( V_10 -> V_19 [ V_24 ] ) ;
memcpy ( V_71 , F_11 ( V_10 , V_24 ) , V_39 -> V_44 . V_45 ) ;
}
V_64:
F_36 ( V_39 -> V_21 , V_30 ) ;
return V_41 ;
}
int F_50 ( struct V_38 * V_39 , T_5 V_40 ,
T_2 * V_19 , T_2 * V_73 , void * V_71 )
{
unsigned V_57 ;
int V_41 = - V_70 ;
T_4 V_74 ;
struct V_66 V_53 ;
F_46 ( & V_53 , V_39 ) ;
for ( V_57 = 0 ; V_57 < V_39 -> V_58 - 1u ; V_57 ++ ) {
V_41 = F_41 ( & V_53 , V_40 , V_19 [ V_57 ] ,
F_6 , V_73 ,
& V_74 , sizeof( T_2 ) ) ;
if ( V_41 )
goto V_64;
if ( * V_73 != V_19 [ V_57 ] ) {
V_41 = - V_70 ;
goto V_64;
}
V_40 = F_5 ( V_74 ) ;
}
V_41 = F_48 ( V_39 , V_40 , V_19 [ V_57 ] , V_73 , V_71 ) ;
V_64:
F_47 ( & V_53 ) ;
return V_41 ;
}
static int F_51 ( struct V_76 * V_48 , unsigned V_77 ,
T_2 V_11 )
{
int V_41 ;
T_1 V_45 ;
unsigned V_78 , V_79 ;
struct V_42 * V_80 , * V_81 , * V_82 ;
struct V_9 * V_83 , * V_84 , * V_85 ;
T_4 V_86 ;
V_80 = F_52 ( V_48 ) ;
V_41 = F_20 ( V_48 -> V_39 , & V_81 ) ;
if ( V_41 < 0 )
return V_41 ;
V_83 = F_23 ( V_80 ) ;
V_84 = F_23 ( V_81 ) ;
V_78 = F_4 ( V_83 -> V_15 . V_16 ) / 2 ;
V_79 = F_4 ( V_83 -> V_15 . V_16 ) - V_78 ;
V_83 -> V_15 . V_16 = F_17 ( V_78 ) ;
V_84 -> V_15 . V_25 = V_83 -> V_15 . V_25 ;
V_84 -> V_15 . V_16 = F_17 ( V_79 ) ;
V_84 -> V_15 . V_33 = V_83 -> V_15 . V_33 ;
V_84 -> V_15 . V_29 = V_83 -> V_15 . V_29 ;
memcpy ( V_84 -> V_19 , V_83 -> V_19 + V_78 , V_79 * sizeof( V_84 -> V_19 [ 0 ] ) ) ;
V_45 = F_4 ( V_83 -> V_15 . V_25 ) & V_26 ?
sizeof( T_2 ) : V_48 -> V_39 -> V_44 . V_45 ;
memcpy ( F_11 ( V_84 , 0 ) , F_11 ( V_83 , V_78 ) ,
V_45 * V_79 ) ;
V_82 = F_53 ( V_48 ) ;
V_85 = F_23 ( V_82 ) ;
V_86 = F_13 ( F_24 ( V_80 ) ) ;
F_15 ( & V_86 ) ;
F_1 ( F_11 ( V_85 , V_77 ) ,
& V_86 , sizeof( T_4 ) ) ;
V_86 = F_13 ( F_24 ( V_81 ) ) ;
F_15 ( & V_86 ) ;
V_41 = F_12 ( sizeof( T_4 ) , V_85 , V_77 + 1 ,
F_5 ( V_84 -> V_19 [ 0 ] ) , & V_86 ) ;
if ( V_41 ) {
F_25 ( V_48 -> V_39 , V_81 ) ;
return V_41 ;
}
if ( V_11 < F_5 ( V_84 -> V_19 [ 0 ] ) ) {
F_25 ( V_48 -> V_39 , V_81 ) ;
V_48 -> V_87 [ 1 ] = V_80 ;
} else {
F_25 ( V_48 -> V_39 , V_80 ) ;
V_48 -> V_87 [ 1 ] = V_81 ;
}
return 0 ;
}
static int F_54 ( struct V_76 * V_48 , T_2 V_11 )
{
int V_41 ;
T_1 V_45 ;
unsigned V_78 , V_79 ;
struct V_42 * V_80 , * V_81 , * V_88 ;
struct V_9 * V_85 , * V_83 , * V_84 ;
T_4 V_89 ;
V_88 = F_52 ( V_48 ) ;
V_41 = F_20 ( V_48 -> V_39 , & V_80 ) ;
if ( V_41 < 0 )
return V_41 ;
V_41 = F_20 ( V_48 -> V_39 , & V_81 ) ;
if ( V_41 < 0 ) {
F_25 ( V_48 -> V_39 , V_80 ) ;
return V_41 ;
}
V_85 = F_23 ( V_88 ) ;
V_83 = F_23 ( V_80 ) ;
V_84 = F_23 ( V_81 ) ;
V_78 = F_4 ( V_85 -> V_15 . V_16 ) / 2 ;
V_79 = F_4 ( V_85 -> V_15 . V_16 ) - V_78 ;
V_83 -> V_15 . V_25 = V_85 -> V_15 . V_25 ;
V_83 -> V_15 . V_16 = F_17 ( V_78 ) ;
V_83 -> V_15 . V_33 = V_85 -> V_15 . V_33 ;
V_83 -> V_15 . V_29 = V_85 -> V_15 . V_29 ;
V_84 -> V_15 . V_25 = V_85 -> V_15 . V_25 ;
V_84 -> V_15 . V_16 = F_17 ( V_79 ) ;
V_84 -> V_15 . V_33 = V_85 -> V_15 . V_33 ;
V_84 -> V_15 . V_29 = V_85 -> V_15 . V_29 ;
memcpy ( V_83 -> V_19 , V_85 -> V_19 , V_78 * sizeof( V_85 -> V_19 [ 0 ] ) ) ;
memcpy ( V_84 -> V_19 , V_85 -> V_19 + V_78 , V_79 * sizeof( V_85 -> V_19 [ 0 ] ) ) ;
V_45 = F_4 ( V_85 -> V_15 . V_25 ) & V_26 ?
sizeof( T_4 ) : V_48 -> V_39 -> V_44 . V_45 ;
memcpy ( F_11 ( V_83 , 0 ) , F_11 ( V_85 , 0 ) , V_78 * V_45 ) ;
memcpy ( F_11 ( V_84 , 0 ) , F_11 ( V_85 , V_78 ) ,
V_79 * V_45 ) ;
V_85 -> V_15 . V_25 = F_17 ( V_26 ) ;
V_85 -> V_15 . V_16 = F_17 ( 2 ) ;
V_85 -> V_15 . V_33 = F_17 (
F_18 ( sizeof( T_4 ) ,
F_21 (
F_22 ( V_48 -> V_39 -> V_21 ) ) ) ) ;
V_85 -> V_15 . V_29 = F_17 ( sizeof( T_4 ) ) ;
V_89 = F_13 ( F_24 ( V_80 ) ) ;
F_15 ( & V_89 ) ;
V_85 -> V_19 [ 0 ] = V_83 -> V_19 [ 0 ] ;
F_1 ( F_11 ( V_85 , 0 ) , & V_89 , sizeof( T_4 ) ) ;
V_89 = F_13 ( F_24 ( V_81 ) ) ;
F_15 ( & V_89 ) ;
V_85 -> V_19 [ 1 ] = V_84 -> V_19 [ 0 ] ;
F_1 ( F_11 ( V_85 , 1 ) , & V_89 , sizeof( T_4 ) ) ;
if ( V_48 -> V_87 [ 0 ] != V_88 ) {
F_25 ( V_48 -> V_39 , V_48 -> V_87 [ 0 ] ) ;
V_48 -> V_87 [ 0 ] = V_88 ;
}
if ( V_11 < F_5 ( V_84 -> V_19 [ 0 ] ) ) {
F_25 ( V_48 -> V_39 , V_81 ) ;
V_48 -> V_87 [ 1 ] = V_80 ;
} else {
F_25 ( V_48 -> V_39 , V_80 ) ;
V_48 -> V_87 [ 1 ] = V_81 ;
}
V_48 -> V_90 = 2 ;
return 0 ;
}
static int F_55 ( struct V_76 * V_48 , T_5 V_40 ,
struct V_22 * V_23 ,
T_2 V_11 , unsigned * V_7 )
{
int V_41 , V_24 = * V_7 , V_51 = 1 ;
struct V_9 * V_30 ;
for (; ; ) {
V_41 = F_56 ( V_48 , V_40 , V_23 ) ;
if ( V_41 < 0 )
return V_41 ;
V_30 = F_23 ( F_52 ( V_48 ) ) ;
if ( F_57 ( V_48 ) && V_24 >= 0 ) {
T_4 V_86 = F_13 ( F_24 ( F_52 ( V_48 ) ) ) ;
F_15 ( & V_86 ) ;
F_1 ( F_11 ( F_23 ( F_53 ( V_48 ) ) , V_24 ) ,
& V_86 , sizeof( T_4 ) ) ;
}
V_30 = F_23 ( F_52 ( V_48 ) ) ;
if ( V_30 -> V_15 . V_16 == V_30 -> V_15 . V_33 ) {
if ( V_51 )
V_41 = F_54 ( V_48 , V_11 ) ;
else
V_41 = F_51 ( V_48 , V_24 , V_11 ) ;
if ( V_41 < 0 )
return V_41 ;
}
V_30 = F_23 ( F_52 ( V_48 ) ) ;
V_24 = F_6 ( V_30 , V_11 ) ;
if ( F_4 ( V_30 -> V_15 . V_25 ) & V_46 )
break;
if ( V_24 < 0 ) {
V_30 -> V_19 [ 0 ] = F_13 ( V_11 ) ;
V_24 = 0 ;
}
V_40 = F_10 ( V_30 , V_24 ) ;
V_51 = 0 ;
}
if ( V_24 < 0 || F_5 ( V_30 -> V_19 [ V_24 ] ) != V_11 )
V_24 ++ ;
* V_7 = V_24 ;
return 0 ;
}
static bool F_58 ( struct V_9 * V_30 , T_2 * V_19 ,
unsigned V_57 , unsigned V_7 )
{
return ( ( V_7 >= F_4 ( V_30 -> V_15 . V_16 ) ) ||
( F_5 ( V_30 -> V_19 [ V_7 ] ) != V_19 [ V_57 ] ) ) ;
}
static int F_59 ( struct V_38 * V_39 , T_5 V_40 ,
T_2 * V_19 , void * V_31 , T_5 * V_91 ,
int * V_92 )
__dm_written_to_disk( V_31 )
{
int V_41 ;
unsigned V_57 , V_7 = - 1 , V_72 = V_39 -> V_58 - 1 ;
T_5 V_67 = V_40 ;
struct V_76 V_53 ;
struct V_9 * V_10 ;
struct V_22 V_93 ;
F_60 ( V_39 -> V_21 , & V_93 ) ;
F_61 ( & V_53 , V_39 ) ;
for ( V_57 = 0 ; V_57 < ( V_39 -> V_58 - 1 ) ; V_57 ++ ) {
V_41 = F_55 ( & V_53 , V_67 , & V_93 , V_19 [ V_57 ] , & V_7 ) ;
if ( V_41 < 0 )
goto V_94;
V_10 = F_23 ( F_52 ( & V_53 ) ) ;
if ( F_58 ( V_10 , V_19 , V_57 , V_7 ) ) {
T_5 V_95 ;
T_4 V_96 ;
V_41 = F_19 ( V_39 , & V_95 ) ;
if ( V_41 < 0 )
goto V_94;
V_96 = F_13 ( V_95 ) ;
F_15 ( & V_96 ) ;
V_41 = F_12 ( sizeof( T_2 ) , V_10 , V_7 ,
V_19 [ V_57 ] , & V_96 ) ;
if ( V_41 )
goto V_94;
}
if ( V_57 < V_72 )
V_67 = F_10 ( V_10 , V_7 ) ;
}
V_41 = F_55 ( & V_53 , V_67 , & V_39 -> V_44 ,
V_19 [ V_57 ] , & V_7 ) ;
if ( V_41 < 0 )
goto V_94;
V_10 = F_23 ( F_52 ( & V_53 ) ) ;
if ( F_58 ( V_10 , V_19 , V_57 , V_7 ) ) {
if ( V_92 )
* V_92 = 1 ;
V_41 = F_12 ( V_39 -> V_44 . V_45 , V_10 , V_7 ,
V_19 [ V_57 ] , V_31 ) ;
if ( V_41 )
goto V_97;
} else {
if ( V_92 )
* V_92 = 0 ;
if ( V_39 -> V_44 . V_65 &&
( ! V_39 -> V_44 . V_98 ||
! V_39 -> V_44 . V_98 (
V_39 -> V_44 . V_28 ,
F_11 ( V_10 , V_7 ) ,
V_31 ) ) ) {
V_39 -> V_44 . V_65 ( V_39 -> V_44 . V_28 ,
F_11 ( V_10 , V_7 ) ) ;
}
F_1 ( F_11 ( V_10 , V_7 ) ,
V_31 , V_39 -> V_44 . V_45 ) ;
}
* V_91 = F_62 ( & V_53 ) ;
F_63 ( & V_53 ) ;
return 0 ;
V_94:
F_2 ( V_31 ) ;
V_97:
F_63 ( & V_53 ) ;
return V_41 ;
}
int F_64 ( struct V_38 * V_39 , T_5 V_40 ,
T_2 * V_19 , void * V_31 , T_5 * V_91 )
__dm_written_to_disk( V_31 )
{
return F_59 ( V_39 , V_40 , V_19 , V_31 , V_91 , NULL ) ;
}
int F_65 ( struct V_38 * V_39 , T_5 V_40 ,
T_2 * V_19 , void * V_31 , T_5 * V_91 ,
int * V_92 )
__dm_written_to_disk( V_31 )
{
return F_59 ( V_39 , V_40 , V_19 , V_31 , V_91 , V_92 ) ;
}
static int F_66 ( struct V_66 * V_48 , T_5 V_67 , bool V_99 ,
T_2 * V_68 , T_5 * V_100 )
{
int V_24 , V_41 ;
T_3 V_25 ;
do {
V_41 = F_43 ( V_48 , V_67 ) ;
if ( V_41 < 0 )
return V_41 ;
V_25 = F_4 ( F_44 ( V_48 ) -> V_15 . V_25 ) ;
V_24 = F_4 ( F_44 ( V_48 ) -> V_15 . V_16 ) ;
if ( ! V_24 )
return - V_70 ;
else
V_24 -- ;
if ( V_99 )
* V_68 = F_5 ( F_44 ( V_48 ) -> V_19 [ V_24 ] ) ;
else
* V_68 = F_5 ( F_44 ( V_48 ) -> V_19 [ 0 ] ) ;
if ( V_100 || V_25 & V_26 )
V_67 = F_10 ( F_44 ( V_48 ) , V_24 ) ;
} while ( V_25 & V_26 );
if ( V_100 )
* V_100 = V_67 ;
return 0 ;
}
static int F_67 ( struct V_38 * V_39 , T_5 V_40 ,
bool V_99 , T_2 * V_101 )
{
int V_41 = 0 , V_90 = 0 , V_57 ;
struct V_66 V_53 ;
F_46 ( & V_53 , V_39 ) ;
for ( V_57 = 0 ; V_57 < V_39 -> V_58 ; V_57 ++ ) {
V_41 = F_66 ( & V_53 , V_40 , V_99 , V_101 + V_57 ,
V_57 == V_39 -> V_58 - 1 ? NULL : & V_40 ) ;
if ( V_41 == - V_70 ) {
V_41 = 0 ;
break;
} else if ( V_41 )
break;
V_90 ++ ;
}
F_47 ( & V_53 ) ;
return V_41 ? V_41 : V_90 ;
}
int F_68 ( struct V_38 * V_39 , T_5 V_40 ,
T_2 * V_101 )
{
return F_67 ( V_39 , V_40 , true , V_101 ) ;
}
int F_69 ( struct V_38 * V_39 , T_5 V_40 ,
T_2 * V_101 )
{
return F_67 ( V_39 , V_40 , false , V_101 ) ;
}
static int F_70 ( struct V_38 * V_39 , T_5 V_67 ,
int (* F_71)( void * V_28 , T_2 * V_19 , void * V_102 ) ,
void * V_28 )
{
int V_41 ;
unsigned V_24 , V_103 ;
struct V_42 * V_30 ;
struct V_9 * V_10 ;
T_2 V_19 ;
V_41 = F_49 ( V_39 , V_67 , & V_30 ) ;
if ( V_41 )
return V_41 ;
V_10 = F_23 ( V_30 ) ;
V_103 = F_4 ( V_10 -> V_15 . V_16 ) ;
for ( V_24 = 0 ; V_24 < V_103 ; V_24 ++ ) {
if ( F_4 ( V_10 -> V_15 . V_25 ) & V_26 ) {
V_41 = F_70 ( V_39 , F_10 ( V_10 , V_24 ) , F_71 , V_28 ) ;
if ( V_41 )
goto V_64;
} else {
V_19 = F_5 ( * F_72 ( V_10 , V_24 ) ) ;
V_41 = F_71 ( V_28 , & V_19 , F_11 ( V_10 , V_24 ) ) ;
if ( V_41 )
goto V_64;
}
}
V_64:
F_36 ( V_39 -> V_21 , V_30 ) ;
return V_41 ;
}
int F_73 ( struct V_38 * V_39 , T_5 V_40 ,
int (* F_71)( void * V_28 , T_2 * V_19 , void * V_102 ) ,
void * V_28 )
{
F_74 ( V_39 -> V_58 > 1 ) ;
return F_70 ( V_39 , V_40 , F_71 , V_28 ) ;
}
static void F_75 ( struct V_104 * V_105 )
{
unsigned V_24 , V_103 ;
T_4 V_71 ;
struct V_106 * V_10 = V_105 -> V_87 + V_105 -> V_107 - 1 ;
struct V_9 * V_108 = F_23 ( V_10 -> V_43 ) ;
struct V_54 * V_55 = F_22 ( V_105 -> V_39 -> V_21 ) ;
F_74 ( V_105 -> V_39 -> V_44 . V_45 != sizeof( V_71 ) ) ;
V_103 = F_4 ( V_108 -> V_15 . V_16 ) ;
for ( V_24 = 0 ; V_24 < V_103 ; V_24 ++ ) {
memcpy ( & V_71 , F_11 ( V_108 , V_24 ) , sizeof( V_71 ) ) ;
F_29 ( V_55 , F_5 ( V_71 ) ) ;
}
}
static bool F_76 ( struct V_104 * V_105 )
{
struct V_106 * V_10 = V_105 -> V_87 + V_105 -> V_107 - 1 ;
struct V_9 * V_108 = F_23 ( V_10 -> V_43 ) ;
return F_4 ( V_108 -> V_15 . V_25 ) & V_46 ;
}
static int F_77 ( struct V_104 * V_105 , T_5 V_43 )
{
int V_41 ;
struct V_106 * V_10 = V_105 -> V_87 + V_105 -> V_107 ;
if ( V_105 -> V_107 >= V_109 - 1 ) {
F_14 ( L_4 ) ;
return - V_52 ;
}
V_41 = F_49 ( V_105 -> V_39 , V_43 , & V_10 -> V_43 ) ;
if ( V_41 )
return V_41 ;
V_10 -> V_7 = 0 ;
V_105 -> V_107 ++ ;
if ( V_105 -> V_110 || ! F_76 ( V_105 ) )
F_75 ( V_105 ) ;
return 0 ;
}
static void F_78 ( struct V_104 * V_105 )
{
V_105 -> V_107 -- ;
F_25 ( V_105 -> V_39 , V_105 -> V_87 [ V_105 -> V_107 ] . V_43 ) ;
}
static int F_79 ( struct V_104 * V_105 )
{
struct V_106 * V_10 ;
struct V_9 * V_108 ;
for (; ; ) {
if ( ! V_105 -> V_107 )
return - V_70 ;
V_10 = V_105 -> V_87 + V_105 -> V_107 - 1 ;
V_108 = F_23 ( V_10 -> V_43 ) ;
V_10 -> V_7 ++ ;
if ( V_10 -> V_7 < F_4 ( V_108 -> V_15 . V_16 ) )
break;
F_78 ( V_105 ) ;
}
return 0 ;
}
static int F_80 ( struct V_104 * V_105 )
{
int V_41 = 0 ;
struct V_106 * V_10 ;
struct V_9 * V_108 ;
T_4 V_71 ;
for (; ; ) {
V_10 = V_105 -> V_87 + V_105 -> V_107 - 1 ;
V_108 = F_23 ( V_10 -> V_43 ) ;
if ( F_4 ( V_108 -> V_15 . V_25 ) & V_46 )
break;
memcpy ( & V_71 , F_11 ( V_108 , V_10 -> V_7 ) , sizeof( V_71 ) ) ;
V_41 = F_77 ( V_105 , F_5 ( V_71 ) ) ;
if ( V_41 ) {
F_14 ( L_5 ) ;
break;
}
}
if ( ! V_41 && ( F_4 ( V_108 -> V_15 . V_16 ) == 0 ) )
return - V_70 ;
return V_41 ;
}
int F_81 ( struct V_38 * V_39 , T_5 V_40 ,
bool V_110 , struct V_104 * V_105 )
{
int V_41 ;
V_105 -> V_39 = V_39 ;
V_105 -> V_40 = V_40 ;
V_105 -> V_107 = 0 ;
V_105 -> V_110 = V_110 ;
V_41 = F_77 ( V_105 , V_40 ) ;
if ( V_41 )
return V_41 ;
return F_80 ( V_105 ) ;
}
void F_82 ( struct V_104 * V_105 )
{
while ( V_105 -> V_107 )
F_78 ( V_105 ) ;
}
int F_83 ( struct V_104 * V_105 )
{
int V_41 = F_79 ( V_105 ) ;
if ( ! V_41 ) {
V_41 = F_80 ( V_105 ) ;
if ( V_41 )
F_14 ( L_6 ) ;
}
return V_41 ;
}
int F_84 ( struct V_104 * V_105 , T_3 V_90 )
{
int V_41 = 0 ;
while ( V_90 -- && ! V_41 )
V_41 = F_83 ( V_105 ) ;
return V_41 ;
}
int F_85 ( struct V_104 * V_105 , T_2 * V_11 , void * V_71 )
{
if ( V_105 -> V_107 ) {
struct V_106 * V_10 = V_105 -> V_87 + V_105 -> V_107 - 1 ;
struct V_9 * V_108 = F_23 ( V_10 -> V_43 ) ;
if ( F_4 ( V_108 -> V_15 . V_25 ) & V_26 )
return - V_52 ;
* V_11 = F_5 ( * F_72 ( V_108 , V_10 -> V_7 ) ) ;
memcpy ( V_71 , F_11 ( V_108 , V_10 -> V_7 ) , V_105 -> V_39 -> V_44 . V_45 ) ;
return 0 ;
} else
return - V_70 ;
}
