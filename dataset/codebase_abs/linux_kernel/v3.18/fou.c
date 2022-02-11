static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
return V_3 -> V_4 ;
}
static int F_2 ( struct V_5 * V_6 ,
T_1 V_7 , T_2 V_8 )
{
struct V_9 * V_10 = F_3 ( V_6 ) ;
V_10 -> V_11 = F_4 ( F_5 ( V_10 -> V_11 ) - V_8 ) ;
F_6 ( V_6 , V_8 ) ;
F_7 ( V_6 , F_8 ( V_6 ) , V_8 ) ;
F_9 ( V_6 ) ;
return - V_7 ;
}
static int F_10 ( struct V_2 * V_3 , struct V_5 * V_6 )
{
struct V_1 * V_1 = F_1 ( V_3 ) ;
if ( ! V_1 )
return 1 ;
return F_2 ( V_6 , V_1 -> V_7 ,
sizeof( struct V_12 ) ) ;
}
static int F_11 ( struct V_2 * V_3 , struct V_5 * V_6 )
{
struct V_1 * V_1 = F_1 ( V_3 ) ;
T_2 V_8 ;
struct V_13 * V_13 ;
struct V_12 * V_14 ;
if ( ! V_1 )
return 1 ;
V_8 = sizeof( struct V_12 ) + sizeof( struct V_13 ) ;
if ( ! F_12 ( V_6 , V_8 ) )
goto V_15;
V_14 = F_8 ( V_6 ) ;
V_13 = (struct V_13 * ) & V_14 [ 1 ] ;
V_8 += V_13 -> V_16 << 2 ;
if ( ! F_12 ( V_6 , V_8 ) )
goto V_15;
V_14 = F_8 ( V_6 ) ;
V_13 = (struct V_13 * ) & V_14 [ 1 ] ;
if ( V_13 -> V_17 != 0 )
goto V_15;
if ( V_13 -> V_18 ) {
goto V_15;
}
return F_2 ( V_6 , V_13 -> V_19 , V_8 ) ;
V_15:
F_13 ( V_6 ) ;
return 0 ;
}
static struct V_5 * * F_14 ( struct V_5 * * V_20 ,
struct V_5 * V_6 )
{
const struct V_21 * V_22 ;
struct V_5 * * V_23 = NULL ;
T_1 V_24 = F_15 ( V_6 ) -> V_24 ;
const struct V_21 * * V_25 ;
F_16 () ;
V_25 = F_15 ( V_6 ) -> V_26 ? V_27 : V_28 ;
V_22 = F_17 ( V_25 [ V_24 ] ) ;
if ( ! V_22 || ! V_22 -> V_29 . V_30 )
goto V_31;
V_23 = V_22 -> V_29 . V_30 ( V_20 , V_6 ) ;
V_31:
F_18 () ;
return V_23 ;
}
static int F_19 ( struct V_5 * V_6 , int V_32 )
{
const struct V_21 * V_22 ;
T_1 V_24 = F_15 ( V_6 ) -> V_24 ;
int V_33 = - V_34 ;
const struct V_21 * * V_25 ;
F_20 ( V_6 , V_32 ) ;
F_16 () ;
V_25 = F_15 ( V_6 ) -> V_26 ? V_27 : V_28 ;
V_22 = F_17 ( V_25 [ V_24 ] ) ;
if ( F_21 ( ! V_22 || ! V_22 -> V_29 . V_35 ) )
goto V_31;
V_33 = V_22 -> V_29 . V_35 ( V_6 , V_32 ) ;
V_31:
F_18 () ;
return V_33 ;
}
static struct V_5 * * F_22 ( struct V_5 * * V_20 ,
struct V_5 * V_6 )
{
const struct V_21 * * V_25 ;
const struct V_21 * V_22 ;
struct V_5 * * V_23 = NULL ;
struct V_5 * V_36 ;
T_1 V_24 ;
struct V_13 * V_13 ;
unsigned int V_16 , V_37 ;
unsigned int V_38 ;
int V_39 = 1 ;
V_38 = F_23 ( V_6 ) ;
V_16 = V_38 + sizeof( * V_13 ) ;
V_13 = F_24 ( V_6 , V_38 ) ;
if ( F_25 ( V_6 , V_16 ) ) {
V_13 = F_26 ( V_6 , V_16 , V_38 ) ;
if ( F_27 ( ! V_13 ) )
goto V_40;
}
V_24 = V_13 -> V_19 ;
F_16 () ;
V_25 = F_15 ( V_6 ) -> V_26 ? V_27 : V_28 ;
V_22 = F_17 ( V_25 [ V_24 ] ) ;
if ( F_21 ( ! V_22 || ! V_22 -> V_29 . V_30 ) )
goto V_31;
V_37 = sizeof( * V_13 ) + ( V_13 -> V_16 << 2 ) ;
V_16 = V_38 + V_37 ;
if ( F_25 ( V_6 , V_16 ) ) {
V_13 = F_26 ( V_6 , V_16 , V_38 ) ;
if ( F_27 ( ! V_13 ) )
goto V_31;
}
V_39 = 0 ;
for ( V_36 = * V_20 ; V_36 ; V_36 = V_36 -> V_41 ) {
const struct V_13 * V_42 ;
if ( ! F_15 ( V_36 ) -> V_43 )
continue;
V_42 = (struct V_13 * ) ( V_36 -> V_44 + V_38 ) ;
if ( V_13 -> V_45 != V_42 -> V_45 ) {
F_15 ( V_36 ) -> V_43 = 0 ;
continue;
}
if ( V_13 -> V_16 && memcmp ( & V_13 [ 1 ] , & V_42 [ 1 ] ,
V_13 -> V_16 << 2 ) ) {
F_15 ( V_36 ) -> V_43 = 0 ;
continue;
}
}
F_28 ( V_6 , V_37 ) ;
F_29 ( V_6 , V_13 , V_37 ) ;
V_23 = V_22 -> V_29 . V_30 ( V_20 , V_6 ) ;
V_31:
F_18 () ;
V_40:
F_15 ( V_6 ) -> V_39 |= V_39 ;
return V_23 ;
}
static int F_30 ( struct V_5 * V_6 , int V_32 )
{
const struct V_21 * * V_25 ;
struct V_13 * V_13 = (struct V_13 * ) ( V_6 -> V_44 + V_32 ) ;
const struct V_21 * V_22 ;
unsigned int V_37 ;
T_1 V_24 ;
int V_33 = - V_46 ;
V_24 = V_13 -> V_19 ;
V_37 = sizeof( * V_13 ) + ( V_13 -> V_16 << 2 ) ;
F_16 () ;
V_25 = F_15 ( V_6 ) -> V_26 ? V_27 : V_28 ;
V_22 = F_17 ( V_25 [ V_24 ] ) ;
if ( F_21 ( ! V_22 || ! V_22 -> V_29 . V_35 ) )
goto V_31;
V_33 = V_22 -> V_29 . V_35 ( V_6 , V_32 + V_37 ) ;
V_31:
F_18 () ;
return V_33 ;
}
static int F_31 ( struct V_1 * V_1 )
{
struct V_1 * V_47 ;
F_32 ( & V_48 ) ;
F_33 (fout, &fou_list, list) {
if ( V_1 -> V_49 == V_47 -> V_49 ) {
F_34 ( & V_48 ) ;
return - V_50 ;
}
}
F_35 ( & V_1 -> V_51 , & V_52 ) ;
F_34 ( & V_48 ) ;
return 0 ;
}
static void F_36 ( struct V_1 * V_1 )
{
struct V_53 * V_2 = V_1 -> V_2 ;
struct V_2 * V_3 = V_2 -> V_3 ;
F_37 ( & V_1 -> V_54 ) ;
F_38 ( & V_1 -> V_51 ) ;
V_3 -> V_4 = NULL ;
F_39 ( V_2 ) ;
F_40 ( V_1 ) ;
}
static int F_41 ( struct V_2 * V_3 , struct V_1 * V_1 , struct V_55 * V_56 )
{
F_42 ( V_3 ) -> V_57 = F_10 ;
V_1 -> V_7 = V_56 -> V_7 ;
V_1 -> V_54 . V_29 . V_30 = F_14 ;
V_1 -> V_54 . V_29 . V_35 = F_19 ;
V_1 -> V_54 . V_49 = V_56 -> V_58 . V_59 ;
V_1 -> V_54 . V_60 = V_56 -> V_7 ;
return 0 ;
}
static int F_43 ( struct V_2 * V_3 , struct V_1 * V_1 , struct V_55 * V_56 )
{
F_42 ( V_3 ) -> V_57 = F_11 ;
V_1 -> V_54 . V_29 . V_30 = F_22 ;
V_1 -> V_54 . V_29 . V_35 = F_30 ;
V_1 -> V_54 . V_49 = V_56 -> V_58 . V_59 ;
return 0 ;
}
static int F_44 ( struct V_61 * V_61 , struct V_55 * V_56 ,
struct V_53 * * V_62 )
{
struct V_1 * V_1 = NULL ;
int V_33 ;
struct V_53 * V_2 = NULL ;
struct V_2 * V_3 ;
V_33 = F_45 ( V_61 , & V_56 -> V_58 , & V_2 ) ;
if ( V_33 < 0 )
goto error;
V_1 = F_46 ( sizeof( * V_1 ) , V_63 ) ;
if ( ! V_1 ) {
V_33 = - V_64 ;
goto error;
}
V_3 = V_2 -> V_3 ;
V_1 -> V_49 = V_56 -> V_58 . V_59 ;
switch ( V_56 -> type ) {
case V_65 :
V_33 = F_41 ( V_3 , V_1 , V_56 ) ;
if ( V_33 )
goto error;
break;
case V_66 :
V_33 = F_43 ( V_3 , V_1 , V_56 ) ;
if ( V_33 )
goto error;
break;
default:
V_33 = - V_67 ;
goto error;
}
F_42 ( V_3 ) -> V_68 = 1 ;
F_47 () ;
V_3 -> V_4 = V_1 ;
V_1 -> V_2 = V_2 ;
F_48 ( V_3 , true ) ;
V_3 -> V_69 = V_70 ;
if ( V_56 -> V_58 . V_71 == V_72 ) {
V_33 = F_49 ( & V_1 -> V_54 ) ;
if ( V_33 )
goto error;
}
V_33 = F_31 ( V_1 ) ;
if ( V_33 )
goto error;
if ( V_62 )
* V_62 = V_2 ;
return 0 ;
error:
F_40 ( V_1 ) ;
if ( V_2 )
F_39 ( V_2 ) ;
return V_33 ;
}
static int F_50 ( struct V_61 * V_61 , struct V_55 * V_56 )
{
struct V_1 * V_1 ;
T_3 V_49 = V_56 -> V_58 . V_59 ;
int V_33 = - V_67 ;
F_32 ( & V_48 ) ;
F_33 (fou, &fou_list, list) {
if ( V_1 -> V_49 == V_49 ) {
F_37 ( & V_1 -> V_54 ) ;
F_36 ( V_1 ) ;
V_33 = 0 ;
break;
}
}
F_34 ( & V_48 ) ;
return V_33 ;
}
static int F_51 ( struct V_73 * V_74 ,
struct V_55 * V_56 )
{
memset ( V_56 , 0 , sizeof( * V_56 ) ) ;
V_56 -> V_58 . V_71 = V_72 ;
if ( V_74 -> V_75 [ V_76 ] ) {
T_1 V_71 = F_52 ( V_74 -> V_75 [ V_76 ] ) ;
if ( V_71 != V_72 && V_71 != V_77 )
return - V_67 ;
V_56 -> V_58 . V_71 = V_71 ;
}
if ( V_74 -> V_75 [ V_78 ] ) {
T_3 V_49 = F_53 ( V_74 -> V_75 [ V_78 ] ) ;
V_56 -> V_58 . V_59 = V_49 ;
}
if ( V_74 -> V_75 [ V_79 ] )
V_56 -> V_7 = F_52 ( V_74 -> V_75 [ V_79 ] ) ;
if ( V_74 -> V_75 [ V_80 ] )
V_56 -> type = F_52 ( V_74 -> V_75 [ V_80 ] ) ;
return 0 ;
}
static int F_54 ( struct V_5 * V_6 , struct V_73 * V_74 )
{
struct V_55 V_56 ;
int V_33 ;
V_33 = F_51 ( V_74 , & V_56 ) ;
if ( V_33 )
return V_33 ;
return F_44 ( & V_81 , & V_56 , NULL ) ;
}
static int F_55 ( struct V_5 * V_6 , struct V_73 * V_74 )
{
struct V_55 V_56 ;
F_51 ( V_74 , & V_56 ) ;
return F_50 ( & V_81 , & V_56 ) ;
}
static int T_4 F_56 ( void )
{
int V_82 ;
V_82 = F_57 ( & V_83 ,
V_84 ) ;
return V_82 ;
}
static void T_5 F_58 ( void )
{
struct V_1 * V_1 , * V_41 ;
F_59 ( & V_83 ) ;
F_32 ( & V_48 ) ;
F_60 (fou, next, &fou_list, list)
F_36 ( V_1 ) ;
F_34 ( & V_48 ) ;
}
