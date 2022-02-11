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
const struct V_30 * V_31 = F_12 ( V_11 ) ;
int V_32 = F_13 ( V_9 ) ;
int V_33 ;
T_2 V_7 ;
union V_23 V_24 ;
for ( V_33 = 0 ; V_33 < V_29 ; V_33 ++ ) {
if ( F_14 ( V_11 , * V_3 , & V_22 [ V_33 ] , & V_24 , & V_7 ) ) {
if ( V_24 . V_6 == V_11 -> V_34 [ V_32 ] . V_35 . V_36 . V_37 . V_6 &&
V_7 == V_31 -> V_38 [ V_32 ] ) {
if ( V_33 > 0 &&
F_14 ( V_11 , * V_3 , & V_22 [ 0 ] ,
& V_24 , & V_7 ) &&
( F_15 ( V_24 . V_6 ) & 0xff000000 ) == 0x7f000000 )
V_33 = 0 ;
F_16 ( L_3 ,
& V_24 . V_6 , V_7 ,
& V_11 -> V_34 [ ! V_32 ] . V_35 . V_39 . V_37 . V_6 ,
V_31 -> V_38 [ ! V_32 ] ) ;
return F_9 ( V_2 , V_3 , 0 , & V_22 [ V_33 ] ,
& V_11 -> V_34 [ ! V_32 ] .
V_35 . V_39 . V_37 ,
V_31 -> V_38 [ ! V_32 ] ) ;
} else if ( V_24 . V_6 == V_11 -> V_34 [ V_32 ] . V_35 . V_39 . V_37 . V_6 &&
V_7 == V_31 -> V_38 [ V_32 ] ) {
F_16 ( L_3 ,
& V_24 . V_6 , V_7 ,
& V_11 -> V_34 [ ! V_32 ] . V_35 . V_36 . V_37 . V_6 ,
V_31 -> V_38 [ ! V_32 ] ) ;
return F_9 ( V_2 , V_3 , 0 , & V_22 [ V_33 ] ,
& V_11 -> V_34 [ ! V_32 ] .
V_35 . V_36 . V_37 ,
V_31 -> V_38 [ ! V_32 ] ) ;
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
int V_32 = F_13 ( V_9 ) ;
int V_33 ;
T_2 V_7 ;
union V_23 V_24 ;
for ( V_33 = 0 ; V_33 < V_29 ; V_33 ++ ) {
if ( F_14 ( V_11 , * V_3 , & V_22 [ V_33 ] , & V_24 , & V_7 ) &&
V_24 . V_6 == V_11 -> V_34 [ V_32 ] . V_35 . V_36 . V_37 . V_6 &&
V_7 == V_11 -> V_34 [ V_32 ] . V_35 . V_36 . V_40 . V_41 . V_7 ) {
F_16 ( L_4 ,
& V_24 . V_6 , F_18 ( V_7 ) ,
& V_11 -> V_34 [ ! V_32 ] . V_35 . V_39 . V_37 . V_6 ,
F_18 ( V_11 -> V_34 [ ! V_32 ] . V_35 . V_39 . V_40 . V_41 . V_7 ) ) ;
return F_9 ( V_2 , V_3 , 0 , & V_22 [ V_33 ] ,
& V_11 -> V_34 [ ! V_32 ] . V_35 . V_39 . V_37 ,
V_11 -> V_34 [ ! V_32 ] . V_35 .
V_39 . V_40 . V_41 . V_7 ) ;
}
}
return 0 ;
}
static int F_19 ( struct V_1 * V_2 , struct V_10 * V_11 ,
enum V_8 V_9 ,
unsigned char * * V_3 , int V_4 ,
T_4 * V_22 ,
T_2 V_7 , T_2 V_42 ,
struct V_43 * V_44 ,
struct V_43 * V_45 )
{
struct V_30 * V_31 = F_12 ( V_11 ) ;
int V_32 = F_13 ( V_9 ) ;
int V_33 ;
T_5 V_46 ;
V_44 -> V_47 . V_41 . V_7 = V_44 -> V_35 . V_39 . V_40 . V_41 . V_7 ;
V_44 -> V_48 = V_49 ;
V_44 -> V_32 = ! V_32 ;
V_45 -> V_47 . V_41 . V_7 = V_45 -> V_35 . V_39 . V_40 . V_41 . V_7 ;
V_45 -> V_48 = V_49 ;
V_45 -> V_32 = ! V_32 ;
for ( V_33 = 0 ; V_33 < V_50 ; V_33 ++ ) {
if ( V_31 -> V_42 [ V_33 ] [ V_32 ] == V_42 ) {
V_44 -> V_35 . V_39 . V_40 . V_41 . V_7 = V_31 -> V_42 [ V_33 ] [ V_32 ] ;
V_45 -> V_35 . V_39 . V_40 . V_41 . V_7 =
F_20 ( F_18 ( V_31 -> V_42 [ V_33 ] [ V_32 ] ) + 1 ) ;
break;
} else if ( V_31 -> V_42 [ V_33 ] [ V_32 ] == 0 ) {
break;
}
}
if ( V_33 >= V_50 ) {
F_5 ( L_5 ) ;
return 0 ;
}
for ( V_46 = F_18 ( V_44 -> V_35 . V_39 . V_40 . V_41 . V_7 ) ;
V_46 != 0 ; V_46 += 2 ) {
int V_51 ;
V_44 -> V_35 . V_39 . V_40 . V_41 . V_7 = F_20 ( V_46 ) ;
V_51 = F_21 ( V_44 ) ;
if ( V_51 == 0 ) {
V_45 -> V_35 . V_39 . V_40 . V_41 . V_7 =
F_20 ( V_46 + 1 ) ;
V_51 = F_21 ( V_45 ) ;
if ( V_51 == 0 )
break;
else if ( V_51 != - V_52 ) {
F_22 ( V_44 ) ;
V_46 = 0 ;
break;
}
} else if ( V_51 != - V_52 ) {
V_46 = 0 ;
break;
}
}
if ( V_46 == 0 ) {
F_5 ( L_6 ) ;
return 0 ;
}
if ( F_10 ( V_2 , V_3 , V_4 , V_22 ,
& V_11 -> V_34 [ ! V_32 ] . V_35 . V_39 . V_37 ,
F_20 ( ( V_7 & F_20 ( 1 ) ) ? V_46 + 1 :
V_46 ) ) == 0 ) {
V_31 -> V_42 [ V_33 ] [ V_32 ] = V_42 ;
V_31 -> V_42 [ V_33 ] [ ! V_32 ] = F_20 ( V_46 ) ;
} else {
F_22 ( V_44 ) ;
F_22 ( V_45 ) ;
return - 1 ;
}
F_16 ( L_7 ,
& V_44 -> V_35 . V_36 . V_37 . V_6 ,
F_18 ( V_44 -> V_35 . V_36 . V_40 . V_41 . V_7 ) ,
& V_44 -> V_35 . V_39 . V_37 . V_6 ,
F_18 ( V_44 -> V_35 . V_39 . V_40 . V_41 . V_7 ) ) ;
F_16 ( L_8 ,
& V_45 -> V_35 . V_36 . V_37 . V_6 ,
F_18 ( V_45 -> V_35 . V_36 . V_40 . V_41 . V_7 ) ,
& V_45 -> V_35 . V_39 . V_37 . V_6 ,
F_18 ( V_45 -> V_35 . V_39 . V_40 . V_41 . V_7 ) ) ;
return 0 ;
}
static int F_23 ( struct V_1 * V_2 , struct V_10 * V_11 ,
enum V_8 V_9 ,
unsigned char * * V_3 , int V_4 ,
T_4 * V_22 , T_2 V_7 ,
struct V_43 * exp )
{
int V_32 = F_13 ( V_9 ) ;
T_5 V_46 = F_18 ( V_7 ) ;
exp -> V_47 . V_53 . V_7 = exp -> V_35 . V_39 . V_40 . V_53 . V_7 ;
exp -> V_48 = V_49 ;
exp -> V_32 = ! V_32 ;
for (; V_46 != 0 ; V_46 ++ ) {
int V_51 ;
exp -> V_35 . V_39 . V_40 . V_53 . V_7 = F_20 ( V_46 ) ;
V_51 = F_21 ( exp ) ;
if ( V_51 == 0 )
break;
else if ( V_51 != - V_52 ) {
V_46 = 0 ;
break;
}
}
if ( V_46 == 0 ) {
F_5 ( L_9 ) ;
return 0 ;
}
if ( F_10 ( V_2 , V_3 , V_4 , V_22 ,
& V_11 -> V_34 [ ! V_32 ] . V_35 . V_39 . V_37 ,
F_20 ( V_46 ) ) < 0 ) {
F_22 ( exp ) ;
return - 1 ;
}
F_16 ( L_10 ,
& exp -> V_35 . V_36 . V_37 . V_6 ,
F_18 ( exp -> V_35 . V_36 . V_40 . V_53 . V_7 ) ,
& exp -> V_35 . V_39 . V_37 . V_6 ,
F_18 ( exp -> V_35 . V_39 . V_40 . V_53 . V_7 ) ) ;
return 0 ;
}
static int F_24 ( struct V_1 * V_2 , struct V_10 * V_11 ,
enum V_8 V_9 ,
unsigned char * * V_3 , int V_4 ,
T_3 * V_22 , T_2 V_7 ,
struct V_43 * exp )
{
struct V_30 * V_31 = F_12 ( V_11 ) ;
int V_32 = F_13 ( V_9 ) ;
T_5 V_46 = F_18 ( V_7 ) ;
exp -> V_47 . V_53 . V_7 = exp -> V_35 . V_39 . V_40 . V_53 . V_7 ;
exp -> V_48 = V_49 ;
exp -> V_32 = ! V_32 ;
if ( V_31 -> V_38 [ V_32 ] == V_7 )
V_46 = F_18 ( V_31 -> V_38 [ ! V_32 ] ) ;
for (; V_46 != 0 ; V_46 ++ ) {
int V_51 ;
exp -> V_35 . V_39 . V_40 . V_53 . V_7 = F_20 ( V_46 ) ;
V_51 = F_21 ( exp ) ;
if ( V_51 == 0 )
break;
else if ( V_51 != - V_52 ) {
V_46 = 0 ;
break;
}
}
if ( V_46 == 0 ) {
F_5 ( L_11 ) ;
return 0 ;
}
if ( F_9 ( V_2 , V_3 , V_4 , V_22 ,
& V_11 -> V_34 [ ! V_32 ] . V_35 . V_39 . V_37 ,
F_20 ( V_46 ) ) == 0 ) {
V_31 -> V_38 [ V_32 ] = V_7 ;
V_31 -> V_38 [ ! V_32 ] = F_20 ( V_46 ) ;
} else {
F_22 ( exp ) ;
return - 1 ;
}
F_16 ( L_12 ,
& exp -> V_35 . V_36 . V_37 . V_6 ,
F_18 ( exp -> V_35 . V_36 . V_40 . V_53 . V_7 ) ,
& exp -> V_35 . V_39 . V_37 . V_6 ,
F_18 ( exp -> V_35 . V_39 . V_40 . V_53 . V_7 ) ) ;
return 0 ;
}
static void F_25 ( struct V_10 * V_54 ,
struct V_43 * V_55 )
{
struct V_56 V_57 ;
if ( V_55 -> V_35 . V_36 . V_37 . V_6 != 0 ) {
V_49 ( V_54 , V_55 ) ;
return;
}
F_26 ( V_54 -> V_58 & V_59 ) ;
V_57 . V_60 = V_61 ;
V_57 . V_62 = V_57 . V_63 = V_54 -> V_34 [ ! V_55 -> V_32 ] . V_35 . V_36 . V_37 . V_6 ;
F_27 ( V_54 , & V_57 , V_64 ) ;
V_57 . V_60 = ( V_61 | V_65 ) ;
V_57 . V_66 = V_57 . V_67 = V_55 -> V_47 ;
V_57 . V_62 = V_57 . V_63 =
V_54 -> V_68 -> V_34 [ ! V_55 -> V_32 ] . V_35 . V_36 . V_37 . V_6 ;
F_27 ( V_54 , & V_57 , V_69 ) ;
}
static int F_28 ( struct V_1 * V_2 , struct V_10 * V_11 ,
enum V_8 V_9 ,
unsigned char * * V_3 , T_3 * V_22 , int V_70 ,
T_2 V_7 , struct V_43 * exp )
{
struct V_30 * V_31 = F_12 ( V_11 ) ;
int V_32 = F_13 ( V_9 ) ;
T_5 V_46 = F_18 ( V_7 ) ;
union V_23 V_24 ;
exp -> V_47 . V_53 . V_7 = exp -> V_35 . V_39 . V_40 . V_53 . V_7 ;
exp -> V_48 = F_25 ;
exp -> V_32 = ! V_32 ;
if ( V_31 -> V_38 [ V_32 ] == V_7 )
V_46 = F_18 ( V_31 -> V_38 [ ! V_32 ] ) ;
for (; V_46 != 0 ; V_46 ++ ) {
int V_51 ;
exp -> V_35 . V_39 . V_40 . V_53 . V_7 = F_20 ( V_46 ) ;
V_51 = F_21 ( exp ) ;
if ( V_51 == 0 )
break;
else if ( V_51 != - V_52 ) {
V_46 = 0 ;
break;
}
}
if ( V_46 == 0 ) {
F_5 ( L_13 ) ;
return 0 ;
}
if ( F_9 ( V_2 , V_3 , 0 , & V_22 [ V_70 ] ,
& V_11 -> V_34 [ ! V_32 ] . V_35 . V_39 . V_37 ,
F_20 ( V_46 ) ) == 0 ) {
V_31 -> V_38 [ V_32 ] = V_7 ;
V_31 -> V_38 [ ! V_32 ] = F_20 ( V_46 ) ;
if ( V_70 > 0 &&
F_14 ( V_11 , * V_3 , & V_22 [ 0 ] , & V_24 , & V_7 ) &&
( F_15 ( V_24 . V_6 ) & 0xff000000 ) == 0x7f000000 ) {
F_9 ( V_2 , V_3 , 0 , & V_22 [ 0 ] ,
& V_11 -> V_34 [ ! V_32 ] . V_35 . V_39 . V_37 ,
V_31 -> V_38 [ ! V_32 ] ) ;
}
} else {
F_22 ( exp ) ;
return - 1 ;
}
F_16 ( L_14 ,
& exp -> V_35 . V_36 . V_37 . V_6 ,
F_18 ( exp -> V_35 . V_36 . V_40 . V_53 . V_7 ) ,
& exp -> V_35 . V_39 . V_37 . V_6 ,
F_18 ( exp -> V_35 . V_39 . V_40 . V_53 . V_7 ) ) ;
return 0 ;
}
static void F_29 ( struct V_10 * V_54 ,
struct V_43 * V_55 )
{
struct V_56 V_57 ;
F_26 ( V_54 -> V_58 & V_59 ) ;
V_57 . V_60 = V_61 ;
V_57 . V_62 = V_57 . V_63 = V_54 -> V_34 [ ! V_55 -> V_32 ] . V_35 . V_36 . V_37 . V_6 ;
F_27 ( V_54 , & V_57 , V_64 ) ;
V_57 . V_60 = ( V_61 | V_65 ) ;
V_57 . V_66 = V_57 . V_67 = V_55 -> V_47 ;
V_57 . V_62 = V_57 . V_63 = V_55 -> V_71 ;
F_27 ( V_54 , & V_57 , V_69 ) ;
}
static int F_30 ( struct V_1 * V_2 , struct V_10 * V_11 ,
enum V_8 V_9 ,
unsigned char * * V_3 , int V_4 ,
T_3 * V_22 , T_2 V_7 ,
struct V_43 * exp )
{
int V_32 = F_13 ( V_9 ) ;
T_5 V_46 ;
exp -> V_71 = exp -> V_35 . V_39 . V_37 . V_6 ;
exp -> V_35 . V_39 . V_37 . V_6 = V_11 -> V_34 [ ! V_32 ] . V_35 . V_39 . V_37 . V_6 ;
exp -> V_47 . V_53 . V_7 = exp -> V_35 . V_39 . V_40 . V_53 . V_7 ;
exp -> V_48 = F_29 ;
exp -> V_32 = ! V_32 ;
for ( V_46 = F_18 ( V_7 ) ; V_46 != 0 ; V_46 ++ ) {
int V_51 ;
exp -> V_35 . V_39 . V_40 . V_53 . V_7 = F_20 ( V_46 ) ;
V_51 = F_21 ( exp ) ;
if ( V_51 == 0 )
break;
else if ( V_51 != - V_52 ) {
V_46 = 0 ;
break;
}
}
if ( V_46 == 0 ) {
F_5 ( L_11 ) ;
return 0 ;
}
if ( ! F_9 ( V_2 , V_3 , V_4 , V_22 ,
& V_11 -> V_34 [ ! V_32 ] . V_35 . V_39 . V_37 ,
F_20 ( V_46 ) ) == 0 ) {
F_22 ( exp ) ;
return - 1 ;
}
F_16 ( L_15 ,
& exp -> V_35 . V_36 . V_37 . V_6 ,
F_18 ( exp -> V_35 . V_36 . V_40 . V_53 . V_7 ) ,
& exp -> V_35 . V_39 . V_37 . V_6 ,
F_18 ( exp -> V_35 . V_39 . V_40 . V_53 . V_7 ) ) ;
return 0 ;
}
static int T_6 F_31 ( void )
{
F_26 ( V_72 != NULL ) ;
F_26 ( V_73 != NULL ) ;
F_26 ( V_74 != NULL ) ;
F_26 ( V_75 != NULL ) ;
F_26 ( V_76 != NULL ) ;
F_26 ( V_77 != NULL ) ;
F_26 ( V_78 != NULL ) ;
F_26 ( V_79 != NULL ) ;
F_26 ( V_80 != NULL ) ;
F_32 ( V_72 , F_10 ) ;
F_32 ( V_73 , F_9 ) ;
F_32 ( V_74 , F_11 ) ;
F_32 ( V_75 , F_17 ) ;
F_32 ( V_76 , F_19 ) ;
F_32 ( V_77 , F_23 ) ;
F_32 ( V_78 , F_24 ) ;
F_32 ( V_79 , F_30 ) ;
F_32 ( V_80 , F_28 ) ;
F_33 ( & V_81 ) ;
F_33 ( & V_82 ) ;
return 0 ;
}
static void T_7 F_34 ( void )
{
F_32 ( V_72 , NULL ) ;
F_32 ( V_73 , NULL ) ;
F_32 ( V_74 , NULL ) ;
F_32 ( V_75 , NULL ) ;
F_32 ( V_76 , NULL ) ;
F_32 ( V_77 , NULL ) ;
F_32 ( V_78 , NULL ) ;
F_32 ( V_79 , NULL ) ;
F_32 ( V_80 , NULL ) ;
F_35 ( & V_81 ) ;
F_35 ( & V_82 ) ;
F_36 () ;
}
