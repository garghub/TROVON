static int F_1 ( struct V_1 * V_2 , unsigned int V_3 ,
unsigned char * * V_4 , int V_5 ,
unsigned int V_6 , T_1 V_7 , T_2 V_8 )
{
enum V_9 V_10 ;
struct V_11 * V_12 = F_2 ( V_2 , & V_10 ) ;
struct {
T_1 V_7 ;
T_2 V_8 ;
} V_13 ( ( V_14 ) ) V_15 ;
const struct V_16 * V_17 ;
struct V_16 V_18 ;
V_15 . V_7 = V_7 ;
V_15 . V_8 = V_8 ;
V_6 += V_5 ;
if ( F_3 ( V_2 ) -> V_19 == V_20 ) {
if ( ! F_4 ( V_2 , V_12 , V_10 ,
V_3 , V_6 , sizeof( V_15 ) ,
( char * ) & V_15 , sizeof( V_15 ) ) ) {
F_5 ( L_1 ) ;
return - 1 ;
}
V_17 = F_6 ( V_2 , F_7 ( V_2 ) ,
sizeof( V_18 ) , & V_18 ) ;
if ( V_17 == NULL )
return - 1 ;
* V_4 = V_2 -> V_4 + F_7 ( V_2 ) + V_17 -> V_21 * 4 + V_5 ;
} else {
if ( ! F_8 ( V_2 , V_12 , V_10 ,
V_3 , V_6 , sizeof( V_15 ) ,
( char * ) & V_15 , sizeof( V_15 ) ) ) {
F_5 ( L_2 ) ;
return - 1 ;
}
* V_4 = V_2 -> V_4 + F_7 ( V_2 ) + sizeof( struct V_22 ) ;
}
return 0 ;
}
static int F_9 ( struct V_1 * V_2 , unsigned int V_3 ,
unsigned char * * V_4 , int V_5 ,
T_3 * V_23 ,
union V_24 * V_25 , T_2 V_8 )
{
return F_1 ( V_2 , V_3 , V_4 , V_5 , V_23 -> V_26 . V_7 ,
V_25 -> V_7 , V_8 ) ;
}
static int F_10 ( struct V_1 * V_2 , unsigned V_3 ,
unsigned char * * V_4 , int V_5 ,
T_4 * V_23 ,
union V_24 * V_25 , T_2 V_8 )
{
return F_1 ( V_2 , V_3 , V_4 , V_5 ,
V_23 -> V_27 . V_28 . V_29 ,
V_25 -> V_7 , V_8 ) ;
}
static int F_11 ( struct V_1 * V_2 , struct V_11 * V_12 ,
enum V_9 V_10 ,
unsigned int V_3 , unsigned char * * V_4 ,
T_3 * V_23 , int V_30 )
{
const struct V_31 * V_32 = F_12 ( V_12 ) ;
int V_33 = F_13 ( V_10 ) ;
int V_34 ;
T_2 V_8 ;
union V_24 V_25 ;
for ( V_34 = 0 ; V_34 < V_30 ; V_34 ++ ) {
if ( F_14 ( V_12 , * V_4 , & V_23 [ V_34 ] , & V_25 , & V_8 ) ) {
if ( V_25 . V_7 == V_12 -> V_35 [ V_33 ] . V_36 . V_37 . V_38 . V_7 &&
V_8 == V_32 -> V_39 [ V_33 ] ) {
if ( V_34 > 0 &&
F_14 ( V_12 , * V_4 , & V_23 [ 0 ] ,
& V_25 , & V_8 ) &&
( F_15 ( V_25 . V_7 ) & 0xff000000 ) == 0x7f000000 )
V_34 = 0 ;
F_16 ( L_3 ,
& V_25 . V_7 , V_8 ,
& V_12 -> V_35 [ ! V_33 ] . V_36 . V_40 . V_38 . V_7 ,
V_32 -> V_39 [ ! V_33 ] ) ;
return F_9 ( V_2 , V_3 , V_4 , 0 ,
& V_23 [ V_34 ] ,
& V_12 -> V_35 [ ! V_33 ] .
V_36 . V_40 . V_38 ,
V_32 -> V_39 [ ! V_33 ] ) ;
} else if ( V_25 . V_7 == V_12 -> V_35 [ V_33 ] . V_36 . V_40 . V_38 . V_7 &&
V_8 == V_32 -> V_39 [ V_33 ] ) {
F_16 ( L_3 ,
& V_25 . V_7 , V_8 ,
& V_12 -> V_35 [ ! V_33 ] . V_36 . V_37 . V_38 . V_7 ,
V_32 -> V_39 [ ! V_33 ] ) ;
return F_9 ( V_2 , V_3 , V_4 , 0 ,
& V_23 [ V_34 ] ,
& V_12 -> V_35 [ ! V_33 ] .
V_36 . V_37 . V_38 ,
V_32 -> V_39 [ ! V_33 ] ) ;
}
}
}
return 0 ;
}
static int F_17 ( struct V_1 * V_2 , struct V_11 * V_12 ,
enum V_9 V_10 ,
unsigned int V_3 , unsigned char * * V_4 ,
T_3 * V_23 , int V_30 )
{
int V_33 = F_13 ( V_10 ) ;
int V_34 ;
T_2 V_8 ;
union V_24 V_25 ;
for ( V_34 = 0 ; V_34 < V_30 ; V_34 ++ ) {
if ( F_14 ( V_12 , * V_4 , & V_23 [ V_34 ] , & V_25 , & V_8 ) &&
V_25 . V_7 == V_12 -> V_35 [ V_33 ] . V_36 . V_37 . V_38 . V_7 &&
V_8 == V_12 -> V_35 [ V_33 ] . V_36 . V_37 . V_41 . V_42 . V_8 ) {
F_16 ( L_4 ,
& V_25 . V_7 , F_18 ( V_8 ) ,
& V_12 -> V_35 [ ! V_33 ] . V_36 . V_40 . V_38 . V_7 ,
F_18 ( V_12 -> V_35 [ ! V_33 ] . V_36 . V_40 . V_41 . V_42 . V_8 ) ) ;
return F_9 ( V_2 , V_3 , V_4 , 0 , & V_23 [ V_34 ] ,
& V_12 -> V_35 [ ! V_33 ] . V_36 . V_40 . V_38 ,
V_12 -> V_35 [ ! V_33 ] . V_36 .
V_40 . V_41 . V_42 . V_8 ) ;
}
}
return 0 ;
}
static int F_19 ( struct V_1 * V_2 , struct V_11 * V_12 ,
enum V_9 V_10 ,
unsigned int V_3 , unsigned char * * V_4 , int V_5 ,
T_4 * V_23 ,
T_2 V_8 , T_2 V_43 ,
struct V_44 * V_45 ,
struct V_44 * V_46 )
{
struct V_31 * V_32 = F_12 ( V_12 ) ;
int V_33 = F_13 ( V_10 ) ;
int V_34 ;
T_5 V_47 ;
V_45 -> V_48 . V_42 . V_8 = V_45 -> V_36 . V_40 . V_41 . V_42 . V_8 ;
V_45 -> V_49 = V_50 ;
V_45 -> V_33 = ! V_33 ;
V_46 -> V_48 . V_42 . V_8 = V_46 -> V_36 . V_40 . V_41 . V_42 . V_8 ;
V_46 -> V_49 = V_50 ;
V_46 -> V_33 = ! V_33 ;
for ( V_34 = 0 ; V_34 < V_51 ; V_34 ++ ) {
if ( V_32 -> V_43 [ V_34 ] [ V_33 ] == V_43 ) {
V_45 -> V_36 . V_40 . V_41 . V_42 . V_8 = V_32 -> V_43 [ V_34 ] [ V_33 ] ;
V_46 -> V_36 . V_40 . V_41 . V_42 . V_8 =
F_20 ( F_18 ( V_32 -> V_43 [ V_34 ] [ V_33 ] ) + 1 ) ;
break;
} else if ( V_32 -> V_43 [ V_34 ] [ V_33 ] == 0 ) {
break;
}
}
if ( V_34 >= V_51 ) {
F_5 ( L_5 ) ;
return 0 ;
}
for ( V_47 = F_18 ( V_45 -> V_36 . V_40 . V_41 . V_42 . V_8 ) ;
V_47 != 0 ; V_47 += 2 ) {
int V_52 ;
V_45 -> V_36 . V_40 . V_41 . V_42 . V_8 = F_20 ( V_47 ) ;
V_52 = F_21 ( V_45 ) ;
if ( V_52 == 0 ) {
V_46 -> V_36 . V_40 . V_41 . V_42 . V_8 =
F_20 ( V_47 + 1 ) ;
V_52 = F_21 ( V_46 ) ;
if ( V_52 == 0 )
break;
else if ( V_52 == - V_53 ) {
F_22 ( V_45 ) ;
continue;
} else if ( V_52 < 0 ) {
F_22 ( V_45 ) ;
V_47 = 0 ;
break;
}
} else if ( V_52 != - V_53 ) {
V_47 = 0 ;
break;
}
}
if ( V_47 == 0 ) {
F_5 ( L_6 ) ;
return 0 ;
}
if ( F_10 ( V_2 , V_3 , V_4 , V_5 , V_23 ,
& V_12 -> V_35 [ ! V_33 ] . V_36 . V_40 . V_38 ,
F_20 ( ( V_8 & F_20 ( 1 ) ) ? V_47 + 1 :
V_47 ) ) ) {
F_22 ( V_45 ) ;
F_22 ( V_46 ) ;
return - 1 ;
}
V_32 -> V_43 [ V_34 ] [ V_33 ] = V_43 ;
V_32 -> V_43 [ V_34 ] [ ! V_33 ] = F_20 ( V_47 ) ;
F_16 ( L_7 ,
& V_45 -> V_36 . V_37 . V_38 . V_7 ,
F_18 ( V_45 -> V_36 . V_37 . V_41 . V_42 . V_8 ) ,
& V_45 -> V_36 . V_40 . V_38 . V_7 ,
F_18 ( V_45 -> V_36 . V_40 . V_41 . V_42 . V_8 ) ) ;
F_16 ( L_8 ,
& V_46 -> V_36 . V_37 . V_38 . V_7 ,
F_18 ( V_46 -> V_36 . V_37 . V_41 . V_42 . V_8 ) ,
& V_46 -> V_36 . V_40 . V_38 . V_7 ,
F_18 ( V_46 -> V_36 . V_40 . V_41 . V_42 . V_8 ) ) ;
return 0 ;
}
static int F_23 ( struct V_1 * V_2 , struct V_11 * V_12 ,
enum V_9 V_10 ,
unsigned int V_3 , unsigned char * * V_4 , int V_5 ,
T_4 * V_23 , T_2 V_8 ,
struct V_44 * exp )
{
int V_33 = F_13 ( V_10 ) ;
T_5 V_47 = F_18 ( V_8 ) ;
exp -> V_48 . V_54 . V_8 = exp -> V_36 . V_40 . V_41 . V_54 . V_8 ;
exp -> V_49 = V_50 ;
exp -> V_33 = ! V_33 ;
for (; V_47 != 0 ; V_47 ++ ) {
int V_52 ;
exp -> V_36 . V_40 . V_41 . V_54 . V_8 = F_20 ( V_47 ) ;
V_52 = F_21 ( exp ) ;
if ( V_52 == 0 )
break;
else if ( V_52 != - V_53 ) {
V_47 = 0 ;
break;
}
}
if ( V_47 == 0 ) {
F_5 ( L_9 ) ;
return 0 ;
}
if ( F_10 ( V_2 , V_3 , V_4 , V_5 , V_23 ,
& V_12 -> V_35 [ ! V_33 ] . V_36 . V_40 . V_38 ,
F_20 ( V_47 ) ) < 0 ) {
F_22 ( exp ) ;
return - 1 ;
}
F_16 ( L_10 ,
& exp -> V_36 . V_37 . V_38 . V_7 ,
F_18 ( exp -> V_36 . V_37 . V_41 . V_54 . V_8 ) ,
& exp -> V_36 . V_40 . V_38 . V_7 ,
F_18 ( exp -> V_36 . V_40 . V_41 . V_54 . V_8 ) ) ;
return 0 ;
}
static int F_24 ( struct V_1 * V_2 , struct V_11 * V_12 ,
enum V_9 V_10 ,
unsigned int V_3 , unsigned char * * V_4 , int V_5 ,
T_3 * V_23 , T_2 V_8 ,
struct V_44 * exp )
{
struct V_31 * V_32 = F_12 ( V_12 ) ;
int V_33 = F_13 ( V_10 ) ;
T_5 V_47 = F_18 ( V_8 ) ;
exp -> V_48 . V_54 . V_8 = exp -> V_36 . V_40 . V_41 . V_54 . V_8 ;
exp -> V_49 = V_50 ;
exp -> V_33 = ! V_33 ;
if ( V_32 -> V_39 [ V_33 ] == V_8 )
V_47 = F_18 ( V_32 -> V_39 [ ! V_33 ] ) ;
for (; V_47 != 0 ; V_47 ++ ) {
int V_52 ;
exp -> V_36 . V_40 . V_41 . V_54 . V_8 = F_20 ( V_47 ) ;
V_52 = F_21 ( exp ) ;
if ( V_52 == 0 )
break;
else if ( V_52 != - V_53 ) {
V_47 = 0 ;
break;
}
}
if ( V_47 == 0 ) {
F_5 ( L_11 ) ;
return 0 ;
}
if ( F_9 ( V_2 , V_3 , V_4 , V_5 , V_23 ,
& V_12 -> V_35 [ ! V_33 ] . V_36 . V_40 . V_38 ,
F_20 ( V_47 ) ) ) {
F_22 ( exp ) ;
return - 1 ;
}
V_32 -> V_39 [ V_33 ] = V_8 ;
V_32 -> V_39 [ ! V_33 ] = F_20 ( V_47 ) ;
F_16 ( L_12 ,
& exp -> V_36 . V_37 . V_38 . V_7 ,
F_18 ( exp -> V_36 . V_37 . V_41 . V_54 . V_8 ) ,
& exp -> V_36 . V_40 . V_38 . V_7 ,
F_18 ( exp -> V_36 . V_40 . V_41 . V_54 . V_8 ) ) ;
return 0 ;
}
static void F_25 ( struct V_11 * V_55 ,
struct V_44 * V_56 )
{
struct V_57 V_58 ;
if ( V_56 -> V_36 . V_37 . V_38 . V_7 != 0 ) {
V_50 ( V_55 , V_56 ) ;
return;
}
F_26 ( V_55 -> V_59 & V_60 ) ;
V_58 . V_61 = V_62 ;
V_58 . V_63 = V_58 . V_64 =
V_55 -> V_35 [ ! V_56 -> V_33 ] . V_36 . V_37 . V_38 ;
F_27 ( V_55 , & V_58 , V_65 ) ;
V_58 . V_61 = ( V_62 | V_66 ) ;
V_58 . V_67 = V_58 . V_68 = V_56 -> V_48 ;
V_58 . V_63 = V_58 . V_64 =
V_55 -> V_69 -> V_35 [ ! V_56 -> V_33 ] . V_36 . V_37 . V_38 ;
F_27 ( V_55 , & V_58 , V_70 ) ;
}
static int F_28 ( struct V_1 * V_2 , struct V_11 * V_12 ,
enum V_9 V_10 ,
unsigned int V_3 , unsigned char * * V_4 ,
T_3 * V_23 , int V_71 ,
T_2 V_8 , struct V_44 * exp )
{
struct V_31 * V_32 = F_12 ( V_12 ) ;
int V_33 = F_13 ( V_10 ) ;
T_5 V_47 = F_18 ( V_8 ) ;
union V_24 V_25 ;
exp -> V_48 . V_54 . V_8 = exp -> V_36 . V_40 . V_41 . V_54 . V_8 ;
exp -> V_49 = F_25 ;
exp -> V_33 = ! V_33 ;
if ( V_32 -> V_39 [ V_33 ] == V_8 )
V_47 = F_18 ( V_32 -> V_39 [ ! V_33 ] ) ;
for (; V_47 != 0 ; V_47 ++ ) {
int V_52 ;
exp -> V_36 . V_40 . V_41 . V_54 . V_8 = F_20 ( V_47 ) ;
V_52 = F_21 ( exp ) ;
if ( V_52 == 0 )
break;
else if ( V_52 != - V_53 ) {
V_47 = 0 ;
break;
}
}
if ( V_47 == 0 ) {
F_5 ( L_13 ) ;
return 0 ;
}
if ( F_9 ( V_2 , V_3 , V_4 , 0 , & V_23 [ V_71 ] ,
& V_12 -> V_35 [ ! V_33 ] . V_36 . V_40 . V_38 ,
F_20 ( V_47 ) ) ) {
F_22 ( exp ) ;
return - 1 ;
}
V_32 -> V_39 [ V_33 ] = V_8 ;
V_32 -> V_39 [ ! V_33 ] = F_20 ( V_47 ) ;
if ( V_71 > 0 &&
F_14 ( V_12 , * V_4 , & V_23 [ 0 ] , & V_25 , & V_8 ) &&
( F_15 ( V_25 . V_7 ) & 0xff000000 ) == 0x7f000000 ) {
if ( F_9 ( V_2 , V_3 , V_4 , 0 , & V_23 [ 0 ] ,
& V_12 -> V_35 [ ! V_33 ] . V_36 . V_40 . V_38 ,
V_32 -> V_39 [ ! V_33 ] ) ) {
F_22 ( exp ) ;
return - 1 ;
}
}
F_16 ( L_14 ,
& exp -> V_36 . V_37 . V_38 . V_7 ,
F_18 ( exp -> V_36 . V_37 . V_41 . V_54 . V_8 ) ,
& exp -> V_36 . V_40 . V_38 . V_7 ,
F_18 ( exp -> V_36 . V_40 . V_41 . V_54 . V_8 ) ) ;
return 0 ;
}
static void F_29 ( struct V_11 * V_55 ,
struct V_44 * V_56 )
{
struct V_57 V_58 ;
F_26 ( V_55 -> V_59 & V_60 ) ;
V_58 . V_61 = V_62 ;
V_58 . V_63 = V_58 . V_64 =
V_55 -> V_35 [ ! V_56 -> V_33 ] . V_36 . V_37 . V_38 ;
F_27 ( V_55 , & V_58 , V_65 ) ;
V_58 . V_61 = ( V_62 | V_66 ) ;
V_58 . V_67 = V_58 . V_68 = V_56 -> V_48 ;
V_58 . V_63 = V_58 . V_64 = V_56 -> V_72 ;
F_27 ( V_55 , & V_58 , V_70 ) ;
}
static int F_30 ( struct V_1 * V_2 , struct V_11 * V_12 ,
enum V_9 V_10 ,
unsigned int V_3 ,
unsigned char * * V_4 , int V_5 ,
T_3 * V_23 , T_2 V_8 ,
struct V_44 * exp )
{
int V_33 = F_13 ( V_10 ) ;
T_5 V_47 ;
exp -> V_72 = exp -> V_36 . V_40 . V_38 ;
exp -> V_36 . V_40 . V_38 . V_7 = V_12 -> V_35 [ ! V_33 ] . V_36 . V_40 . V_38 . V_7 ;
exp -> V_48 . V_54 . V_8 = exp -> V_36 . V_40 . V_41 . V_54 . V_8 ;
exp -> V_49 = F_29 ;
exp -> V_33 = ! V_33 ;
for ( V_47 = F_18 ( V_8 ) ; V_47 != 0 ; V_47 ++ ) {
int V_52 ;
exp -> V_36 . V_40 . V_41 . V_54 . V_8 = F_20 ( V_47 ) ;
V_52 = F_21 ( exp ) ;
if ( V_52 == 0 )
break;
else if ( V_52 != - V_53 ) {
V_47 = 0 ;
break;
}
}
if ( V_47 == 0 ) {
F_5 ( L_11 ) ;
return 0 ;
}
if ( F_9 ( V_2 , V_3 , V_4 , V_5 , V_23 ,
& V_12 -> V_35 [ ! V_33 ] . V_36 . V_40 . V_38 ,
F_20 ( V_47 ) ) ) {
F_22 ( exp ) ;
return - 1 ;
}
F_16 ( L_15 ,
& exp -> V_36 . V_37 . V_38 . V_7 ,
F_18 ( exp -> V_36 . V_37 . V_41 . V_54 . V_8 ) ,
& exp -> V_36 . V_40 . V_38 . V_7 ,
F_18 ( exp -> V_36 . V_40 . V_41 . V_54 . V_8 ) ) ;
return 0 ;
}
static int T_6 F_31 ( void )
{
F_26 ( V_73 != NULL ) ;
F_26 ( V_74 != NULL ) ;
F_26 ( V_75 != NULL ) ;
F_26 ( V_76 != NULL ) ;
F_26 ( V_77 != NULL ) ;
F_26 ( V_78 != NULL ) ;
F_26 ( V_79 != NULL ) ;
F_26 ( V_80 != NULL ) ;
F_26 ( V_81 != NULL ) ;
F_32 ( V_73 , F_10 ) ;
F_32 ( V_74 , F_9 ) ;
F_32 ( V_75 , F_11 ) ;
F_32 ( V_76 , F_17 ) ;
F_32 ( V_77 , F_19 ) ;
F_32 ( V_78 , F_23 ) ;
F_32 ( V_79 , F_24 ) ;
F_32 ( V_80 , F_30 ) ;
F_32 ( V_81 , F_28 ) ;
F_33 ( & V_82 ) ;
F_33 ( & V_83 ) ;
return 0 ;
}
static void T_7 F_34 ( void )
{
F_32 ( V_73 , NULL ) ;
F_32 ( V_74 , NULL ) ;
F_32 ( V_75 , NULL ) ;
F_32 ( V_76 , NULL ) ;
F_32 ( V_77 , NULL ) ;
F_32 ( V_78 , NULL ) ;
F_32 ( V_79 , NULL ) ;
F_32 ( V_80 , NULL ) ;
F_32 ( V_81 , NULL ) ;
F_35 ( & V_82 ) ;
F_35 ( & V_83 ) ;
F_36 () ;
}
