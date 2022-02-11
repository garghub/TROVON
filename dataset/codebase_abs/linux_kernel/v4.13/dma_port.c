static bool F_1 ( const struct V_1 * V_2 ,
const struct V_3 * V_4 )
{
T_1 V_5 = F_2 ( V_4 -> V_6 ) & ~ F_3 ( 63 ) ;
if ( V_4 -> V_7 . V_8 == V_9 )
return true ;
if ( V_4 -> V_7 . V_8 != V_2 -> V_10 )
return false ;
if ( V_5 != F_2 ( V_2 -> V_11 ) )
return false ;
if ( V_4 -> V_7 . V_12 != V_2 -> V_13 )
return false ;
return true ;
}
static bool F_4 ( struct V_1 * V_2 , const struct V_3 * V_4 )
{
memcpy ( V_2 -> V_14 , V_4 -> V_6 , V_2 -> V_13 ) ;
return true ;
}
static int F_5 ( struct V_15 * V_16 , void * V_6 , T_1 V_5 ,
T_2 V_17 , T_2 V_18 , T_2 V_19 , int V_20 )
{
struct V_21 V_11 = {
. V_22 = F_6 ( V_5 ) ,
. V_23 = {
. V_24 = 1 ,
. V_17 = V_17 ,
. V_25 = V_26 ,
. V_18 = V_18 ,
. V_19 = V_19 ,
} ,
} ;
struct V_1 * V_2 ;
struct V_27 V_28 ;
struct V_29 V_30 ;
V_2 = F_7 () ;
if ( ! V_2 )
return - V_31 ;
V_2 -> V_32 = F_1 ;
V_2 -> V_33 = F_4 ;
V_2 -> V_11 = & V_11 ;
V_2 -> V_34 = sizeof( V_11 ) ;
V_2 -> V_35 = V_36 ;
V_2 -> V_14 = & V_28 ;
V_2 -> V_13 = 12 + 4 * V_19 ;
V_2 -> V_10 = V_36 ;
V_30 = F_8 ( V_16 , V_2 , V_20 ) ;
F_9 ( V_2 ) ;
if ( V_30 . V_37 )
return V_30 . V_37 ;
memcpy ( V_6 , & V_28 . V_38 , 4 * V_19 ) ;
return 0 ;
}
static int F_10 ( struct V_15 * V_16 , const void * V_6 , T_1 V_5 ,
T_2 V_17 , T_2 V_18 , T_2 V_19 , int V_20 )
{
struct V_27 V_11 = {
. V_22 = F_6 ( V_5 ) ,
. V_23 = {
. V_24 = 1 ,
. V_17 = V_17 ,
. V_25 = V_26 ,
. V_18 = V_18 ,
. V_19 = V_19 ,
} ,
} ;
struct V_1 * V_2 ;
struct V_21 V_28 ;
struct V_29 V_30 ;
memcpy ( & V_11 . V_38 , V_6 , V_19 * 4 ) ;
V_2 = F_7 () ;
if ( ! V_2 )
return - V_31 ;
V_2 -> V_32 = F_1 ;
V_2 -> V_33 = F_4 ;
V_2 -> V_11 = & V_11 ;
V_2 -> V_34 = 12 + 4 * V_19 ;
V_2 -> V_35 = V_39 ;
V_2 -> V_14 = & V_28 ;
V_2 -> V_13 = sizeof( V_28 ) ;
V_2 -> V_10 = V_39 ;
V_30 = F_8 ( V_16 , V_2 , V_20 ) ;
F_9 ( V_2 ) ;
return V_30 . V_37 ;
}
static int F_11 ( struct V_40 * V_41 )
{
int V_17 , V_42 ;
T_2 type ;
V_17 = 5 ;
V_42 = F_5 ( V_41 -> V_43 -> V_16 , & type , F_12 ( V_41 ) , V_17 , 2 , 1 ,
V_44 ) ;
if ( ! V_42 && ( type & 0xffffff ) == V_45 )
return V_17 ;
V_17 = 3 ;
V_42 = F_5 ( V_41 -> V_43 -> V_16 , & type , F_12 ( V_41 ) , V_17 , 2 , 1 ,
V_44 ) ;
if ( ! V_42 && ( type & 0xffffff ) == V_45 )
return V_17 ;
return - V_46 ;
}
struct V_47 * F_13 ( struct V_40 * V_41 )
{
struct V_47 * V_48 ;
int V_17 ;
V_17 = F_11 ( V_41 ) ;
if ( V_17 < 0 )
return NULL ;
V_48 = F_14 ( sizeof( * V_48 ) , V_49 ) ;
if ( ! V_48 )
return NULL ;
V_48 -> V_50 = F_15 ( V_51 , sizeof( T_2 ) , V_49 ) ;
if ( ! V_48 -> V_50 ) {
F_16 ( V_48 ) ;
return NULL ;
}
V_48 -> V_41 = V_41 ;
V_48 -> V_17 = V_17 ;
V_48 -> V_52 = V_53 ;
return V_48 ;
}
void F_17 ( struct V_47 * V_48 )
{
if ( V_48 ) {
F_16 ( V_48 -> V_50 ) ;
F_16 ( V_48 ) ;
}
}
static int F_18 ( struct V_47 * V_48 ,
unsigned int V_54 )
{
unsigned long V_55 = V_56 + F_19 ( V_54 ) ;
struct V_40 * V_41 = V_48 -> V_41 ;
do {
int V_42 ;
T_2 V_57 ;
V_42 = F_5 ( V_41 -> V_43 -> V_16 , & V_57 , F_12 ( V_41 ) , V_48 -> V_17 ,
V_48 -> V_52 + V_58 , 1 , 50 ) ;
if ( V_42 ) {
if ( V_42 != - V_59 )
return V_42 ;
} else if ( ! ( V_57 & V_60 ) ) {
return 0 ;
}
F_20 ( 50 , 100 ) ;
} while ( F_21 ( V_56 , V_55 ) );
return - V_59 ;
}
static int F_22 ( T_2 V_61 )
{
switch ( V_61 & V_62 ) {
case V_63 :
return 0 ;
case V_64 :
return - V_65 ;
case V_66 :
return - V_67 ;
}
return - V_68 ;
}
static int F_23 ( struct V_47 * V_48 , T_2 V_57 ,
unsigned int V_54 )
{
struct V_40 * V_41 = V_48 -> V_41 ;
T_2 V_69 ;
int V_42 ;
V_42 = F_10 ( V_41 -> V_43 -> V_16 , & V_57 , F_12 ( V_41 ) , V_48 -> V_17 ,
V_48 -> V_52 + V_58 , 1 , V_44 ) ;
if ( V_42 )
return V_42 ;
V_42 = F_18 ( V_48 , V_54 ) ;
if ( V_42 )
return V_42 ;
V_42 = F_5 ( V_41 -> V_43 -> V_16 , & V_69 , F_12 ( V_41 ) , V_48 -> V_17 ,
V_48 -> V_52 + V_70 , 1 , V_44 ) ;
if ( V_42 )
return V_42 ;
return F_22 ( V_69 ) ;
}
static int F_24 ( struct V_47 * V_48 , T_2 V_71 ,
void * V_50 , T_2 V_12 )
{
struct V_40 * V_41 = V_48 -> V_41 ;
T_2 V_57 , V_72 , V_73 ;
int V_42 ;
V_72 = V_71 / 4 ;
V_73 = V_12 / 4 ;
V_57 = V_74 << V_75 ;
if ( V_73 < V_51 )
V_57 |= ( V_73 << V_76 ) & V_77 ;
V_57 |= ( V_72 << V_78 ) & V_79 ;
V_57 |= V_60 ;
V_42 = F_23 ( V_48 , V_57 , V_44 ) ;
if ( V_42 )
return V_42 ;
return F_5 ( V_41 -> V_43 -> V_16 , V_50 , F_12 ( V_41 ) , V_48 -> V_17 ,
V_48 -> V_52 + V_80 , V_73 , V_44 ) ;
}
static int F_25 ( struct V_47 * V_48 , T_2 V_71 ,
const void * V_50 , T_2 V_12 )
{
struct V_40 * V_41 = V_48 -> V_41 ;
T_2 V_57 , V_72 , V_73 ;
int V_42 ;
V_73 = V_12 / 4 ;
V_42 = F_10 ( V_41 -> V_43 -> V_16 , V_50 , F_12 ( V_41 ) , V_48 -> V_17 ,
V_48 -> V_52 + V_80 , V_73 , V_44 ) ;
V_57 = V_81 << V_75 ;
if ( V_71 >= V_82 ) {
V_72 = V_82 ;
V_57 |= V_83 ;
} else {
V_72 = V_71 / 4 ;
}
V_57 |= ( ( V_73 - 1 ) << V_76 ) & V_77 ;
V_57 |= ( V_72 << V_78 ) & V_79 ;
V_57 |= V_60 ;
return F_23 ( V_48 , V_57 , V_44 ) ;
}
int F_26 ( struct V_47 * V_48 , unsigned int V_71 ,
void * V_50 , T_3 V_12 )
{
unsigned int V_84 = V_85 ;
unsigned int V_18 ;
V_18 = V_71 & 3 ;
V_71 = V_71 & ~ 3 ;
do {
T_2 V_86 = F_27 ( T_2 , V_12 , V_51 * 4 ) ;
int V_42 ;
V_42 = F_24 ( V_48 , V_71 , V_48 -> V_50 ,
F_28 ( V_86 , 4 ) ) ;
if ( V_42 ) {
if ( V_42 == - V_59 ) {
if ( V_84 -- )
continue;
V_42 = - V_68 ;
}
return V_42 ;
}
memcpy ( V_50 , V_48 -> V_50 + V_18 , V_86 ) ;
V_12 -= V_86 ;
V_71 += V_86 ;
V_50 += V_86 ;
} while ( V_12 > 0 );
return 0 ;
}
int F_29 ( struct V_47 * V_48 , unsigned int V_71 ,
const void * V_50 , T_3 V_12 )
{
unsigned int V_84 = V_85 ;
unsigned int V_18 ;
if ( V_71 >= V_82 ) {
V_18 = 0 ;
if ( V_12 > V_87 )
return - V_88 ;
} else {
V_18 = V_71 & 3 ;
V_71 = V_71 & ~ 3 ;
}
do {
T_2 V_86 = F_27 ( T_2 , V_12 , V_51 * 4 ) ;
int V_42 ;
memcpy ( V_48 -> V_50 + V_18 , V_50 , V_86 ) ;
V_42 = F_25 ( V_48 , V_71 , V_50 , V_86 ) ;
if ( V_42 ) {
if ( V_42 == - V_59 ) {
if ( V_84 -- )
continue;
V_42 = - V_68 ;
}
return V_42 ;
}
V_12 -= V_86 ;
V_71 += V_86 ;
V_50 += V_86 ;
} while ( V_12 > 0 );
return 0 ;
}
int F_30 ( struct V_47 * V_48 )
{
T_2 V_57 ;
V_57 = V_89 << V_75 ;
V_57 |= V_60 ;
return F_23 ( V_48 , V_57 , 150 ) ;
}
int F_31 ( struct V_47 * V_48 , T_2 * V_61 )
{
struct V_40 * V_41 = V_48 -> V_41 ;
T_2 V_69 , V_90 ;
int V_42 ;
V_42 = F_5 ( V_41 -> V_43 -> V_16 , & V_69 , F_12 ( V_41 ) , V_48 -> V_17 ,
V_48 -> V_52 + V_70 , 1 , V_44 ) ;
if ( V_42 )
return V_42 ;
V_90 = ( V_69 & V_91 ) >> V_92 ;
if ( V_90 == V_89 ) {
if ( V_61 )
* V_61 = V_69 & V_62 ;
return 1 ;
}
return 0 ;
}
int F_32 ( struct V_47 * V_48 )
{
T_2 V_57 ;
V_57 = V_93 << V_75 ;
V_57 |= V_60 ;
return F_23 ( V_48 , V_57 , 150 ) ;
}
