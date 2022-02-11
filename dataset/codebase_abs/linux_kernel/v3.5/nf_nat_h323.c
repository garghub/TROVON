static int F_1 ( struct V_1 * V_2 ,
unsigned char * * V_3 , int V_4 ,
unsigned int V_5 , T_1 V_6 , T_2 V_7 )
{
enum V_8 V_9 ;
struct V_10 * V_11 = F_2 ( V_2 , & V_9 ) ;
struct {
T_1 V_6 ;
T_2 V_7 ;
} V_12 ( ( V_13 ) ) V_14 ;
const struct V_15 * V_16 ;
struct V_15 V_17 ;
V_14 . V_6 = V_6 ;
V_14 . V_7 = V_7 ;
V_5 += V_4 ;
if ( F_3 ( V_2 ) -> V_18 == V_19 ) {
if ( ! F_4 ( V_2 , V_11 , V_9 ,
V_5 , sizeof( V_14 ) ,
( char * ) & V_14 , sizeof( V_14 ) ) ) {
F_5 ( L_1 ) ;
return - 1 ;
}
V_16 = F_6 ( V_2 , F_7 ( V_2 ) ,
sizeof( V_17 ) , & V_17 ) ;
if ( V_16 == NULL )
return - 1 ;
* V_3 = V_2 -> V_3 + F_7 ( V_2 ) + V_16 -> V_20 * 4 + V_4 ;
} else {
if ( ! F_8 ( V_2 , V_11 , V_9 ,
V_5 , sizeof( V_14 ) ,
( char * ) & V_14 , sizeof( V_14 ) ) ) {
F_5 ( L_2 ) ;
return - 1 ;
}
* V_3 = V_2 -> V_3 + F_7 ( V_2 ) + sizeof( struct V_21 ) ;
}
return 0 ;
}
static int F_9 ( struct V_1 * V_2 ,
unsigned char * * V_3 , int V_4 ,
T_3 * V_22 ,
union V_23 * V_24 , T_2 V_7 )
{
return F_1 ( V_2 , V_3 , V_4 , V_22 -> V_25 . V_6 ,
V_24 -> V_6 , V_7 ) ;
}
static int F_10 ( struct V_1 * V_2 ,
unsigned char * * V_3 , int V_4 ,
T_4 * V_22 ,
union V_23 * V_24 , T_2 V_7 )
{
return F_1 ( V_2 , V_3 , V_4 ,
V_22 -> V_26 . V_27 . V_28 ,
V_24 -> V_6 , V_7 ) ;
}
static int F_11 ( struct V_1 * V_2 , struct V_10 * V_11 ,
enum V_8 V_9 ,
unsigned char * * V_3 ,
T_3 * V_22 , int V_29 )
{
const struct V_30 * V_31 = & F_12 ( V_11 ) -> V_32 . V_33 ;
int V_34 = F_13 ( V_9 ) ;
int V_35 ;
T_2 V_7 ;
union V_23 V_24 ;
for ( V_35 = 0 ; V_35 < V_29 ; V_35 ++ ) {
if ( F_14 ( V_11 , * V_3 , & V_22 [ V_35 ] , & V_24 , & V_7 ) ) {
if ( V_24 . V_6 == V_11 -> V_36 [ V_34 ] . V_37 . V_38 . V_39 . V_6 &&
V_7 == V_31 -> V_40 [ V_34 ] ) {
if ( V_35 > 0 &&
F_14 ( V_11 , * V_3 , & V_22 [ 0 ] ,
& V_24 , & V_7 ) &&
( F_15 ( V_24 . V_6 ) & 0xff000000 ) == 0x7f000000 )
V_35 = 0 ;
F_16 ( L_3 ,
& V_24 . V_6 , V_7 ,
& V_11 -> V_36 [ ! V_34 ] . V_37 . V_41 . V_39 . V_6 ,
V_31 -> V_40 [ ! V_34 ] ) ;
return F_9 ( V_2 , V_3 , 0 , & V_22 [ V_35 ] ,
& V_11 -> V_36 [ ! V_34 ] .
V_37 . V_41 . V_39 ,
V_31 -> V_40 [ ! V_34 ] ) ;
} else if ( V_24 . V_6 == V_11 -> V_36 [ V_34 ] . V_37 . V_41 . V_39 . V_6 &&
V_7 == V_31 -> V_40 [ V_34 ] ) {
F_16 ( L_3 ,
& V_24 . V_6 , V_7 ,
& V_11 -> V_36 [ ! V_34 ] . V_37 . V_38 . V_39 . V_6 ,
V_31 -> V_40 [ ! V_34 ] ) ;
return F_9 ( V_2 , V_3 , 0 , & V_22 [ V_35 ] ,
& V_11 -> V_36 [ ! V_34 ] .
V_37 . V_38 . V_39 ,
V_31 -> V_40 [ ! V_34 ] ) ;
}
}
}
return 0 ;
}
static int F_17 ( struct V_1 * V_2 , struct V_10 * V_11 ,
enum V_8 V_9 ,
unsigned char * * V_3 ,
T_3 * V_22 , int V_29 )
{
int V_34 = F_13 ( V_9 ) ;
int V_35 ;
T_2 V_7 ;
union V_23 V_24 ;
for ( V_35 = 0 ; V_35 < V_29 ; V_35 ++ ) {
if ( F_14 ( V_11 , * V_3 , & V_22 [ V_35 ] , & V_24 , & V_7 ) &&
V_24 . V_6 == V_11 -> V_36 [ V_34 ] . V_37 . V_38 . V_39 . V_6 &&
V_7 == V_11 -> V_36 [ V_34 ] . V_37 . V_38 . V_42 . V_43 . V_7 ) {
F_16 ( L_4 ,
& V_24 . V_6 , F_18 ( V_7 ) ,
& V_11 -> V_36 [ ! V_34 ] . V_37 . V_41 . V_39 . V_6 ,
F_18 ( V_11 -> V_36 [ ! V_34 ] . V_37 . V_41 . V_42 . V_43 . V_7 ) ) ;
return F_9 ( V_2 , V_3 , 0 , & V_22 [ V_35 ] ,
& V_11 -> V_36 [ ! V_34 ] . V_37 . V_41 . V_39 ,
V_11 -> V_36 [ ! V_34 ] . V_37 .
V_41 . V_42 . V_43 . V_7 ) ;
}
}
return 0 ;
}
static int F_19 ( struct V_1 * V_2 , struct V_10 * V_11 ,
enum V_8 V_9 ,
unsigned char * * V_3 , int V_4 ,
T_4 * V_22 ,
T_2 V_7 , T_2 V_44 ,
struct V_45 * V_46 ,
struct V_45 * V_47 )
{
struct V_30 * V_31 = & F_12 ( V_11 ) -> V_32 . V_33 ;
int V_34 = F_13 ( V_9 ) ;
int V_35 ;
T_5 V_48 ;
V_46 -> V_49 . V_43 . V_7 = V_46 -> V_37 . V_41 . V_42 . V_43 . V_7 ;
V_46 -> V_50 = V_51 ;
V_46 -> V_34 = ! V_34 ;
V_47 -> V_49 . V_43 . V_7 = V_47 -> V_37 . V_41 . V_42 . V_43 . V_7 ;
V_47 -> V_50 = V_51 ;
V_47 -> V_34 = ! V_34 ;
for ( V_35 = 0 ; V_35 < V_52 ; V_35 ++ ) {
if ( V_31 -> V_44 [ V_35 ] [ V_34 ] == V_44 ) {
V_46 -> V_37 . V_41 . V_42 . V_43 . V_7 = V_31 -> V_44 [ V_35 ] [ V_34 ] ;
V_47 -> V_37 . V_41 . V_42 . V_43 . V_7 =
F_20 ( F_18 ( V_31 -> V_44 [ V_35 ] [ V_34 ] ) + 1 ) ;
break;
} else if ( V_31 -> V_44 [ V_35 ] [ V_34 ] == 0 ) {
break;
}
}
if ( V_35 >= V_52 ) {
F_5 ( L_5 ) ;
return 0 ;
}
for ( V_48 = F_18 ( V_46 -> V_37 . V_41 . V_42 . V_43 . V_7 ) ;
V_48 != 0 ; V_48 += 2 ) {
int V_53 ;
V_46 -> V_37 . V_41 . V_42 . V_43 . V_7 = F_20 ( V_48 ) ;
V_53 = F_21 ( V_46 ) ;
if ( V_53 == 0 ) {
V_47 -> V_37 . V_41 . V_42 . V_43 . V_7 =
F_20 ( V_48 + 1 ) ;
V_53 = F_21 ( V_47 ) ;
if ( V_53 == 0 )
break;
else if ( V_53 != - V_54 ) {
F_22 ( V_46 ) ;
V_48 = 0 ;
break;
}
} else if ( V_53 != - V_54 ) {
V_48 = 0 ;
break;
}
}
if ( V_48 == 0 ) {
F_5 ( L_6 ) ;
return 0 ;
}
if ( F_10 ( V_2 , V_3 , V_4 , V_22 ,
& V_11 -> V_36 [ ! V_34 ] . V_37 . V_41 . V_39 ,
F_20 ( ( V_7 & F_20 ( 1 ) ) ? V_48 + 1 :
V_48 ) ) == 0 ) {
V_31 -> V_44 [ V_35 ] [ V_34 ] = V_44 ;
V_31 -> V_44 [ V_35 ] [ ! V_34 ] = F_20 ( V_48 ) ;
} else {
F_22 ( V_46 ) ;
F_22 ( V_47 ) ;
return - 1 ;
}
F_16 ( L_7 ,
& V_46 -> V_37 . V_38 . V_39 . V_6 ,
F_18 ( V_46 -> V_37 . V_38 . V_42 . V_43 . V_7 ) ,
& V_46 -> V_37 . V_41 . V_39 . V_6 ,
F_18 ( V_46 -> V_37 . V_41 . V_42 . V_43 . V_7 ) ) ;
F_16 ( L_8 ,
& V_47 -> V_37 . V_38 . V_39 . V_6 ,
F_18 ( V_47 -> V_37 . V_38 . V_42 . V_43 . V_7 ) ,
& V_47 -> V_37 . V_41 . V_39 . V_6 ,
F_18 ( V_47 -> V_37 . V_41 . V_42 . V_43 . V_7 ) ) ;
return 0 ;
}
static int F_23 ( struct V_1 * V_2 , struct V_10 * V_11 ,
enum V_8 V_9 ,
unsigned char * * V_3 , int V_4 ,
T_4 * V_22 , T_2 V_7 ,
struct V_45 * exp )
{
int V_34 = F_13 ( V_9 ) ;
T_5 V_48 = F_18 ( V_7 ) ;
exp -> V_49 . V_55 . V_7 = exp -> V_37 . V_41 . V_42 . V_55 . V_7 ;
exp -> V_50 = V_51 ;
exp -> V_34 = ! V_34 ;
for (; V_48 != 0 ; V_48 ++ ) {
int V_53 ;
exp -> V_37 . V_41 . V_42 . V_55 . V_7 = F_20 ( V_48 ) ;
V_53 = F_21 ( exp ) ;
if ( V_53 == 0 )
break;
else if ( V_53 != - V_54 ) {
V_48 = 0 ;
break;
}
}
if ( V_48 == 0 ) {
F_5 ( L_9 ) ;
return 0 ;
}
if ( F_10 ( V_2 , V_3 , V_4 , V_22 ,
& V_11 -> V_36 [ ! V_34 ] . V_37 . V_41 . V_39 ,
F_20 ( V_48 ) ) < 0 ) {
F_22 ( exp ) ;
return - 1 ;
}
F_16 ( L_10 ,
& exp -> V_37 . V_38 . V_39 . V_6 ,
F_18 ( exp -> V_37 . V_38 . V_42 . V_55 . V_7 ) ,
& exp -> V_37 . V_41 . V_39 . V_6 ,
F_18 ( exp -> V_37 . V_41 . V_42 . V_55 . V_7 ) ) ;
return 0 ;
}
static int F_24 ( struct V_1 * V_2 , struct V_10 * V_11 ,
enum V_8 V_9 ,
unsigned char * * V_3 , int V_4 ,
T_3 * V_22 , T_2 V_7 ,
struct V_45 * exp )
{
struct V_30 * V_31 = & F_12 ( V_11 ) -> V_32 . V_33 ;
int V_34 = F_13 ( V_9 ) ;
T_5 V_48 = F_18 ( V_7 ) ;
exp -> V_49 . V_55 . V_7 = exp -> V_37 . V_41 . V_42 . V_55 . V_7 ;
exp -> V_50 = V_51 ;
exp -> V_34 = ! V_34 ;
if ( V_31 -> V_40 [ V_34 ] == V_7 )
V_48 = F_18 ( V_31 -> V_40 [ ! V_34 ] ) ;
for (; V_48 != 0 ; V_48 ++ ) {
int V_53 ;
exp -> V_37 . V_41 . V_42 . V_55 . V_7 = F_20 ( V_48 ) ;
V_53 = F_21 ( exp ) ;
if ( V_53 == 0 )
break;
else if ( V_53 != - V_54 ) {
V_48 = 0 ;
break;
}
}
if ( V_48 == 0 ) {
F_5 ( L_11 ) ;
return 0 ;
}
if ( F_9 ( V_2 , V_3 , V_4 , V_22 ,
& V_11 -> V_36 [ ! V_34 ] . V_37 . V_41 . V_39 ,
F_20 ( V_48 ) ) == 0 ) {
V_31 -> V_40 [ V_34 ] = V_7 ;
V_31 -> V_40 [ ! V_34 ] = F_20 ( V_48 ) ;
} else {
F_22 ( exp ) ;
return - 1 ;
}
F_16 ( L_12 ,
& exp -> V_37 . V_38 . V_39 . V_6 ,
F_18 ( exp -> V_37 . V_38 . V_42 . V_55 . V_7 ) ,
& exp -> V_37 . V_41 . V_39 . V_6 ,
F_18 ( exp -> V_37 . V_41 . V_42 . V_55 . V_7 ) ) ;
return 0 ;
}
static void F_25 ( struct V_10 * V_56 ,
struct V_45 * V_57 )
{
struct V_58 V_59 ;
if ( V_57 -> V_37 . V_38 . V_39 . V_6 != 0 ) {
V_51 ( V_56 , V_57 ) ;
return;
}
F_26 ( V_56 -> V_60 & V_61 ) ;
V_59 . V_62 = V_63 ;
V_59 . V_64 = V_59 . V_65 = V_56 -> V_36 [ ! V_57 -> V_34 ] . V_37 . V_38 . V_39 . V_6 ;
F_27 ( V_56 , & V_59 , V_66 ) ;
V_59 . V_62 = ( V_63 | V_67 ) ;
V_59 . V_68 = V_59 . V_69 = V_57 -> V_49 ;
V_59 . V_64 = V_59 . V_65 =
V_56 -> V_70 -> V_36 [ ! V_57 -> V_34 ] . V_37 . V_38 . V_39 . V_6 ;
F_27 ( V_56 , & V_59 , V_71 ) ;
}
static int F_28 ( struct V_1 * V_2 , struct V_10 * V_11 ,
enum V_8 V_9 ,
unsigned char * * V_3 , T_3 * V_22 , int V_72 ,
T_2 V_7 , struct V_45 * exp )
{
struct V_30 * V_31 = & F_12 ( V_11 ) -> V_32 . V_33 ;
int V_34 = F_13 ( V_9 ) ;
T_5 V_48 = F_18 ( V_7 ) ;
union V_23 V_24 ;
exp -> V_49 . V_55 . V_7 = exp -> V_37 . V_41 . V_42 . V_55 . V_7 ;
exp -> V_50 = F_25 ;
exp -> V_34 = ! V_34 ;
if ( V_31 -> V_40 [ V_34 ] == V_7 )
V_48 = F_18 ( V_31 -> V_40 [ ! V_34 ] ) ;
for (; V_48 != 0 ; V_48 ++ ) {
int V_53 ;
exp -> V_37 . V_41 . V_42 . V_55 . V_7 = F_20 ( V_48 ) ;
V_53 = F_21 ( exp ) ;
if ( V_53 == 0 )
break;
else if ( V_53 != - V_54 ) {
V_48 = 0 ;
break;
}
}
if ( V_48 == 0 ) {
F_5 ( L_13 ) ;
return 0 ;
}
if ( F_9 ( V_2 , V_3 , 0 , & V_22 [ V_72 ] ,
& V_11 -> V_36 [ ! V_34 ] . V_37 . V_41 . V_39 ,
F_20 ( V_48 ) ) == 0 ) {
V_31 -> V_40 [ V_34 ] = V_7 ;
V_31 -> V_40 [ ! V_34 ] = F_20 ( V_48 ) ;
if ( V_72 > 0 &&
F_14 ( V_11 , * V_3 , & V_22 [ 0 ] , & V_24 , & V_7 ) &&
( F_15 ( V_24 . V_6 ) & 0xff000000 ) == 0x7f000000 ) {
F_9 ( V_2 , V_3 , 0 , & V_22 [ 0 ] ,
& V_11 -> V_36 [ ! V_34 ] . V_37 . V_41 . V_39 ,
V_31 -> V_40 [ ! V_34 ] ) ;
}
} else {
F_22 ( exp ) ;
return - 1 ;
}
F_16 ( L_14 ,
& exp -> V_37 . V_38 . V_39 . V_6 ,
F_18 ( exp -> V_37 . V_38 . V_42 . V_55 . V_7 ) ,
& exp -> V_37 . V_41 . V_39 . V_6 ,
F_18 ( exp -> V_37 . V_41 . V_42 . V_55 . V_7 ) ) ;
return 0 ;
}
static void F_29 ( struct V_10 * V_56 ,
struct V_45 * V_57 )
{
struct V_58 V_59 ;
F_26 ( V_56 -> V_60 & V_61 ) ;
V_59 . V_62 = V_63 ;
V_59 . V_64 = V_59 . V_65 = V_56 -> V_36 [ ! V_57 -> V_34 ] . V_37 . V_38 . V_39 . V_6 ;
F_27 ( V_56 , & V_59 , V_66 ) ;
V_59 . V_62 = ( V_63 | V_67 ) ;
V_59 . V_68 = V_59 . V_69 = V_57 -> V_49 ;
V_59 . V_64 = V_59 . V_65 = V_57 -> V_73 ;
F_27 ( V_56 , & V_59 , V_71 ) ;
}
static int F_30 ( struct V_1 * V_2 , struct V_10 * V_11 ,
enum V_8 V_9 ,
unsigned char * * V_3 , int V_4 ,
T_3 * V_22 , T_2 V_7 ,
struct V_45 * exp )
{
int V_34 = F_13 ( V_9 ) ;
T_5 V_48 ;
exp -> V_73 = exp -> V_37 . V_41 . V_39 . V_6 ;
exp -> V_37 . V_41 . V_39 . V_6 = V_11 -> V_36 [ ! V_34 ] . V_37 . V_41 . V_39 . V_6 ;
exp -> V_49 . V_55 . V_7 = exp -> V_37 . V_41 . V_42 . V_55 . V_7 ;
exp -> V_50 = F_29 ;
exp -> V_34 = ! V_34 ;
for ( V_48 = F_18 ( V_7 ) ; V_48 != 0 ; V_48 ++ ) {
int V_53 ;
exp -> V_37 . V_41 . V_42 . V_55 . V_7 = F_20 ( V_48 ) ;
V_53 = F_21 ( exp ) ;
if ( V_53 == 0 )
break;
else if ( V_53 != - V_54 ) {
V_48 = 0 ;
break;
}
}
if ( V_48 == 0 ) {
F_5 ( L_11 ) ;
return 0 ;
}
if ( ! F_9 ( V_2 , V_3 , V_4 , V_22 ,
& V_11 -> V_36 [ ! V_34 ] . V_37 . V_41 . V_39 ,
F_20 ( V_48 ) ) == 0 ) {
F_22 ( exp ) ;
return - 1 ;
}
F_16 ( L_15 ,
& exp -> V_37 . V_38 . V_39 . V_6 ,
F_18 ( exp -> V_37 . V_38 . V_42 . V_55 . V_7 ) ,
& exp -> V_37 . V_41 . V_39 . V_6 ,
F_18 ( exp -> V_37 . V_41 . V_42 . V_55 . V_7 ) ) ;
return 0 ;
}
static int T_6 F_31 ( void )
{
F_26 ( V_74 != NULL ) ;
F_26 ( V_75 != NULL ) ;
F_26 ( V_76 != NULL ) ;
F_26 ( V_77 != NULL ) ;
F_26 ( V_78 != NULL ) ;
F_26 ( V_79 != NULL ) ;
F_26 ( V_80 != NULL ) ;
F_26 ( V_81 != NULL ) ;
F_26 ( V_82 != NULL ) ;
F_32 ( V_74 , F_10 ) ;
F_32 ( V_75 , F_9 ) ;
F_32 ( V_76 , F_11 ) ;
F_32 ( V_77 , F_17 ) ;
F_32 ( V_78 , F_19 ) ;
F_32 ( V_79 , F_23 ) ;
F_32 ( V_80 , F_24 ) ;
F_32 ( V_81 , F_30 ) ;
F_32 ( V_82 , F_28 ) ;
F_33 ( & V_83 ) ;
F_33 ( & V_84 ) ;
return 0 ;
}
static void T_7 F_34 ( void )
{
F_32 ( V_74 , NULL ) ;
F_32 ( V_75 , NULL ) ;
F_32 ( V_76 , NULL ) ;
F_32 ( V_77 , NULL ) ;
F_32 ( V_78 , NULL ) ;
F_32 ( V_79 , NULL ) ;
F_32 ( V_80 , NULL ) ;
F_32 ( V_81 , NULL ) ;
F_32 ( V_82 , NULL ) ;
F_35 ( & V_83 ) ;
F_35 ( & V_84 ) ;
F_36 () ;
}
