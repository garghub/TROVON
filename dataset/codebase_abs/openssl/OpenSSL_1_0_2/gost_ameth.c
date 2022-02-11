int F_1 ( T_1 * V_1 )
{
T_2 * V_2 ;
T_3 * V_3 = F_2 () ;
for ( V_2 = V_4 ; V_2 -> V_3 != NULL ; V_2 ++ ) {
F_3 ( & V_3 , V_2 -> V_3 ) ;
if ( ! F_4 ( V_3 , V_1 -> V_3 ) ) {
F_5 ( V_3 ) ;
return V_2 -> V_5 ;
}
}
F_5 ( V_3 ) ;
return V_6 ;
}
static T_4 * F_6 ( const T_5 * V_7 )
{
T_4 * V_8 = F_7 () ;
T_6 * V_9 = F_8 () ;
int V_10 = V_6 ;
if ( ! V_8 || ! V_9 ) {
F_9 ( V_11 , V_12 ) ;
F_10 ( V_8 ) ;
V_8 = NULL ;
goto V_13;
}
switch ( F_11 ( V_7 ) ) {
case V_14 :
V_10 =
F_12 ( F_13
( F_14 ( ( T_5 * ) V_7 ) ) ) ;
break;
case V_15 :
V_10 =
( int ) F_1 ( F_14 ( ( T_5 * ) V_7 ) ) ;
if ( V_10 == V_6 ) {
F_9 ( V_11 ,
V_16 ) ;
F_10 ( V_8 ) ;
V_8 = NULL ;
goto V_13;
}
break;
}
V_9 -> V_17 = F_15 ( V_10 ) ;
V_9 -> V_18 = F_15 ( V_19 ) ;
V_8 -> V_20 = F_16 ( V_9 , & V_8 -> V_21 ) ;
if ( V_8 -> V_20 <= 0 ) {
F_9 ( V_11 , V_12 ) ;
F_10 ( V_8 ) ;
V_8 = NULL ;
goto V_13;
}
V_8 -> type = V_22 ;
V_13:
F_17 ( V_9 ) ;
return V_8 ;
}
static int F_18 ( T_5 * V_23 , T_7 * V_24 )
{
T_8 * V_25 = NULL ;
int V_26 = V_27 ;
int V_28 = V_6 , V_29 = V_6 ;
void * V_30 ;
T_4 * V_31 = NULL ;
const unsigned char * V_1 ;
T_6 * V_9 = NULL ;
F_19 ( & V_25 , & V_26 , & V_30 , V_24 ) ;
V_31 = V_30 ;
if ( V_26 != V_22 ) {
F_9 ( V_32 ,
V_33 ) ;
return 0 ;
}
V_1 = V_31 -> V_21 ;
V_28 = F_20 ( V_25 ) ;
V_9 = F_21 ( NULL , & V_1 , V_31 -> V_20 ) ;
if ( ! V_9 ) {
F_9 ( V_32 ,
V_34 ) ;
return 0 ;
}
V_29 = F_20 ( V_9 -> V_17 ) ;
F_17 ( V_9 ) ;
F_22 ( V_23 , V_28 ) ;
switch ( V_28 ) {
case V_15 :
{
T_1 * V_35 = F_14 ( V_23 ) ;
if ( ! V_35 ) {
V_35 = F_23 () ;
if ( ! F_24 ( V_23 , V_28 , V_35 ) )
return 0 ;
}
if ( ! F_25 ( V_35 , V_29 ) )
return 0 ;
break;
}
case V_14 :
{
T_9 * V_36 = F_14 ( V_23 ) ;
if ( ! V_36 ) {
V_36 = F_26 () ;
if ( ! F_24 ( V_23 , V_28 , V_36 ) )
return 0 ;
}
if ( ! F_27 ( V_36 , V_29 ) )
return 0 ;
}
}
return 1 ;
}
static int F_28 ( T_5 * V_23 , T_3 * V_37 )
{
switch ( F_11 ( V_23 ) ) {
case V_15 :
{
T_1 * V_35 = F_14 ( V_23 ) ;
if ( ! V_35 ) {
V_35 = F_23 () ;
F_24 ( V_23 , F_11 ( V_23 ) , V_35 ) ;
}
V_35 -> V_38 = F_29 ( V_37 ) ;
if ( ! F_30 ( V_23 ) )
F_31 ( V_35 ) ;
break;
}
case V_14 :
{
T_9 * V_36 = F_14 ( V_23 ) ;
if ( ! V_36 ) {
V_36 = F_26 () ;
F_24 ( V_23 , F_11 ( V_23 ) , V_36 ) ;
}
if ( ! F_32 ( V_36 , V_37 ) )
return 0 ;
if ( ! F_30 ( V_23 ) )
F_33 ( V_36 ) ;
break;
}
}
return 1 ;
}
T_3 * F_34 ( const T_5 * V_23 )
{
switch ( F_11 ( V_23 ) ) {
case V_15 :
{
T_1 * V_35 = F_14 ( ( T_5 * ) V_23 ) ;
if ( ! V_35 ) {
return NULL ;
}
if ( ! V_35 -> V_38 )
return NULL ;
return V_35 -> V_38 ;
break;
}
case V_14 :
{
T_9 * V_36 = F_14 ( ( T_5 * ) V_23 ) ;
const T_3 * V_37 ;
if ( ! V_36 ) {
return NULL ;
}
if ( ! ( V_37 = F_35 ( V_36 ) ) )
return NULL ;
return ( T_3 * ) V_37 ;
break;
}
}
return NULL ;
}
static int F_36 ( T_5 * V_23 , int V_39 , long V_40 , void * V_41 )
{
switch ( V_39 ) {
case V_42 :
if ( V_40 == 0 ) {
T_7 * V_43 = NULL , * V_44 = NULL ;
int V_5 = F_11 ( V_23 ) ;
F_37 ( ( V_45 * ) V_41 ,
NULL , & V_43 , & V_44 ) ;
F_38 ( V_43 , F_15 ( V_46 ) ,
V_47 , 0 ) ;
if ( V_5 == V_6 ) {
return ( - 1 ) ;
}
F_38 ( V_44 , F_15 ( V_5 ) , V_47 , 0 ) ;
}
return 1 ;
#ifndef F_39
case V_48 :
if ( V_40 == 0 ) {
T_7 * V_43 = NULL , * V_44 = NULL ;
int V_5 = F_11 ( V_23 ) ;
F_40 ( ( V_49 * ) V_41 ,
NULL , NULL , & V_43 , & V_44 ) ;
F_38 ( V_43 , F_15 ( V_46 ) ,
V_47 , 0 ) ;
if ( V_5 == V_6 ) {
return ( - 1 ) ;
}
F_38 ( V_44 , F_15 ( V_5 ) , V_47 , 0 ) ;
}
return 1 ;
#endif
case V_50 :
if ( V_40 == 0 ) {
T_7 * V_51 ;
T_4 * V_8 = F_6 ( V_23 ) ;
if ( ! V_8 ) {
return - 1 ;
}
F_41 ( ( V_52 * ) V_41 , & V_51 ) ;
F_38 ( V_51 , F_15 ( V_23 -> type ) ,
V_22 , V_8 ) ;
}
return 1 ;
#ifndef F_39
case V_53 :
if ( V_40 == 0 ) {
T_7 * V_51 = NULL ;
T_4 * V_8 = F_6 ( V_23 ) ;
if ( ! V_8 ) {
return - 1 ;
}
F_42 ( ( V_54 * ) V_41 , NULL ,
NULL , & V_51 ) ;
F_38 ( V_51 , F_15 ( V_23 -> type ) , V_22 ,
V_8 ) ;
}
return 1 ;
#endif
case V_55 :
* ( int * ) V_41 = V_46 ;
return 2 ;
}
return - 2 ;
}
static void F_43 ( T_5 * V_7 )
{
if ( V_7 -> V_23 . V_35 ) {
F_44 ( V_7 -> V_23 . V_35 ) ;
}
}
static void F_45 ( T_5 * V_7 )
{
if ( V_7 -> V_23 . V_36 ) {
F_46 ( V_7 -> V_23 . V_36 ) ;
}
}
static int F_47 ( T_5 * V_56 , T_10 * V_57 )
{
const unsigned char * V_58 = NULL , * V_1 = NULL ;
int V_59 = 0 ;
T_3 * V_60 = NULL ;
int V_61 = 0 ;
T_7 * V_24 = NULL ;
T_8 * V_25 = NULL ;
T_11 * V_38 = NULL ;
if ( ! F_48 ( & V_25 , & V_58 , & V_59 , & V_24 , V_57 ) )
return 0 ;
V_1 = V_58 ;
if ( ! F_18 ( V_56 , V_24 ) ) {
return 0 ;
}
if ( V_62 == * V_1 ) {
unsigned char V_63 [ 32 ] ;
int V_64 ;
T_12 * V_65 = F_49 ( NULL , & V_1 , V_59 ) ;
if ( ! V_65 || V_65 -> V_20 != 32 ) {
F_9 ( V_66 , V_67 ) ;
return 0 ;
}
for ( V_64 = 0 ; V_64 < 32 ; V_64 ++ ) {
V_63 [ 31 - V_64 ] = V_65 -> V_21 [ V_64 ] ;
}
F_10 ( V_65 ) ;
V_60 = F_50 ( V_63 , 32 ) ;
} else {
V_38 = F_51 ( NULL , & V_1 , V_59 ) ;
if ( ! V_38 )
return 0 ;
V_61 = ( ( V_60 = F_52 ( V_38 , NULL ) ) != NULL ) ;
F_53 ( V_38 ) ;
if ( ! V_61 ) {
F_9 ( V_66 , V_67 ) ;
return 0 ;
}
}
V_61 = F_28 ( V_56 , V_60 ) ;
F_5 ( V_60 ) ;
return V_61 ;
}
static int F_54 ( T_10 * V_68 , const T_5 * V_56 )
{
T_8 * V_69 = F_15 ( F_11 ( V_56 ) ) ;
T_4 * V_8 = F_6 ( V_56 ) ;
unsigned char * V_70 = NULL ;
int V_59 ;
T_11 * V_71 = NULL ;
if ( ! V_8 ) {
return 0 ;
}
V_71 = F_55 ( F_34 ( V_56 ) , NULL ) ;
V_59 = F_56 ( V_71 , & V_70 ) ;
F_53 ( V_71 ) ;
return F_57 ( V_68 , V_69 , 0 , V_22 , V_8 ,
V_70 , V_59 ) ;
}
static int F_58 ( T_13 * V_72 , const T_5 * V_23 , int V_73 ,
T_14 * V_74 , int type )
{
int V_29 = V_6 ;
if ( type == 2 ) {
T_3 * V_7 ;
if ( ! F_59 ( V_72 , V_73 , 128 ) )
return 0 ;
F_60 ( V_72 , L_1 ) ;
V_7 = F_34 ( V_23 ) ;
if ( ! V_7 )
F_60 ( V_72 , L_2 ) ;
else
F_61 ( V_72 , V_7 ) ;
F_60 ( V_72 , L_3 ) ;
}
if ( type >= 1 ) {
T_3 * V_75 ;
V_75 = ( ( T_1 * ) F_14 ( ( T_5 * ) V_23 ) ) -> V_76 ;
F_59 ( V_72 , V_73 , 128 ) ;
F_60 ( V_72 , L_4 ) ;
F_61 ( V_72 , V_75 ) ;
F_60 ( V_72 , L_3 ) ;
}
V_29 = F_1 ( F_14 ( ( T_5 * ) V_23 ) ) ;
F_59 ( V_72 , V_73 , 128 ) ;
F_60 ( V_72 , L_5 , F_62 ( V_29 ) ) ;
return 1 ;
}
static int F_63 ( T_13 * V_72 , const T_5 * V_23 , int V_73 ,
T_14 * V_74 )
{
return F_58 ( V_72 , V_23 , V_73 , V_74 , 0 ) ;
}
static int F_64 ( T_13 * V_72 , const T_5 * V_23 , int V_73 ,
T_14 * V_74 )
{
return F_58 ( V_72 , V_23 , V_73 , V_74 , 1 ) ;
}
static int F_65 ( T_13 * V_72 , const T_5 * V_23 , int V_73 ,
T_14 * V_74 )
{
return F_58 ( V_72 , V_23 , V_73 , V_74 , 2 ) ;
}
static int F_66 ( T_13 * V_72 , const T_5 * V_23 , int V_73 ,
T_14 * V_74 , int type )
{
int V_29 = V_6 ;
if ( type == 2 ) {
T_3 * V_7 ;
if ( ! F_59 ( V_72 , V_73 , 128 ) )
return 0 ;
F_60 ( V_72 , L_1 ) ;
V_7 = F_34 ( V_23 ) ;
if ( ! V_7 )
F_60 ( V_72 , L_6 ) ;
else
F_61 ( V_72 , V_7 ) ;
F_60 ( V_72 , L_3 ) ;
}
if ( type >= 1 ) {
T_15 * V_77 = F_67 () ;
T_3 * V_78 , * V_79 ;
const T_16 * V_75 ;
const T_17 * V_80 ;
if ( ! V_77 ) {
F_9 ( V_81 , V_12 ) ;
return 0 ;
}
F_68 ( V_77 ) ;
V_78 = F_69 ( V_77 ) ;
V_79 = F_69 ( V_77 ) ;
V_75 =
F_70 ( ( T_9 * ) F_14 ( ( T_5 * ) V_23 ) ) ;
V_80 = F_13 ( ( T_9 * ) F_14 ( ( T_5 * ) V_23 ) ) ;
if ( ! F_71 ( V_80 , V_75 , V_78 , V_79 , V_77 ) ) {
F_9 ( V_81 , V_82 ) ;
F_72 ( V_77 ) ;
return 0 ;
}
if ( ! F_59 ( V_72 , V_73 , 128 ) )
return 0 ;
F_60 ( V_72 , L_7 ) ;
if ( ! F_59 ( V_72 , V_73 + 3 , 128 ) )
return 0 ;
F_60 ( V_72 , L_8 ) ;
F_61 ( V_72 , V_78 ) ;
F_60 ( V_72 , L_3 ) ;
F_59 ( V_72 , V_73 + 3 , 128 ) ;
F_60 ( V_72 , L_9 ) ;
F_61 ( V_72 , V_79 ) ;
F_60 ( V_72 , L_3 ) ;
F_73 ( V_77 ) ;
F_72 ( V_77 ) ;
}
V_29 =
F_12 ( F_13
( F_14 ( ( T_5 * ) V_23 ) ) ) ;
if ( ! F_59 ( V_72 , V_73 , 128 ) )
return 0 ;
F_60 ( V_72 , L_5 , F_62 ( V_29 ) ) ;
return 1 ;
}
static int F_74 ( T_13 * V_72 , const T_5 * V_23 , int V_73 ,
T_14 * V_74 )
{
return F_66 ( V_72 , V_23 , V_73 , V_74 , 0 ) ;
}
static int F_75 ( T_13 * V_72 , const T_5 * V_23 , int V_73 ,
T_14 * V_74 )
{
return F_66 ( V_72 , V_23 , V_73 , V_74 , 1 ) ;
}
static int F_76 ( T_13 * V_72 , const T_5 * V_23 , int V_73 ,
T_14 * V_74 )
{
return F_66 ( V_72 , V_23 , V_73 , V_74 , 2 ) ;
}
static int F_77 ( const T_5 * V_56 )
{
const T_1 * V_35 = F_14 ( ( T_5 * ) V_56 ) ;
if ( ! V_35 )
return 1 ;
if ( ! V_35 -> V_3 )
return 1 ;
return 0 ;
}
static int F_78 ( const T_5 * V_56 )
{
const T_9 * V_36 = F_14 ( ( T_5 * ) V_56 ) ;
if ( ! V_36 )
return 1 ;
if ( ! F_13 ( V_36 ) )
return 1 ;
return 0 ;
}
static int F_79 ( T_5 * V_83 , const T_5 * V_84 )
{
const T_1 * V_85 = F_14 ( ( T_5 * ) V_84 ) ;
T_1 * V_86 = F_14 ( V_83 ) ;
if ( F_11 ( V_84 ) != F_11 ( V_83 ) ) {
F_9 ( V_87 , V_88 ) ;
return 0 ;
}
if ( ! V_85 ) {
F_9 ( V_87 , V_89 ) ;
return 0 ;
}
if ( ! V_86 ) {
V_86 = F_23 () ;
F_24 ( V_83 , F_11 ( V_84 ) , V_86 ) ;
}
#define F_80 ( T_18 , T_19 , T_20 ) if (a->x) BN_free(a->x); a->x=BN_dup(b->x);
F_80 (dto, dfrom, p)
F_80 (dto, dfrom, q)
F_80 (dto, dfrom, g)
if ( V_86 -> V_38 )
F_31 ( V_86 ) ;
return 1 ;
}
static int F_81 ( T_5 * V_83 , const T_5 * V_84 )
{
T_9 * V_90 = F_14 ( V_83 ) ;
const T_9 * V_91 = F_14 ( ( T_5 * ) V_84 ) ;
if ( F_11 ( V_84 ) != F_11 ( V_83 ) ) {
F_9 ( V_92 , V_88 ) ;
return 0 ;
}
if ( ! V_91 ) {
F_9 ( V_92 , V_89 ) ;
return 0 ;
}
if ( ! V_90 ) {
V_90 = F_26 () ;
F_24 ( V_83 , F_11 ( V_84 ) , V_90 ) ;
}
F_82 ( V_90 , F_13 ( V_91 ) ) ;
if ( F_35 ( V_90 ) ) {
F_33 ( V_90 ) ;
}
return 1 ;
}
static int F_83 ( const T_5 * T_18 , const T_5 * T_19 )
{
const T_1 * V_93 = F_14 ( ( T_5 * ) T_18 ) ;
const T_1 * V_94 = F_14 ( ( T_5 * ) T_19 ) ;
if ( ! F_4 ( V_93 -> V_3 , V_94 -> V_3 ) )
return 1 ;
return 0 ;
}
static int F_84 ( const T_5 * T_18 , const T_5 * T_19 )
{
if ( F_12
( F_13 ( F_14 ( ( T_5 * ) T_18 ) ) ) ==
F_12 ( F_13
( F_14 ( ( T_5 * ) T_19 ) ) ) ) {
return 1 ;
}
return 0 ;
}
static int F_85 ( T_5 * V_56 , T_21 * V_95 )
{
T_7 * V_24 = NULL ;
const unsigned char * V_96 = NULL ;
unsigned char * V_97 ;
T_8 * V_98 = NULL ;
int V_99 , V_64 , V_100 ;
T_1 * V_35 ;
T_12 * V_101 = NULL ;
if ( ! F_86 ( & V_98 , & V_96 , & V_99 , & V_24 , V_95 ) )
return 0 ;
F_24 ( V_56 , F_20 ( V_98 ) , NULL ) ;
if ( ! F_18 ( V_56 , V_24 ) )
return 0 ;
V_101 = F_49 ( NULL , & V_96 , V_99 ) ;
if ( ! V_101 ) {
F_9 ( V_102 , V_12 ) ;
return 0 ;
}
V_97 = F_87 ( V_101 -> V_20 ) ;
for ( V_64 = 0 , V_100 = V_101 -> V_20 - 1 ; V_64 < V_101 -> V_20 ; V_64 ++ , V_100 -- ) {
V_97 [ V_100 ] = V_101 -> V_21 [ V_64 ] ;
}
V_35 = F_14 ( V_56 ) ;
V_35 -> V_76 = F_88 ( V_97 , V_101 -> V_20 , NULL ) ;
F_89 ( V_101 ) ;
F_90 ( V_97 ) ;
return 1 ;
}
static int F_91 ( T_21 * V_95 , const T_5 * V_56 )
{
T_8 * V_69 = NULL ;
T_12 * V_101 = NULL ;
void * V_31 = NULL ;
unsigned char * V_103 = NULL , * V_97 , * V_104 ;
int V_64 , V_100 , V_105 , V_61 = 0 ;
int V_26 = V_27 ;
T_1 * V_35 = F_14 ( ( T_5 * ) V_56 ) ;
V_69 = F_15 ( F_11 ( V_56 ) ) ;
if ( V_56 -> V_106 ) {
T_4 * V_8 = F_6 ( V_56 ) ;
V_31 = V_8 ;
V_26 = V_22 ;
}
V_105 = F_92 ( V_35 -> V_76 ) ;
V_97 = F_87 ( V_105 ) ;
F_93 ( V_35 -> V_76 , V_97 ) ;
V_101 = F_94 () ;
F_95 ( V_101 , NULL , V_105 ) ;
V_104 = F_96 ( V_101 ) ;
for ( V_64 = 0 , V_100 = V_105 - 1 ; V_64 < V_105 ; V_64 ++ , V_100 -- ) {
V_104 [ V_64 ] = V_97 [ V_100 ] ;
}
F_90 ( V_97 ) ;
V_61 = F_97 ( V_101 , & V_103 ) ;
F_98 ( V_101 ) ;
if ( V_61 < 0 )
return 0 ;
return F_99 ( V_95 , V_69 , V_26 , V_31 , V_103 , V_61 ) ;
}
static int F_100 ( T_5 * V_56 , T_21 * V_95 )
{
T_7 * V_24 = NULL ;
const unsigned char * V_96 = NULL ;
unsigned char * V_97 ;
T_8 * V_98 = NULL ;
int V_99 , V_64 , V_100 ;
T_16 * V_76 ;
T_3 * V_78 , * V_79 ;
T_12 * V_101 = NULL ;
int V_107 ;
const T_17 * V_80 ;
if ( ! F_86 ( & V_98 , & V_96 , & V_99 , & V_24 , V_95 ) )
return 0 ;
F_24 ( V_56 , F_20 ( V_98 ) , NULL ) ;
if ( ! F_18 ( V_56 , V_24 ) )
return 0 ;
V_80 = F_13 ( F_14 ( V_56 ) ) ;
V_101 = F_49 ( NULL , & V_96 , V_99 ) ;
if ( ! V_101 ) {
F_9 ( V_108 , V_12 ) ;
return 0 ;
}
V_97 = F_87 ( V_101 -> V_20 ) ;
for ( V_64 = 0 , V_100 = V_101 -> V_20 - 1 ; V_64 < V_101 -> V_20 ; V_64 ++ , V_100 -- ) {
V_97 [ V_100 ] = V_101 -> V_21 [ V_64 ] ;
}
V_107 = V_101 -> V_20 / 2 ;
F_89 ( V_101 ) ;
V_79 = F_50 ( V_97 , V_107 ) ;
V_78 = F_50 ( V_97 + V_107 , V_107 ) ;
F_90 ( V_97 ) ;
V_76 = F_101 ( V_80 ) ;
if ( ! F_102 ( V_80 , V_76 , V_78 , V_79 , NULL ) ) {
F_9 ( V_108 , V_82 ) ;
F_103 ( V_76 ) ;
F_5 ( V_78 ) ;
F_5 ( V_79 ) ;
return 0 ;
}
F_5 ( V_78 ) ;
F_5 ( V_79 ) ;
if ( ! F_104 ( F_14 ( V_56 ) , V_76 ) ) {
F_9 ( V_108 , V_82 ) ;
F_103 ( V_76 ) ;
return 0 ;
}
F_103 ( V_76 ) ;
return 1 ;
}
static int F_105 ( T_21 * V_95 , const T_5 * V_56 )
{
T_8 * V_69 = NULL ;
T_12 * V_101 = NULL ;
void * V_31 = NULL ;
unsigned char * V_103 = NULL , * V_97 , * V_104 ;
int V_64 , V_100 , V_105 , V_61 = 0 ;
const T_16 * V_76 ;
T_3 * V_78 , * V_79 , * V_109 ;
const T_9 * V_36 = F_14 ( ( T_5 * ) V_56 ) ;
int V_26 = V_27 ;
V_69 = F_15 ( F_11 ( V_56 ) ) ;
if ( V_56 -> V_106 ) {
T_4 * V_8 = F_6 ( V_56 ) ;
V_31 = V_8 ;
V_26 = V_22 ;
}
V_109 = F_2 () ;
F_106 ( F_13 ( V_36 ) , V_109 , NULL ) ;
V_76 = F_70 ( V_36 ) ;
if ( ! V_76 ) {
F_9 ( V_110 , V_111 ) ;
return 0 ;
}
V_78 = F_2 () ;
V_79 = F_2 () ;
F_71 ( F_13 ( V_36 ) ,
V_76 , V_78 , V_79 , NULL ) ;
V_105 = 2 * F_92 ( V_109 ) ;
F_5 ( V_109 ) ;
V_97 = F_87 ( V_105 ) ;
memset ( V_97 , 0 , V_105 ) ;
F_107 ( V_78 , V_97 + V_105 / 2 , V_105 / 2 ) ;
F_107 ( V_79 , V_97 , V_105 / 2 ) ;
F_5 ( V_78 ) ;
F_5 ( V_79 ) ;
V_101 = F_94 () ;
F_95 ( V_101 , NULL , V_105 ) ;
V_104 = F_96 ( V_101 ) ;
for ( V_64 = 0 , V_100 = V_105 - 1 ; V_64 < V_105 ; V_64 ++ , V_100 -- ) {
V_104 [ V_64 ] = V_97 [ V_100 ] ;
}
F_90 ( V_97 ) ;
V_61 = F_97 ( V_101 , & V_103 ) ;
F_98 ( V_101 ) ;
if ( V_61 < 0 )
return 0 ;
return F_99 ( V_95 , V_69 , V_26 , V_31 , V_103 , V_61 ) ;
}
static int F_108 ( const T_5 * T_18 , const T_5 * T_19 )
{
const T_1 * V_93 = F_14 ( ( T_5 * ) T_18 ) ;
const T_1 * V_94 = F_14 ( ( T_5 * ) T_19 ) ;
if ( V_93 && V_94 && V_93 -> V_76 && V_94 -> V_76
&& ! F_4 ( V_93 -> V_76 , V_94 -> V_76 ) ) {
return 1 ;
}
return 0 ;
}
static int F_109 ( const T_5 * T_18 , const T_5 * T_19 )
{
const T_9 * V_112 = F_14 ( ( T_5 * ) T_18 ) ;
const T_9 * V_113 = F_14 ( ( T_5 * ) T_19 ) ;
const T_16 * V_114 , * V_115 ;
int V_61 = 0 ;
if ( ! V_112 || ! V_113 )
return 0 ;
V_114 = F_70 ( V_112 ) ;
V_115 = F_70 ( V_113 ) ;
if ( ! V_114 || ! V_115 )
return 0 ;
V_61 = ( 0 == F_110 ( F_13 ( V_112 ) , V_114 , V_115 , NULL ) ) ;
return V_61 ;
}
static int F_111 ( const T_5 * V_56 )
{
return 64 ;
}
static int F_112 ( const T_5 * V_56 )
{
return 256 ;
}
static void F_113 ( T_5 * V_56 )
{
if ( V_56 -> V_23 . V_116 ) {
F_90 ( V_56 -> V_23 . V_116 ) ;
}
}
static int F_114 ( T_5 * V_23 , int V_39 , long V_40 , void * V_41 )
{
switch ( V_39 ) {
case V_55 :
* ( int * ) V_41 = V_117 ;
return 2 ;
}
return - 2 ;
}
static int F_115 ( const T_5 * V_23 , unsigned char * * V_118 )
{
int V_5 = F_1 ( F_14 ( ( T_5 * ) V_23 ) ) ;
return F_116 ( F_15 ( V_5 ) , V_118 ) ;
}
static int F_117 ( const T_5 * V_23 , unsigned char * * V_118 )
{
int V_5 =
F_12 ( F_13
( F_14 ( ( T_5 * ) V_23 ) ) ) ;
return F_116 ( F_15 ( V_5 ) , V_118 ) ;
}
static int F_118 ( T_5 * V_23 , const unsigned char * * V_118 ,
int V_119 )
{
T_8 * V_120 = NULL ;
T_1 * V_35 = F_14 ( V_23 ) ;
int V_5 ;
if ( F_119 ( & V_120 , V_118 , V_119 ) == NULL ) {
return 0 ;
}
V_5 = F_20 ( V_120 ) ;
F_120 ( V_120 ) ;
if ( ! V_35 ) {
V_35 = F_23 () ;
if ( ! F_24 ( V_23 , V_15 , V_35 ) )
return 0 ;
}
if ( ! F_25 ( V_35 , V_5 ) )
return 0 ;
return 1 ;
}
static int F_121 ( T_5 * V_23 , const unsigned char * * V_118 ,
int V_119 )
{
T_8 * V_120 = NULL ;
int V_5 ;
T_9 * V_36 = F_14 ( V_23 ) ;
if ( F_119 ( & V_120 , V_118 , V_119 ) == NULL ) {
return 0 ;
}
V_5 = F_20 ( V_120 ) ;
F_120 ( V_120 ) ;
if ( ! V_36 ) {
V_36 = F_26 () ;
if ( ! F_24 ( V_23 , V_14 , V_36 ) )
return 0 ;
}
if ( ! F_27 ( V_36 , V_5 ) )
return 0 ;
return 1 ;
}
int F_122 ( int V_5 , T_22 * * V_121 ,
const char * V_122 , const char * V_123 )
{
* V_121 = F_123 ( V_5 , V_124 , V_122 , V_123 ) ;
if ( ! * V_121 )
return 0 ;
switch ( V_5 ) {
case V_15 :
F_124 ( * V_121 , F_43 ) ;
F_125 ( * V_121 ,
F_47 , F_54 ,
F_65 ) ;
F_126 ( * V_121 ,
F_118 , F_115 ,
F_77 , F_79 ,
F_83 , F_63 ) ;
F_127 ( * V_121 ,
F_85 , F_91 ,
F_108 , F_64 ,
F_111 , F_112 ) ;
F_128 ( * V_121 , F_36 ) ;
break;
case V_14 :
F_124 ( * V_121 , F_45 ) ;
F_125 ( * V_121 ,
F_47 , F_54 ,
F_76 ) ;
F_126 ( * V_121 ,
F_121 , F_117 ,
F_78 , F_81 ,
F_84 , F_74 ) ;
F_127 ( * V_121 ,
F_100 , F_105 ,
F_109 , F_75 ,
F_111 , F_112 ) ;
F_128 ( * V_121 , F_36 ) ;
break;
case V_117 :
F_124 ( * V_121 , F_113 ) ;
F_128 ( * V_121 , F_114 ) ;
break;
}
return 1 ;
}
