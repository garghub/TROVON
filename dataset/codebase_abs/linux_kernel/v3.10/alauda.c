static struct V_1 * F_1 ( T_1 V_2 )
{
struct V_1 * V_3 ;
for ( V_3 = V_4 ; V_3 -> V_2 ; V_3 ++ )
if ( V_3 -> V_2 == V_2 )
return V_3 ;
return NULL ;
}
static void F_2 ( struct V_5 * V_5 )
{
struct V_6 * V_7 = F_3 ( V_5 , struct V_6 , V_5 ) ;
if ( V_7 -> V_8 ) {
F_4 ( V_7 -> V_8 ) ;
F_5 ( V_7 -> V_8 ) ;
}
F_6 ( V_7 -> V_9 ) ;
F_5 ( V_7 ) ;
}
static int F_7 ( struct V_6 * V_7 , void * V_10 )
{
int V_11 ;
F_8 ( & V_7 -> V_12 ) ;
V_11 = F_9 ( V_7 -> V_9 , F_10 ( V_7 -> V_9 , 0 ) ,
V_13 , 0xc0 , 0 , 1 , V_10 , 2 , V_14 ) ;
F_11 ( & V_7 -> V_12 ) ;
return V_11 ;
}
static int F_12 ( struct V_6 * V_7 )
{
int V_11 ;
F_8 ( & V_7 -> V_12 ) ;
V_11 = F_9 ( V_7 -> V_9 , F_13 ( V_7 -> V_9 , 0 ) ,
V_15 , 0x40 , 0 , 1 , NULL , 0 , V_14 ) ;
F_11 ( & V_7 -> V_12 ) ;
return V_11 ;
}
static int F_14 ( struct V_6 * V_7 , void * V_10 )
{
int V_11 ;
F_8 ( & V_7 -> V_12 ) ;
V_11 = F_9 ( V_7 -> V_9 , F_10 ( V_7 -> V_9 , 0 ) ,
V_16 , 0xc0 , 0 , 0 , V_10 , 4 , V_14 ) ;
F_11 ( & V_7 -> V_12 ) ;
return V_11 ;
}
static void F_15 ( struct V_6 * V_7 )
{
T_1 V_17 [] = {
V_18 , V_19 , 0 , 0 ,
0 , 0 , 0 , 0 , V_7 -> V_20
} ;
F_8 ( & V_7 -> V_12 ) ;
F_16 ( V_7 -> V_9 , V_7 -> V_21 , V_17 , 9 , NULL , V_14 ) ;
F_11 ( & V_7 -> V_12 ) ;
}
static void F_17 ( void * V_10 , void * V_22 ,
int * V_23 , int * V_24 )
{
T_1 V_25 [ 3 ] ;
int V_26 ;
F_18 ( NULL , V_10 , V_25 ) ;
V_26 = F_19 ( NULL , V_10 , V_22 , V_25 ) ;
if ( V_26 ) {
if ( V_26 > 0 )
( * V_23 ) ++ ;
else
( * V_24 ) ++ ;
}
}
static void F_20 ( struct V_27 * V_27 )
{
struct V_28 * V_29 = V_27 -> V_30 ;
if ( V_29 )
F_21 ( V_29 ) ;
}
static int F_22 ( struct V_31 * V_8 , T_2 V_32 , void * V_10 ,
void * V_33 )
{
struct V_34 V_35 ;
struct V_6 * V_7 = V_8 -> V_36 ;
T_3 V_37 = V_32 >> V_7 -> V_3 -> V_38 ;
T_3 V_39 = ( V_32 >> V_7 -> V_3 -> V_40 ) & V_7 -> V_41 ;
T_1 V_17 [] = {
V_18 , V_42 , F_23 ( V_37 ) ,
F_24 ( V_37 ) , 0 , F_25 ( V_37 ) + V_39 , 1 , 0 , V_7 -> V_20
} ;
int V_43 , V_26 ;
for ( V_43 = 0 ; V_43 < 3 ; V_43 ++ )
V_35 . V_27 [ V_43 ] = NULL ;
V_26 = - V_44 ;
for ( V_43 = 0 ; V_43 < 3 ; V_43 ++ ) {
V_35 . V_27 [ V_43 ] = F_26 ( 0 , V_45 ) ;
if ( ! V_35 . V_27 [ V_43 ] )
goto V_46;
}
F_27 ( & V_35 . V_29 ) ;
F_28 ( V_35 . V_27 [ 0 ] , V_7 -> V_9 , V_7 -> V_21 , V_17 , 9 ,
F_20 , NULL ) ;
F_28 ( V_35 . V_27 [ 1 ] , V_7 -> V_9 , V_7 -> V_47 , V_10 , V_8 -> V_48 ,
F_20 , NULL ) ;
F_28 ( V_35 . V_27 [ 2 ] , V_7 -> V_9 , V_7 -> V_47 , V_33 , 16 ,
F_20 , & V_35 . V_29 ) ;
F_8 ( & V_7 -> V_12 ) ;
for ( V_43 = 0 ; V_43 < 3 ; V_43 ++ ) {
V_26 = F_29 ( V_35 . V_27 [ V_43 ] , V_45 ) ;
if ( V_26 )
goto V_49;
}
if ( ! F_30 ( & V_35 . V_29 , V_50 ) ) {
V_26 = - V_51 ;
V_49:
for ( V_43 = 0 ; V_43 < 3 ; V_43 ++ ) {
F_31 ( V_35 . V_27 [ V_43 ] ) ;
}
}
F_11 ( & V_7 -> V_12 ) ;
V_46:
F_32 ( V_35 . V_27 [ 0 ] ) ;
F_32 ( V_35 . V_27 [ 1 ] ) ;
F_32 ( V_35 . V_27 [ 2 ] ) ;
return V_26 ;
}
static int F_33 ( struct V_31 * V_8 , T_2 V_32 ,
void * V_10 , T_1 * V_33 , int * V_23 , int * V_24 )
{
int V_26 ;
V_26 = F_22 ( V_8 , V_32 , V_10 , V_33 ) ;
if ( V_26 )
return V_26 ;
F_17 ( V_10 , V_33 + 13 , V_23 , V_24 ) ;
F_17 ( V_10 + 256 , V_33 + 8 , V_23 , V_24 ) ;
return 0 ;
}
static int F_34 ( struct V_31 * V_8 , T_2 V_52 , void * V_10 ,
void * V_33 )
{
struct V_34 V_35 ;
struct V_6 * V_7 = V_8 -> V_36 ;
T_3 V_37 = V_52 >> V_7 -> V_3 -> V_38 ;
T_3 V_39 = ( V_52 >> V_7 -> V_3 -> V_40 ) & V_7 -> V_41 ;
T_1 V_17 [] = {
V_18 , V_53 , F_23 ( V_37 ) ,
F_24 ( V_37 ) , 0 , F_25 ( V_37 ) + V_39 , 32 , 0 , V_7 -> V_20
} ;
int V_43 , V_26 ;
for ( V_43 = 0 ; V_43 < 3 ; V_43 ++ )
V_35 . V_27 [ V_43 ] = NULL ;
V_26 = - V_44 ;
for ( V_43 = 0 ; V_43 < 3 ; V_43 ++ ) {
V_35 . V_27 [ V_43 ] = F_26 ( 0 , V_45 ) ;
if ( ! V_35 . V_27 [ V_43 ] )
goto V_46;
}
F_27 ( & V_35 . V_29 ) ;
F_28 ( V_35 . V_27 [ 0 ] , V_7 -> V_9 , V_7 -> V_21 , V_17 , 9 ,
F_20 , NULL ) ;
F_28 ( V_35 . V_27 [ 1 ] , V_7 -> V_9 , V_7 -> V_54 , V_10 , V_8 -> V_48 ,
F_20 , NULL ) ;
F_28 ( V_35 . V_27 [ 2 ] , V_7 -> V_9 , V_7 -> V_54 , V_33 , 16 ,
F_20 , & V_35 . V_29 ) ;
F_8 ( & V_7 -> V_12 ) ;
for ( V_43 = 0 ; V_43 < 3 ; V_43 ++ ) {
V_26 = F_29 ( V_35 . V_27 [ V_43 ] , V_45 ) ;
if ( V_26 )
goto V_49;
}
if ( ! F_30 ( & V_35 . V_29 , V_50 ) ) {
V_26 = - V_51 ;
V_49:
for ( V_43 = 0 ; V_43 < 3 ; V_43 ++ ) {
F_31 ( V_35 . V_27 [ V_43 ] ) ;
}
}
F_11 ( & V_7 -> V_12 ) ;
V_46:
F_32 ( V_35 . V_27 [ 0 ] ) ;
F_32 ( V_35 . V_27 [ 1 ] ) ;
F_32 ( V_35 . V_27 [ 2 ] ) ;
return V_26 ;
}
static int F_35 ( struct V_31 * V_8 , T_2 V_55 )
{
struct V_34 V_35 ;
struct V_6 * V_7 = V_8 -> V_36 ;
T_3 V_37 = V_55 >> V_7 -> V_3 -> V_38 ;
T_1 V_17 [] = {
V_18 , V_56 , F_23 ( V_37 ) ,
F_24 ( V_37 ) , 0 , F_25 ( V_37 ) , 0x02 , 0 , V_7 -> V_20
} ;
T_1 V_10 [ 2 ] ;
int V_43 , V_26 ;
for ( V_43 = 0 ; V_43 < 2 ; V_43 ++ )
V_35 . V_27 [ V_43 ] = NULL ;
V_26 = - V_44 ;
for ( V_43 = 0 ; V_43 < 2 ; V_43 ++ ) {
V_35 . V_27 [ V_43 ] = F_26 ( 0 , V_45 ) ;
if ( ! V_35 . V_27 [ V_43 ] )
goto V_46;
}
F_27 ( & V_35 . V_29 ) ;
F_28 ( V_35 . V_27 [ 0 ] , V_7 -> V_9 , V_7 -> V_21 , V_17 , 9 ,
F_20 , NULL ) ;
F_28 ( V_35 . V_27 [ 1 ] , V_7 -> V_9 , V_7 -> V_47 , V_10 , 2 ,
F_20 , & V_35 . V_29 ) ;
F_8 ( & V_7 -> V_12 ) ;
for ( V_43 = 0 ; V_43 < 2 ; V_43 ++ ) {
V_26 = F_29 ( V_35 . V_27 [ V_43 ] , V_45 ) ;
if ( V_26 )
goto V_49;
}
if ( ! F_30 ( & V_35 . V_29 , V_50 ) ) {
V_26 = - V_51 ;
V_49:
for ( V_43 = 0 ; V_43 < 2 ; V_43 ++ ) {
F_31 ( V_35 . V_27 [ V_43 ] ) ;
}
}
F_11 ( & V_7 -> V_12 ) ;
V_46:
F_32 ( V_35 . V_27 [ 0 ] ) ;
F_32 ( V_35 . V_27 [ 1 ] ) ;
return V_26 ;
}
static int F_36 ( struct V_31 * V_8 , T_2 V_32 , void * V_33 )
{
static T_1 V_57 [ 512 ] ;
return F_22 ( V_8 , V_32 , V_57 , V_33 ) ;
}
static int F_37 ( struct V_31 * V_8 , T_2 V_55 )
{
T_1 V_33 [ 16 ] ;
int V_26 ;
V_26 = F_36 ( V_8 , V_55 , V_33 ) ;
if ( V_26 )
return V_26 ;
return F_38 ( V_33 [ 5 ] ) >= 7 ? 0 : 1 ;
}
static int F_39 ( struct V_31 * V_8 , T_2 V_32 , T_4 V_58 ,
T_4 * V_59 , T_5 * V_10 )
{
struct V_6 * V_7 = V_8 -> V_36 ;
void * V_60 ;
int V_26 , V_23 = 0 , V_24 = 0 ;
V_60 = F_40 ( V_8 -> V_48 , V_61 ) ;
if ( ! V_60 )
return - V_44 ;
* V_59 = V_58 ;
while ( V_58 ) {
T_1 V_33 [ 16 ] ;
T_4 V_62 = V_32 & V_7 -> V_63 ;
T_4 V_64 = F_41 ( V_58 , V_8 -> V_48 - V_62 ) ;
V_26 = F_33 ( V_8 , V_32 , V_60 , V_33 ,
& V_23 , & V_24 ) ;
if ( V_26 )
goto V_46;
memcpy ( V_10 , V_60 + V_62 , V_64 ) ;
V_10 += V_64 ;
V_32 += V_64 ;
V_58 -= V_64 ;
}
V_26 = 0 ;
if ( V_23 )
V_26 = 1 ;
if ( V_24 )
V_26 = - V_65 ;
V_46:
F_5 ( V_60 ) ;
return V_26 ;
}
static int F_42 ( struct V_31 * V_8 , T_2 V_32 , T_4 V_58 ,
T_4 * V_59 , T_5 * V_10 )
{
struct V_6 * V_7 = V_8 -> V_36 ;
int V_26 , V_23 = 0 , V_24 = 0 ;
if ( ( V_32 & V_7 -> V_63 ) || ( V_58 & V_7 -> V_63 ) )
return F_39 ( V_8 , V_32 , V_58 , V_59 , V_10 ) ;
* V_59 = V_58 ;
while ( V_58 ) {
T_1 V_33 [ 16 ] ;
V_26 = F_33 ( V_8 , V_32 , V_10 , V_33 ,
& V_23 , & V_24 ) ;
if ( V_26 )
return V_26 ;
V_10 += V_8 -> V_48 ;
V_32 += V_8 -> V_48 ;
V_58 -= V_8 -> V_48 ;
}
V_26 = 0 ;
if ( V_23 )
V_26 = 1 ;
if ( V_24 )
V_26 = - V_65 ;
return V_26 ;
}
static int F_43 ( struct V_31 * V_8 , T_2 V_52 , T_4 V_58 ,
T_4 * V_59 , const T_5 * V_10 )
{
struct V_6 * V_7 = V_8 -> V_36 ;
int V_26 ;
if ( ( V_52 & V_7 -> V_63 ) || ( V_58 & V_7 -> V_63 ) )
return - V_66 ;
* V_59 = V_58 ;
while ( V_58 ) {
T_3 V_39 = ( V_52 >> V_7 -> V_3 -> V_40 ) & V_7 -> V_41 ;
T_1 V_33 [ 16 ] = { 'h' , 'e' , 'l' , 'l' , 'o' , 0xff , 0xff , 0xff ,
0xff , 0xff , 0xff , 0xff , 0xff , 0xff , 0xff , 0xff } ;
if ( V_39 == 0 ) {
V_26 = F_37 ( V_8 , V_52 ) ;
if ( V_26 ) {
return - V_67 ;
}
}
F_18 ( V_8 , V_10 , & V_33 [ 13 ] ) ;
F_18 ( V_8 , V_10 + 256 , & V_33 [ 8 ] ) ;
V_26 = F_34 ( V_8 , V_52 , ( void * ) V_10 , V_33 ) ;
if ( V_26 )
return V_26 ;
V_10 += V_8 -> V_48 ;
V_52 += V_8 -> V_48 ;
V_58 -= V_8 -> V_48 ;
}
return 0 ;
}
static int F_44 ( struct V_31 * V_8 , struct V_68 * V_69 )
{
struct V_6 * V_7 = V_8 -> V_36 ;
T_3 V_55 = V_69 -> V_70 ;
T_3 V_58 = V_69 -> V_58 ;
int V_26 ;
if ( ( V_55 & V_7 -> V_71 ) || ( V_58 & V_7 -> V_71 ) )
return - V_66 ;
while ( V_58 ) {
V_26 = F_37 ( V_8 , V_55 ) ;
if ( V_26 > 0 )
V_26 = - V_67 ;
if ( V_26 < 0 )
return V_26 ;
V_26 = F_35 ( V_8 , V_55 ) ;
if ( V_26 < 0 )
return V_26 ;
V_55 += V_8 -> V_72 ;
V_58 -= V_8 -> V_72 ;
}
return 0 ;
}
static int F_45 ( struct V_31 * V_8 , struct V_68 * V_69 )
{
int V_26 ;
V_26 = F_44 ( V_8 , V_69 ) ;
V_69 -> V_73 = V_26 ? V_74 : V_75 ;
F_46 ( V_69 ) ;
return V_26 ;
}
static int F_47 ( struct V_6 * V_7 )
{
T_1 V_10 [ 4 ] , * V_76 = V_10 , * V_77 = V_10 + 1 ;
struct V_1 * V_3 ;
struct V_31 * V_8 ;
int V_26 ;
V_8 = F_48 ( sizeof( * V_8 ) , V_61 ) ;
if ( ! V_8 )
return - V_44 ;
for (; ; ) {
V_26 = F_7 ( V_7 , V_10 ) ;
if ( V_26 < 0 )
goto error;
if ( * V_76 & 0x10 )
break;
F_49 ( 20 ) ;
}
V_26 = F_12 ( V_7 ) ;
if ( V_26 )
goto error;
F_49 ( 10 ) ;
V_26 = F_7 ( V_7 , V_10 ) ;
if ( V_26 < 0 )
goto error;
if ( * V_76 != 0x14 ) {
V_26 = - V_67 ;
goto error;
}
V_26 = F_14 ( V_7 , V_10 ) ;
if ( V_26 < 0 )
goto error;
V_3 = F_1 ( * V_77 ) ;
if ( ! V_3 ) {
F_50 ( V_78 L_1 , * V_77 ) ;
V_26 = - V_67 ;
goto error;
}
F_50 ( V_79 L_2 ,
1 << V_3 -> V_40 , 1 << V_3 -> V_38 ,
1 << ( V_3 -> V_80 - 20 ) ) ;
V_7 -> V_3 = V_3 ;
V_7 -> V_41 = ( 1 << ( V_3 -> V_38 - V_3 -> V_40 ) ) - 1 ;
V_7 -> V_63 = ( 1 << V_3 -> V_40 ) - 1 ;
V_7 -> V_71 = ( 1 << V_3 -> V_38 ) - 1 ;
V_8 -> V_81 = L_3 ;
V_8 -> V_82 = 1 << V_3 -> V_80 ;
V_8 -> V_72 = 1 << V_3 -> V_38 ;
V_8 -> V_48 = 1 << V_3 -> V_40 ;
V_8 -> type = V_83 ;
V_8 -> V_84 = V_85 ;
V_8 -> V_86 = F_42 ;
V_8 -> V_87 = F_43 ;
V_8 -> V_88 = F_45 ;
V_8 -> V_89 = F_37 ;
V_8 -> V_36 = V_7 ;
V_8 -> V_90 = V_91 ;
V_8 -> V_92 = 1 ;
V_26 = F_51 ( V_8 , NULL , 0 ) ;
if ( V_26 ) {
V_26 = - V_93 ;
goto error;
}
V_7 -> V_8 = V_8 ;
F_15 ( V_7 ) ;
return 0 ;
error:
F_5 ( V_8 ) ;
return V_26 ;
}
static int F_52 ( struct V_6 * V_7 )
{
T_1 V_10 [ 2 ] , * V_76 = V_10 , * V_77 = V_10 + 1 ;
int V_26 ;
V_26 = F_7 ( V_7 , V_10 ) ;
if ( V_26 < 0 )
return V_26 ;
if ( ( * V_77 & 0x01 ) == 0 ) {
return - V_67 ;
}
if ( ( * V_76 & 0x80 ) || ( ( * V_76 & 0x1F ) == 0x10 ) ) {
return - V_67 ;
}
if ( * V_76 & 0x08 ) {
return F_47 ( V_7 ) ;
}
return 0 ;
}
static int F_53 ( struct V_94 * V_95 ,
const struct V_96 * V_2 )
{
struct V_6 * V_7 ;
struct V_97 * V_98 ;
struct V_99 * V_100 ,
* V_101 = NULL , * V_102 = NULL , * V_103 = NULL ;
int V_43 , V_26 = - V_44 ;
V_7 = F_48 ( 2 * sizeof( * V_7 ) , V_61 ) ;
if ( ! V_7 )
goto error;
F_54 ( & V_7 -> V_5 ) ;
F_55 ( V_95 , V_7 ) ;
V_7 -> V_9 = F_56 ( F_57 ( V_95 ) ) ;
V_7 -> V_95 = V_95 ;
V_98 = V_95 -> V_104 ;
for ( V_43 = 0 ; V_43 < V_98 -> V_105 . V_106 ; ++ V_43 ) {
V_100 = & V_98 -> V_107 [ V_43 ] . V_105 ;
if ( F_58 ( V_100 ) ) {
V_101 = V_100 ;
} else if ( F_59 ( V_100 ) ) {
if ( V_43 == 0 )
V_103 = V_100 ;
else
V_102 = V_100 ;
}
}
V_26 = - V_67 ;
if ( ! V_103 || ! V_101 || ! V_102 )
goto error;
V_7 -> V_54 = F_60 ( V_7 -> V_9 ,
F_61 ( V_103 ) ) ;
V_7 -> V_47 = F_62 ( V_7 -> V_9 ,
F_61 ( V_101 ) ) ;
V_7 -> V_21 = F_60 ( V_7 -> V_9 ,
F_61 ( V_102 ) ) ;
memcpy ( V_7 + 1 , V_7 , sizeof( * V_7 ) ) ;
F_63 ( & V_7 [ 0 ] . V_12 ) ;
F_63 ( & V_7 [ 1 ] . V_12 ) ;
V_7 [ 0 ] . V_20 = V_108 ;
V_7 [ 1 ] . V_20 = V_109 ;
F_64 ( & V_95 -> V_9 , L_4 ) ;
F_52 ( V_7 ) ;
F_52 ( V_7 + 1 ) ;
return 0 ;
error:
if ( V_7 )
F_65 ( & V_7 -> V_5 , F_2 ) ;
return V_26 ;
}
static void F_66 ( struct V_94 * V_95 )
{
struct V_6 * V_7 ;
V_7 = F_67 ( V_95 ) ;
F_55 ( V_95 , NULL ) ;
if ( V_7 )
F_65 ( & V_7 -> V_5 , F_2 ) ;
F_64 ( & V_95 -> V_9 , L_5 ) ;
}
