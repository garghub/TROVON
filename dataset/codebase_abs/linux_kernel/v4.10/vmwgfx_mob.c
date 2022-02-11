static int F_1 ( struct V_1 * V_2 ,
T_1 type ,
struct V_3 * V_4 ,
unsigned long V_5 ,
struct V_6 * V_7 )
{
struct {
T_2 V_8 ;
T_3 V_9 ;
} * V_10 ;
struct V_11 * V_12 ;
const struct V_13 * V_14 ;
struct V_15 V_16 ;
int V_17 ;
F_2 ( V_7 -> V_18 != NULL ) ;
V_14 = F_3 ( V_4 ) ;
F_4 ( & V_16 , V_14 , V_5 >> V_19 ) ;
F_5 ( ! F_6 ( & V_16 ) ) ;
V_12 = F_7 ( V_7 -> V_20 >> V_19 ) ;
if ( F_8 ( V_12 == NULL ) ) {
F_9 ( L_1 ) ;
return - V_21 ;
}
if ( V_7 -> V_20 <= V_22 ) {
V_12 -> V_23 = V_24 ;
V_12 -> V_25 = F_10 ( & V_16 ) ;
} else if ( V_14 -> V_26 == 1 ) {
V_12 -> V_23 = V_27 ;
V_12 -> V_25 = F_10 ( & V_16 ) ;
} else {
V_17 = F_11 ( V_2 , V_12 ) ;
if ( F_8 ( V_17 != 0 ) )
goto V_28;
F_12 ( V_12 , V_16 , V_7 -> V_20 >> V_19 ) ;
V_12 -> V_23 += V_29 - V_30 ;
}
V_10 = F_13 ( V_2 , sizeof( * V_10 ) ) ;
if ( F_8 ( V_10 == NULL ) ) {
F_9 ( L_2 ) ;
V_17 = - V_21 ;
goto V_31;
}
memset ( V_10 , 0 , sizeof( * V_10 ) ) ;
V_10 -> V_8 . V_32 = V_33 ;
V_10 -> V_8 . V_20 = sizeof( V_10 -> V_9 ) ;
V_10 -> V_9 . type = type ;
V_10 -> V_9 . V_34 = V_12 -> V_25 >> V_19 ;
V_10 -> V_9 . V_35 = V_7 -> V_20 ;
V_10 -> V_9 . V_36 = 0 ;
V_10 -> V_9 . V_37 = V_12 -> V_23 ;
F_2 ( V_12 -> V_23 == V_38 ) ;
F_14 ( V_2 , sizeof( * V_10 ) ) ;
V_7 -> V_18 = V_12 ;
return 0 ;
V_31:
V_28:
F_15 ( V_12 ) ;
return V_17 ;
}
static void F_16 ( struct V_1 * V_2 ,
T_1 type ,
struct V_6 * V_7 )
{
struct {
T_2 V_8 ;
T_4 V_9 ;
} * V_10 ;
struct V_3 * V_39 ;
if ( V_7 -> V_18 == NULL )
return;
V_39 = V_7 -> V_18 -> V_40 ;
V_10 = F_13 ( V_2 , sizeof( * V_10 ) ) ;
if ( F_8 ( V_10 == NULL ) ) {
F_9 ( L_3
L_4 ) ;
return;
}
memset ( V_10 , 0 , sizeof( * V_10 ) ) ;
V_10 -> V_8 . V_32 = V_41 ;
V_10 -> V_8 . V_20 = sizeof( V_10 -> V_9 ) ;
V_10 -> V_9 . type = type ;
V_10 -> V_9 . V_34 = 0 ;
V_10 -> V_9 . V_35 = 0 ;
V_10 -> V_9 . V_36 = 0 ;
V_10 -> V_9 . V_37 = V_42 ;
F_14 ( V_2 , sizeof( * V_10 ) ) ;
if ( V_39 ) {
int V_17 ;
V_17 = F_17 ( V_39 , false , true , NULL ) ;
F_2 ( V_17 != 0 ) ;
F_18 ( V_39 , NULL ) ;
F_19 ( V_39 ) ;
}
F_15 ( V_7 -> V_18 ) ;
V_7 -> V_18 = NULL ;
}
static int F_20 ( struct V_1 * V_2 ,
struct V_43 * V_44 )
{
unsigned long V_5 ;
unsigned long V_45 ;
struct V_6 * V_46 = V_44 -> V_46 ;
T_1 V_47 ;
int V_17 ;
V_45 = 0 ;
for ( V_47 = 0 ; V_47 < V_44 -> V_48 ; ++ V_47 ) {
if ( ! V_46 [ V_47 ] . V_49 )
continue;
V_46 [ V_47 ] . V_20 =
( V_46 [ V_47 ] . V_20 + V_22 - 1 ) & V_50 ;
V_45 += V_46 [ V_47 ] . V_20 ;
}
V_17 = F_21 ( & V_2 -> V_51 , V_45 ,
V_52 ,
& V_53 ,
0 , false , NULL ,
& V_44 -> V_4 ) ;
if ( F_8 ( V_17 != 0 ) )
goto V_54;
V_17 = F_17 ( V_44 -> V_4 , false , true , NULL ) ;
F_2 ( V_17 != 0 ) ;
V_17 = V_55 . V_56 ( V_44 -> V_4 -> V_57 ) ;
if ( F_8 ( V_17 != 0 ) )
goto V_58;
V_17 = F_22 ( V_44 -> V_4 ) ;
if ( F_8 ( V_17 != 0 ) )
goto V_58;
F_19 ( V_44 -> V_4 ) ;
V_5 = 0 ;
for ( V_47 = 0 ; V_47 < V_44 -> V_48 ; ++ V_47 ) {
if ( ! V_44 -> V_46 [ V_47 ] . V_49 )
continue;
V_17 = F_1 ( V_2 , V_47 , V_44 -> V_4 ,
V_5 ,
& V_46 [ V_47 ] ) ;
if ( F_8 ( V_17 != 0 ) )
goto V_59;
V_5 += V_46 [ V_47 ] . V_20 ;
}
return 0 ;
V_58:
F_19 ( V_44 -> V_4 ) ;
V_59:
for ( V_47 = 0 ; V_47 < V_44 -> V_48 ; ++ V_47 ) {
if ( V_44 -> V_46 [ V_47 ] . V_49 )
F_16 ( V_2 , V_47 ,
& V_44 -> V_46 [ V_47 ] ) ;
}
F_23 ( & V_44 -> V_4 ) ;
V_54:
return V_17 ;
}
int F_24 ( struct V_1 * V_2 )
{
struct V_6 * * V_46 = & V_2 -> V_60 . V_46 ;
int V_17 ;
if ( V_2 -> V_61 ) {
* V_46 = F_25 ( sizeof( V_62 ) , V_63 ) ;
if ( * V_46 == NULL )
return - V_21 ;
memcpy ( * V_46 , V_62 , sizeof( V_62 ) ) ;
V_2 -> V_60 . V_48 = F_26 ( V_62 ) ;
} else {
* V_46 = F_25 ( sizeof( V_64 ) , V_63 ) ;
if ( * V_46 == NULL )
return - V_21 ;
memcpy ( * V_46 , V_64 , sizeof( V_64 ) ) ;
V_2 -> V_60 . V_48 = F_26 ( V_64 ) ;
}
V_17 = F_20 ( V_2 , & V_2 -> V_60 ) ;
if ( F_8 ( V_17 != 0 ) )
goto V_65;
return 0 ;
V_65:
F_27 ( * V_46 ) ;
return V_17 ;
}
static void F_28 ( struct V_1 * V_2 ,
struct V_43 * V_44 )
{
T_1 V_47 ;
struct V_3 * V_39 = V_44 -> V_4 ;
int V_17 ;
for ( V_47 = 0 ; V_47 < V_44 -> V_48 ; ++ V_47 )
if ( V_44 -> V_46 [ V_47 ] . V_49 )
F_16 ( V_2 , V_47 ,
& V_44 -> V_46 [ V_47 ] ) ;
V_17 = F_17 ( V_39 , false , true , NULL ) ;
F_2 ( V_17 != 0 ) ;
F_18 ( V_39 , NULL ) ;
F_19 ( V_39 ) ;
F_23 ( & V_44 -> V_4 ) ;
}
void F_29 ( struct V_1 * V_2 )
{
F_28 ( V_2 , & V_2 -> V_60 ) ;
F_27 ( V_2 -> V_60 . V_46 ) ;
}
static unsigned long F_30 ( unsigned long V_66 )
{
unsigned long V_67 = V_66 * V_22 ;
unsigned long V_68 = 0 ;
while ( F_31 ( V_67 > V_22 ) ) {
V_67 = F_32 ( V_67 , V_22 ) ;
V_67 *= V_69 ;
V_68 += ( V_67 + V_22 - 1 ) & V_50 ;
}
return V_68 >> V_19 ;
}
struct V_11 * F_7 ( unsigned long V_66 )
{
struct V_11 * V_12 = F_33 ( sizeof( * V_12 ) , V_63 ) ;
if ( F_8 ( V_12 == NULL ) )
return NULL ;
V_12 -> V_70 = F_30 ( V_66 ) ;
return V_12 ;
}
static int F_11 ( struct V_1 * V_2 ,
struct V_11 * V_12 )
{
int V_17 ;
F_2 ( V_12 -> V_40 != NULL ) ;
V_17 = F_21 ( & V_2 -> V_51 , V_12 -> V_70 * V_22 ,
V_52 ,
& V_53 ,
0 , false , NULL , & V_12 -> V_40 ) ;
if ( F_8 ( V_17 != 0 ) )
return V_17 ;
V_17 = F_17 ( V_12 -> V_40 , false , true , NULL ) ;
F_2 ( V_17 != 0 ) ;
V_17 = V_55 . V_56 ( V_12 -> V_40 -> V_57 ) ;
if ( F_8 ( V_17 != 0 ) )
goto V_58;
V_17 = F_22 ( V_12 -> V_40 ) ;
if ( F_8 ( V_17 != 0 ) )
goto V_58;
F_19 ( V_12 -> V_40 ) ;
return 0 ;
V_58:
F_19 ( V_12 -> V_40 ) ;
F_23 ( & V_12 -> V_40 ) ;
return V_17 ;
}
static void F_34 ( T_5 * * V_71 , T_6 V_72 )
{
* ( ( V_73 * ) * V_71 ) = V_72 >> V_19 ;
* V_71 += 2 ;
}
static void F_34 ( T_5 * * V_71 , T_6 V_72 )
{
* ( * V_71 ) ++ = V_72 >> V_19 ;
}
static unsigned long F_35 ( struct V_15 * V_74 ,
unsigned long V_75 ,
struct V_15 * V_76 )
{
unsigned long V_77 = V_75 * V_69 ;
unsigned long V_78 = F_32 ( V_77 , V_22 ) ;
unsigned long V_79 ;
T_5 * V_71 , * V_80 ;
unsigned long V_47 ;
struct V_81 * V_81 ;
for ( V_79 = 0 ; V_79 < V_78 ; ++ V_79 ) {
V_81 = F_36 ( V_76 ) ;
V_80 = V_71 = F_37 ( V_81 ) ;
for ( V_47 = 0 ; V_47 < V_22 / V_69 ; ++ V_47 ) {
F_34 ( & V_71 ,
F_10 ( V_74 ) ) ;
if ( F_8 ( -- V_75 == 0 ) )
break;
F_5 ( ! F_6 ( V_74 ) ) ;
}
F_38 ( V_80 ) ;
F_6 ( V_76 ) ;
}
return V_78 ;
}
static void F_12 ( struct V_11 * V_12 ,
struct V_15 V_74 ,
unsigned long V_75 )
{
unsigned long V_78 = 0 ;
struct V_3 * V_39 = V_12 -> V_40 ;
struct V_15 V_82 ;
struct V_15 V_76 ;
const struct V_13 * V_14 ;
int V_17 ;
V_17 = F_17 ( V_39 , false , true , NULL ) ;
F_2 ( V_17 != 0 ) ;
V_14 = F_3 ( V_39 ) ;
F_4 ( & V_76 , V_14 , 0 ) ;
F_2 ( ! F_6 ( & V_76 ) ) ;
V_12 -> V_23 = 0 ;
while ( F_31 ( V_75 > 1 ) ) {
++ V_12 -> V_23 ;
F_2 ( V_12 -> V_23 > 2 ) ;
V_82 = V_76 ;
V_78 = F_35 ( & V_74 , V_75 ,
& V_76 ) ;
V_74 = V_82 ;
V_75 = V_78 ;
}
V_12 -> V_25 = F_10 ( & V_82 ) ;
F_19 ( V_39 ) ;
}
void F_15 ( struct V_11 * V_12 )
{
if ( V_12 -> V_40 )
F_23 ( & V_12 -> V_40 ) ;
F_27 ( V_12 ) ;
}
void F_39 ( struct V_1 * V_2 ,
struct V_11 * V_12 )
{
struct {
T_2 V_8 ;
T_7 V_9 ;
} * V_10 ;
int V_17 ;
struct V_3 * V_39 = V_12 -> V_40 ;
if ( V_39 ) {
V_17 = F_17 ( V_39 , false , true , NULL ) ;
F_2 ( V_17 != 0 ) ;
}
V_10 = F_13 ( V_2 , sizeof( * V_10 ) ) ;
if ( F_8 ( V_10 == NULL ) ) {
F_9 ( L_5
L_6 ) ;
} else {
V_10 -> V_8 . V_32 = V_83 ;
V_10 -> V_8 . V_20 = sizeof( V_10 -> V_9 ) ;
V_10 -> V_9 . V_84 = V_12 -> V_32 ;
F_14 ( V_2 , sizeof( * V_10 ) ) ;
}
if ( V_39 ) {
F_18 ( V_39 , NULL ) ;
F_19 ( V_39 ) ;
}
F_40 ( V_2 ) ;
}
int F_41 ( struct V_1 * V_2 ,
struct V_11 * V_12 ,
const struct V_13 * V_14 ,
unsigned long V_75 ,
T_8 V_85 )
{
int V_17 ;
bool V_86 = false ;
struct V_15 V_74 ;
struct {
T_2 V_8 ;
T_9 V_9 ;
} * V_10 ;
V_12 -> V_32 = V_85 ;
F_4 ( & V_74 , V_14 , 0 ) ;
if ( F_8 ( ! F_6 ( & V_74 ) ) )
return 0 ;
if ( F_31 ( V_75 == 1 ) ) {
V_12 -> V_23 = V_24 ;
V_12 -> V_25 = F_10 ( & V_74 ) ;
} else if ( V_14 -> V_26 == 1 ) {
V_12 -> V_23 = V_27 ;
V_12 -> V_25 = F_10 ( & V_74 ) ;
} else if ( F_8 ( V_12 -> V_40 == NULL ) ) {
V_17 = F_11 ( V_2 , V_12 ) ;
if ( F_8 ( V_17 != 0 ) )
return V_17 ;
F_12 ( V_12 , V_74 , V_75 ) ;
V_86 = true ;
V_12 -> V_23 += V_29 - V_30 ;
}
F_42 ( V_2 ) ;
V_10 = F_13 ( V_2 , sizeof( * V_10 ) ) ;
if ( F_8 ( V_10 == NULL ) ) {
F_9 ( L_5
L_7 ) ;
goto V_87;
}
V_10 -> V_8 . V_32 = V_88 ;
V_10 -> V_8 . V_20 = sizeof( V_10 -> V_9 ) ;
V_10 -> V_9 . V_84 = V_85 ;
V_10 -> V_9 . V_37 = V_12 -> V_23 ;
V_10 -> V_9 . V_89 = V_12 -> V_25 >> V_19 ;
V_10 -> V_9 . V_35 = V_75 * V_22 ;
F_14 ( V_2 , sizeof( * V_10 ) ) ;
return 0 ;
V_87:
F_40 ( V_2 ) ;
if ( V_86 )
F_23 ( & V_12 -> V_40 ) ;
return - V_21 ;
}
