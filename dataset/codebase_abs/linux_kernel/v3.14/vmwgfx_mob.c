static int F_1 ( struct V_1 * V_2 ,
T_1 type ,
unsigned long V_3 ,
struct V_4 * V_5 )
{
struct {
T_2 V_6 ;
T_3 V_7 ;
} * V_8 ;
struct V_9 * V_10 ;
const struct V_11 * V_12 ;
struct V_13 V_14 ;
int V_15 ;
F_2 ( V_5 -> V_16 != NULL ) ;
V_12 = F_3 ( V_2 -> V_17 ) ;
F_4 ( & V_14 , V_12 , V_3 >> V_18 ) ;
F_5 ( ! F_6 ( & V_14 ) ) ;
V_10 = F_7 ( V_5 -> V_19 >> V_18 ) ;
if ( F_8 ( V_10 == NULL ) ) {
F_9 ( L_1 ) ;
return - V_20 ;
}
if ( V_5 -> V_19 <= V_21 ) {
V_10 -> V_22 = V_23 ;
V_10 -> V_24 = F_10 ( & V_14 ) ;
} else if ( V_12 -> V_25 == 1 ) {
V_10 -> V_22 = V_26 ;
V_10 -> V_24 = F_10 ( & V_14 ) ;
} else {
V_15 = F_11 ( V_2 , V_10 ) ;
if ( F_8 ( V_15 != 0 ) )
goto V_27;
F_12 ( V_10 , V_14 , V_5 -> V_19 >> V_18 ) ;
V_10 -> V_22 += V_28 - V_29 ;
}
V_8 = F_13 ( V_2 , sizeof( * V_8 ) ) ;
if ( F_8 ( V_8 == NULL ) ) {
F_9 ( L_2 ) ;
V_15 = - V_20 ;
goto V_30;
}
memset ( V_8 , 0 , sizeof( * V_8 ) ) ;
V_8 -> V_6 . V_31 = V_32 ;
V_8 -> V_6 . V_19 = sizeof( V_8 -> V_7 ) ;
V_8 -> V_7 . type = type ;
V_8 -> V_7 . V_33 = F_14 ( V_10 -> V_24 >> V_18 ) ;
V_8 -> V_7 . V_34 = V_5 -> V_19 ;
V_8 -> V_7 . V_35 = 0 ;
V_8 -> V_7 . V_36 = V_10 -> V_22 ;
F_2 ( V_10 -> V_22 == V_37 ) ;
F_15 ( V_2 , sizeof( * V_8 ) ) ;
V_5 -> V_16 = V_10 ;
return 0 ;
V_30:
V_27:
F_16 ( V_10 ) ;
return V_15 ;
}
static void F_17 ( struct V_1 * V_2 ,
T_1 type ,
struct V_4 * V_5 )
{
struct {
T_2 V_6 ;
T_4 V_7 ;
} * V_8 ;
struct V_38 * V_39 ;
if ( V_5 -> V_16 == NULL )
return;
V_39 = V_5 -> V_16 -> V_40 ;
V_8 = F_13 ( V_2 , sizeof( * V_8 ) ) ;
if ( F_8 ( V_8 == NULL ) ) {
F_9 ( L_3
L_4 ) ;
} else {
memset ( V_8 , 0 , sizeof( * V_8 ) ) ;
V_8 -> V_6 . V_31 = V_41 ;
V_8 -> V_6 . V_19 = sizeof( V_8 -> V_7 ) ;
V_8 -> V_7 . type = type ;
V_8 -> V_7 . V_33 = 0 ;
V_8 -> V_7 . V_34 = 0 ;
V_8 -> V_7 . V_35 = 0 ;
V_8 -> V_7 . V_36 = V_42 ;
F_15 ( V_2 , sizeof( * V_8 ) ) ;
}
if ( V_39 ) {
int V_15 ;
V_15 = F_18 ( V_39 , false , true , false , NULL ) ;
F_2 ( V_15 != 0 ) ;
F_19 ( V_39 , NULL ) ;
F_20 ( V_39 ) ;
}
F_16 ( V_5 -> V_16 ) ;
V_5 -> V_16 = NULL ;
}
int F_21 ( struct V_1 * V_2 )
{
unsigned long V_3 ;
unsigned long V_43 ;
struct V_4 * V_44 ;
T_1 V_45 ;
int V_15 ;
V_44 = F_22 ( V_46 * sizeof( * V_44 ) ,
V_47 ) ;
if ( F_8 ( V_44 == NULL ) ) {
F_9 ( L_5
L_6 ) ;
return - V_20 ;
}
V_44 [ V_48 ] . V_19 =
V_49 * V_50 ;
V_44 [ V_51 ] . V_19 =
V_52 * V_53 ;
V_44 [ V_54 ] . V_19 =
V_55 * V_56 ;
V_44 [ V_57 ] . V_19 =
V_58 * V_59 ;
V_44 [ V_60 ] . V_19 =
V_61 *
V_62 ;
V_43 = 0 ;
for ( V_45 = 0 ; V_45 < V_46 ; ++ V_45 ) {
V_44 [ V_45 ] . V_19 =
( V_44 [ V_45 ] . V_19 + V_21 - 1 ) & V_63 ;
V_43 += V_44 [ V_45 ] . V_19 ;
}
V_15 = F_23 ( & V_2 -> V_64 , V_43 ,
V_65 ,
& V_66 ,
0 , false , NULL ,
& V_2 -> V_17 ) ;
if ( F_8 ( V_15 != 0 ) )
goto V_67;
V_15 = F_18 ( V_2 -> V_17 , false , true , false , NULL ) ;
F_2 ( V_15 != 0 ) ;
V_15 = V_68 . V_69 ( V_2 -> V_17 -> V_70 ) ;
if ( F_8 ( V_15 != 0 ) )
goto V_71;
V_15 = F_24 ( V_2 -> V_17 ) ;
if ( F_8 ( V_15 != 0 ) )
goto V_71;
F_20 ( V_2 -> V_17 ) ;
V_3 = 0 ;
for ( V_45 = 0 ; V_45 < V_46 - V_72 ; ++ V_45 ) {
V_15 = F_1 ( V_2 , V_45 , V_3 ,
& V_44 [ V_45 ] ) ;
if ( F_8 ( V_15 != 0 ) )
goto V_73;
V_3 += V_44 [ V_45 ] . V_19 ;
}
V_2 -> V_44 = V_44 ;
return 0 ;
V_71:
F_20 ( V_2 -> V_17 ) ;
V_73:
for ( V_45 = 0 ; V_45 < V_46 - V_72 ; ++ V_45 )
F_17 ( V_2 , V_45 , & V_44 [ V_45 ] ) ;
F_25 ( & V_2 -> V_17 ) ;
V_67:
F_26 ( V_44 ) ;
return V_15 ;
}
void F_27 ( struct V_1 * V_2 )
{
T_1 V_45 ;
struct V_38 * V_39 = V_2 -> V_17 ;
int V_15 ;
for ( V_45 = 0 ; V_45 < V_46 - V_72 ; ++ V_45 )
F_17 ( V_2 , V_45 ,
& V_2 -> V_44 [ V_45 ] ) ;
V_15 = F_18 ( V_39 , false , true , false , NULL ) ;
F_2 ( V_15 != 0 ) ;
F_19 ( V_39 , NULL ) ;
F_20 ( V_39 ) ;
F_25 ( & V_2 -> V_17 ) ;
F_26 ( V_2 -> V_44 ) ;
V_2 -> V_44 = NULL ;
}
static unsigned long F_28 ( unsigned long V_74 )
{
unsigned long V_75 = V_74 * V_21 ;
unsigned long V_76 = 0 ;
while ( F_29 ( V_75 > V_21 ) ) {
V_75 = F_30 ( V_75 , V_21 ) ;
V_75 *= V_77 ;
V_76 += ( V_75 + V_21 - 1 ) & V_63 ;
}
return V_76 >> V_18 ;
}
struct V_9 * F_7 ( unsigned long V_74 )
{
struct V_9 * V_10 = F_22 ( sizeof( * V_10 ) , V_47 ) ;
if ( F_8 ( V_10 == NULL ) )
return NULL ;
V_10 -> V_78 = F_28 ( V_74 ) ;
return V_10 ;
}
static int F_11 ( struct V_1 * V_2 ,
struct V_9 * V_10 )
{
int V_15 ;
F_2 ( V_10 -> V_40 != NULL ) ;
V_15 = F_23 ( & V_2 -> V_64 , V_10 -> V_78 * V_21 ,
V_65 ,
& V_66 ,
0 , false , NULL , & V_10 -> V_40 ) ;
if ( F_8 ( V_15 != 0 ) )
return V_15 ;
V_15 = F_18 ( V_10 -> V_40 , false , true , false , NULL ) ;
F_2 ( V_15 != 0 ) ;
V_15 = V_68 . V_69 ( V_10 -> V_40 -> V_70 ) ;
if ( F_8 ( V_15 != 0 ) )
goto V_71;
V_15 = F_24 ( V_10 -> V_40 ) ;
if ( F_8 ( V_15 != 0 ) )
goto V_71;
F_20 ( V_10 -> V_40 ) ;
return 0 ;
V_71:
F_20 ( V_10 -> V_40 ) ;
F_25 ( & V_10 -> V_40 ) ;
return V_15 ;
}
static void F_31 ( T_5 * * V_79 , T_6 V_80 )
{
* ( ( V_81 * ) * V_79 ) = F_14 ( V_80 >> V_18 ) ;
* V_79 += 2 ;
}
static void F_31 ( T_5 * * V_79 , T_6 V_80 )
{
* ( * V_79 ) ++ = F_32 ( V_80 >> V_18 ) ;
}
static unsigned long F_33 ( struct V_13 * V_82 ,
unsigned long V_83 ,
struct V_13 * V_84 )
{
unsigned long V_85 = V_83 * V_77 ;
unsigned long V_86 = F_30 ( V_85 , V_21 ) ;
unsigned long V_87 ;
T_5 * V_79 , * V_88 ;
unsigned long V_45 ;
struct V_89 * V_89 ;
for ( V_87 = 0 ; V_87 < V_86 ; ++ V_87 ) {
V_89 = F_34 ( V_84 ) ;
V_88 = V_79 = F_35 ( V_89 ) ;
for ( V_45 = 0 ; V_45 < V_21 / V_77 ; ++ V_45 ) {
F_31 ( & V_79 ,
F_10 ( V_82 ) ) ;
if ( F_8 ( -- V_83 == 0 ) )
break;
F_5 ( ! F_6 ( V_82 ) ) ;
}
F_36 ( V_88 ) ;
F_6 ( V_84 ) ;
}
return V_86 ;
}
static void F_12 ( struct V_9 * V_10 ,
struct V_13 V_82 ,
unsigned long V_83 )
{
unsigned long V_86 = 0 ;
struct V_38 * V_39 = V_10 -> V_40 ;
struct V_13 V_90 ;
struct V_13 V_84 ;
const struct V_11 * V_12 ;
int V_15 ;
V_15 = F_18 ( V_39 , false , true , false , NULL ) ;
F_2 ( V_15 != 0 ) ;
V_12 = F_3 ( V_39 ) ;
F_4 ( & V_84 , V_12 , 0 ) ;
F_2 ( ! F_6 ( & V_84 ) ) ;
V_10 -> V_22 = 0 ;
while ( F_29 ( V_83 > 1 ) ) {
++ V_10 -> V_22 ;
F_2 ( V_10 -> V_22 > 2 ) ;
V_90 = V_84 ;
V_86 = F_33 ( & V_82 , V_83 ,
& V_84 ) ;
V_82 = V_90 ;
V_83 = V_86 ;
}
V_10 -> V_24 = F_10 ( & V_90 ) ;
F_20 ( V_39 ) ;
}
void F_16 ( struct V_9 * V_10 )
{
if ( V_10 -> V_40 )
F_25 ( & V_10 -> V_40 ) ;
F_26 ( V_10 ) ;
}
void F_37 ( struct V_1 * V_2 ,
struct V_9 * V_10 )
{
struct {
T_2 V_6 ;
T_7 V_7 ;
} * V_8 ;
int V_15 ;
struct V_38 * V_39 = V_10 -> V_40 ;
if ( V_39 ) {
V_15 = F_18 ( V_39 , false , true , false , NULL ) ;
F_2 ( V_15 != 0 ) ;
}
V_8 = F_13 ( V_2 , sizeof( * V_8 ) ) ;
if ( F_8 ( V_8 == NULL ) ) {
F_9 ( L_7
L_8 ) ;
} else {
V_8 -> V_6 . V_31 = V_91 ;
V_8 -> V_6 . V_19 = sizeof( V_8 -> V_7 ) ;
V_8 -> V_7 . V_92 = V_10 -> V_31 ;
F_15 ( V_2 , sizeof( * V_8 ) ) ;
}
if ( V_39 ) {
F_19 ( V_39 , NULL ) ;
F_20 ( V_39 ) ;
}
F_38 ( V_2 , false ) ;
}
int F_39 ( struct V_1 * V_2 ,
struct V_9 * V_10 ,
const struct V_11 * V_12 ,
unsigned long V_83 ,
T_8 V_93 )
{
int V_15 ;
bool V_94 = false ;
struct V_13 V_82 ;
struct {
T_2 V_6 ;
T_9 V_7 ;
} * V_8 ;
V_10 -> V_31 = V_93 ;
F_4 ( & V_82 , V_12 , 0 ) ;
if ( F_8 ( ! F_6 ( & V_82 ) ) )
return 0 ;
if ( F_29 ( V_83 == 1 ) ) {
V_10 -> V_22 = V_23 ;
V_10 -> V_24 = F_10 ( & V_82 ) ;
} else if ( V_12 -> V_25 == 1 ) {
V_10 -> V_22 = V_26 ;
V_10 -> V_24 = F_10 ( & V_82 ) ;
} else if ( F_8 ( V_10 -> V_40 == NULL ) ) {
V_15 = F_11 ( V_2 , V_10 ) ;
if ( F_8 ( V_15 != 0 ) )
return V_15 ;
F_12 ( V_10 , V_82 , V_83 ) ;
V_94 = true ;
V_10 -> V_22 += V_28 - V_29 ;
}
( void ) F_40 ( V_2 , false ) ;
V_8 = F_13 ( V_2 , sizeof( * V_8 ) ) ;
if ( F_8 ( V_8 == NULL ) ) {
F_9 ( L_7
L_9 ) ;
goto V_95;
}
V_8 -> V_6 . V_31 = V_96 ;
V_8 -> V_6 . V_19 = sizeof( V_8 -> V_7 ) ;
V_8 -> V_7 . V_92 = V_93 ;
V_8 -> V_7 . V_36 = V_10 -> V_22 ;
V_8 -> V_7 . V_97 = F_14 ( V_10 -> V_24 >> V_18 ) ;
V_8 -> V_7 . V_34 = V_83 * V_21 ;
F_15 ( V_2 , sizeof( * V_8 ) ) ;
return 0 ;
V_95:
F_38 ( V_2 , false ) ;
if ( V_94 )
F_25 ( & V_10 -> V_40 ) ;
return - V_20 ;
}
