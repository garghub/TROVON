static int F_1 ( struct V_1 * V_2 , struct V_3 * V_4 ,
char * V_5 , struct V_3 * V_6 )
{
const struct V_7 * V_8 = V_4 -> V_9 -> V_10 ;
struct V_11 V_11 = { . V_2 = V_2 , . V_3 = V_4 } ;
if ( V_8 -> V_12 )
return V_8 -> V_12 ( V_4 , V_5 , V_6 ) ;
else
return V_12 ( & V_11 , V_5 , V_6 ) ;
}
static struct V_3 *
F_2 ( struct V_3 * V_13 ,
int (* F_3)( void * V_14 , struct V_3 * V_3 ) ,
void * V_14 )
{
struct V_3 * V_3 , * V_15 = NULL ;
struct V_16 * V_16 ;
if ( F_3 ( V_14 , V_13 ) )
return V_13 ;
V_16 = V_13 -> V_17 ;
F_4 ( & V_16 -> V_18 ) ;
F_5 (dentry, &inode->i_dentry, d_u.d_alias) {
F_6 ( V_3 ) ;
F_7 ( & V_16 -> V_18 ) ;
if ( V_15 )
F_8 ( V_15 ) ;
if ( V_3 != V_13 && F_3 ( V_14 , V_3 ) ) {
F_8 ( V_13 ) ;
return V_3 ;
}
F_4 ( & V_16 -> V_18 ) ;
V_15 = V_3 ;
}
F_7 ( & V_16 -> V_18 ) ;
if ( V_15 )
F_8 ( V_15 ) ;
return NULL ;
}
static bool F_9 ( struct V_3 * V_3 )
{
F_6 ( V_3 ) ;
while ( V_3 -> V_19 & V_20 ) {
struct V_3 * V_21 = F_10 ( V_3 ) ;
F_8 ( V_3 ) ;
if ( F_11 ( V_3 ) ) {
F_8 ( V_21 ) ;
return false ;
}
V_3 = V_21 ;
}
F_8 ( V_3 ) ;
return true ;
}
static void F_12 ( struct V_3 * V_3 )
{
F_6 ( V_3 ) ;
while ( V_3 -> V_19 & V_20 ) {
struct V_3 * V_21 = F_10 ( V_3 ) ;
F_13 ( F_11 ( V_3 ) ) ;
F_4 ( & V_3 -> V_22 ) ;
V_3 -> V_19 &= ~ V_20 ;
F_7 ( & V_3 -> V_22 ) ;
F_8 ( V_3 ) ;
V_3 = V_21 ;
}
F_8 ( V_3 ) ;
}
static struct V_3 * F_14 ( struct V_1 * V_2 ,
struct V_3 * V_3 , char * V_23 )
{
struct V_3 * V_21 ;
struct V_3 * V_24 ;
int V_25 ;
V_21 = F_15 ( - V_26 ) ;
F_16 ( & V_3 -> V_17 -> V_27 ) ;
if ( V_2 -> V_28 -> V_10 -> V_29 )
V_21 = V_2 -> V_28 -> V_10 -> V_29 ( V_3 ) ;
F_17 ( & V_3 -> V_17 -> V_27 ) ;
if ( F_18 ( V_21 ) ) {
F_19 ( L_1 ,
V_30 , V_3 -> V_17 -> V_31 , F_20 ( V_21 ) ) ;
return V_21 ;
}
F_19 ( L_2 , V_30 ,
V_3 -> V_17 -> V_31 , V_21 -> V_17 -> V_31 ) ;
V_25 = F_1 ( V_2 , V_21 , V_23 , V_3 ) ;
if ( V_25 == - V_32 )
goto V_33;
if ( V_25 )
goto V_34;
F_19 ( L_3 , V_30 , V_23 ) ;
F_16 ( & V_21 -> V_17 -> V_27 ) ;
V_24 = F_21 ( V_23 , V_21 , strlen ( V_23 ) ) ;
F_17 ( & V_21 -> V_17 -> V_27 ) ;
if ( F_18 ( V_24 ) ) {
F_19 ( L_4 , V_30 , F_20 ( V_24 ) ) ;
goto V_34;
}
if ( V_24 != V_3 ) {
F_8 ( V_24 ) ;
goto V_33;
}
F_8 ( V_24 ) ;
if ( F_11 ( V_3 ) ) {
V_25 = - V_35 ;
goto V_34;
}
return V_21 ;
V_34:
F_8 ( V_21 ) ;
return F_15 ( V_25 ) ;
V_33:
F_8 ( V_21 ) ;
if ( ! F_9 ( V_3 ) )
return F_15 ( - V_35 ) ;
return NULL ;
}
static int
F_22 ( struct V_1 * V_2 , struct V_3 * V_36 , char * V_23 )
{
struct V_3 * V_3 , * V_21 ;
V_3 = F_6 ( V_36 ) ;
while ( V_3 -> V_19 & V_20 ) {
F_23 ( V_3 == V_2 -> V_28 -> V_37 ) ;
if ( F_11 ( V_3 ) )
V_21 = F_14 ( V_2 , V_3 , V_23 ) ;
else
V_21 = F_10 ( V_3 ) ;
if ( ! V_21 )
break;
F_8 ( V_3 ) ;
if ( F_18 ( V_21 ) )
return F_20 ( V_21 ) ;
V_3 = V_21 ;
}
F_8 ( V_3 ) ;
F_12 ( V_36 ) ;
return 0 ;
}
static int F_24 ( struct V_38 * V_39 , const char * V_5 , int V_40 ,
T_1 V_41 , T_2 V_42 , unsigned int V_43 )
{
struct V_44 * V_45 =
F_25 ( V_39 , struct V_44 , V_39 ) ;
int V_13 = 0 ;
V_45 -> V_46 ++ ;
if ( V_45 -> V_42 == V_42 && V_40 <= V_47 ) {
memcpy ( V_45 -> V_5 , V_5 , V_40 ) ;
V_45 -> V_5 [ V_40 ] = '\0' ;
V_45 -> V_48 = 1 ;
V_13 = - 1 ;
}
return V_13 ;
}
static int V_12 ( const struct V_11 * V_11 , char * V_5 , struct V_3 * V_6 )
{
const struct V_49 * V_49 = F_26 () ;
struct V_16 * V_4 = V_11 -> V_3 -> V_17 ;
int error ;
struct V_50 * V_50 ;
struct V_51 V_52 ;
struct V_11 V_53 = {
. V_2 = V_11 -> V_2 ,
. V_3 = V_6 ,
} ;
struct V_44 V_54 = {
. V_39 . V_55 = F_24 ,
. V_5 = V_5 ,
} ;
error = - V_56 ;
if ( ! V_4 || ! F_27 ( V_4 -> V_57 ) )
goto V_58;
error = - V_59 ;
if ( ! V_4 -> V_60 )
goto V_58;
error = F_28 ( & V_53 , & V_52 ) ;
if ( error )
return error ;
V_54 . V_42 = V_52 . V_42 ;
V_50 = F_29 ( V_11 , V_61 , V_49 ) ;
error = F_20 ( V_50 ) ;
if ( F_18 ( V_50 ) )
goto V_58;
error = - V_59 ;
if ( ! V_50 -> V_62 -> V_63 )
goto V_64;
V_54 . V_46 = 0 ;
while ( 1 ) {
int V_65 = V_54 . V_46 ;
error = F_30 ( V_50 , & V_54 . V_39 ) ;
if ( V_54 . V_48 ) {
error = 0 ;
break;
}
if ( error < 0 )
break;
error = - V_32 ;
if ( V_65 == V_54 . V_46 )
break;
}
V_64:
F_31 ( V_50 ) ;
V_58:
return error ;
}
static int F_32 ( struct V_16 * V_16 , struct V_66 * V_66 ,
int * V_67 , struct V_16 * V_21 )
{
int V_40 = * V_67 ;
int type = V_68 ;
if ( V_21 && ( V_40 < 4 ) ) {
* V_67 = 4 ;
return V_69 ;
} else if ( V_40 < 2 ) {
* V_67 = 2 ;
return V_69 ;
}
V_40 = 2 ;
V_66 -> V_70 . V_42 = V_16 -> V_31 ;
V_66 -> V_70 . V_71 = V_16 -> V_72 ;
if ( V_21 ) {
V_66 -> V_70 . V_73 = V_21 -> V_31 ;
V_66 -> V_70 . V_74 = V_21 -> V_72 ;
V_40 = 4 ;
type = V_75 ;
}
* V_67 = V_40 ;
return type ;
}
int F_33 ( struct V_16 * V_16 , struct V_66 * V_66 ,
int * V_67 , struct V_16 * V_21 )
{
const struct V_7 * V_8 = V_16 -> V_76 -> V_10 ;
if ( V_8 && V_8 -> V_77 )
return V_8 -> V_77 ( V_16 , V_66 -> V_78 , V_67 , V_21 ) ;
return F_32 ( V_16 , V_66 , V_67 , V_21 ) ;
}
int F_34 ( struct V_3 * V_3 , struct V_66 * V_66 , int * V_67 ,
int V_79 )
{
int error ;
struct V_3 * V_80 = NULL ;
struct V_16 * V_16 = V_3 -> V_17 , * V_21 = NULL ;
if ( V_79 && ! F_27 ( V_16 -> V_57 ) ) {
V_80 = F_10 ( V_3 ) ;
V_21 = V_80 -> V_17 ;
}
error = F_33 ( V_16 , V_66 , V_67 , V_21 ) ;
F_8 ( V_80 ) ;
return error ;
}
struct V_3 * F_35 ( struct V_1 * V_2 , struct V_66 * V_66 ,
int V_81 , int V_82 ,
int (* F_3)( void * , struct V_3 * ) , void * V_14 )
{
const struct V_7 * V_8 = V_2 -> V_28 -> V_10 ;
struct V_3 * V_13 , * V_83 ;
char V_23 [ V_47 + 1 ] ;
int V_25 ;
if ( ! V_8 || ! V_8 -> V_84 )
return F_15 ( - V_35 ) ;
V_13 = V_8 -> V_84 ( V_2 -> V_28 , V_66 , V_81 , V_82 ) ;
if ( ! V_13 )
V_13 = F_15 ( - V_35 ) ;
if ( F_18 ( V_13 ) )
return V_13 ;
if ( F_36 ( V_13 ) ) {
if ( V_13 -> V_19 & V_20 ) {
V_25 = F_22 ( V_2 , V_13 , V_23 ) ;
if ( V_25 )
goto V_85;
}
if ( ! F_3 ( V_14 , V_13 ) ) {
V_25 = - V_26 ;
goto V_85;
}
return V_13 ;
} else {
struct V_3 * V_36 , * V_86 ;
V_83 = F_2 ( V_13 , F_3 , V_14 ) ;
if ( V_83 )
return V_83 ;
V_25 = - V_35 ;
if ( ! V_8 -> V_87 )
goto V_85;
V_36 = V_8 -> V_87 ( V_2 -> V_28 , V_66 ,
V_81 , V_82 ) ;
if ( ! V_36 )
goto V_85;
V_25 = F_20 ( V_36 ) ;
if ( F_18 ( V_36 ) )
goto V_85;
V_25 = F_22 ( V_2 , V_36 , V_23 ) ;
if ( V_25 ) {
F_8 ( V_36 ) ;
goto V_85;
}
V_25 = F_1 ( V_2 , V_36 , V_23 , V_13 ) ;
if ( ! V_25 ) {
F_16 ( & V_36 -> V_17 -> V_27 ) ;
V_86 = F_21 ( V_23 , V_36 ,
strlen ( V_23 ) ) ;
F_17 ( & V_36 -> V_17 -> V_27 ) ;
if ( ! F_18 ( V_86 ) ) {
if ( V_86 -> V_17 ) {
F_8 ( V_13 ) ;
V_13 = V_86 ;
} else
F_8 ( V_86 ) ;
}
}
F_8 ( V_36 ) ;
V_83 = F_2 ( V_13 , F_3 , V_14 ) ;
if ( ! V_83 ) {
V_25 = - V_26 ;
goto V_85;
}
return V_83 ;
}
V_85:
F_8 ( V_13 ) ;
return F_15 ( V_25 ) ;
}
