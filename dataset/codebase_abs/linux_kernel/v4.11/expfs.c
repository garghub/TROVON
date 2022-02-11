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
F_16 ( V_3 -> V_17 ) ;
if ( V_2 -> V_27 -> V_10 -> V_28 )
V_21 = V_2 -> V_27 -> V_10 -> V_28 ( V_3 ) ;
F_17 ( V_3 -> V_17 ) ;
if ( F_18 ( V_21 ) ) {
F_19 ( L_1 ,
V_29 , V_3 -> V_17 -> V_30 , F_20 ( V_21 ) ) ;
return V_21 ;
}
F_19 ( L_2 , V_29 ,
V_3 -> V_17 -> V_30 , V_21 -> V_17 -> V_30 ) ;
V_25 = F_1 ( V_2 , V_21 , V_23 , V_3 ) ;
if ( V_25 == - V_31 )
goto V_32;
if ( V_25 )
goto V_33;
F_19 ( L_3 , V_29 , V_23 ) ;
V_24 = F_21 ( V_23 , V_21 , strlen ( V_23 ) ) ;
if ( F_18 ( V_24 ) ) {
F_19 ( L_4 , V_29 , F_20 ( V_24 ) ) ;
goto V_33;
}
if ( V_24 != V_3 ) {
F_8 ( V_24 ) ;
goto V_32;
}
F_8 ( V_24 ) ;
if ( F_11 ( V_3 ) ) {
V_25 = - V_34 ;
goto V_33;
}
return V_21 ;
V_33:
F_8 ( V_21 ) ;
return F_15 ( V_25 ) ;
V_32:
F_8 ( V_21 ) ;
if ( ! F_9 ( V_3 ) )
return F_15 ( - V_34 ) ;
return NULL ;
}
static int
F_22 ( struct V_1 * V_2 , struct V_3 * V_35 , char * V_23 )
{
struct V_3 * V_3 , * V_21 ;
V_3 = F_6 ( V_35 ) ;
while ( V_3 -> V_19 & V_20 ) {
F_23 ( V_3 == V_2 -> V_27 -> V_36 ) ;
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
F_12 ( V_35 ) ;
return 0 ;
}
static int F_24 ( struct V_37 * V_38 , const char * V_5 , int V_39 ,
T_1 V_40 , T_2 V_41 , unsigned int V_42 )
{
struct V_43 * V_44 =
F_25 ( V_38 , struct V_43 , V_38 ) ;
int V_13 = 0 ;
V_44 -> V_45 ++ ;
if ( V_44 -> V_41 == V_41 && V_39 <= V_46 ) {
memcpy ( V_44 -> V_5 , V_5 , V_39 ) ;
V_44 -> V_5 [ V_39 ] = '\0' ;
V_44 -> V_47 = 1 ;
V_13 = - 1 ;
}
return V_13 ;
}
static int V_12 ( const struct V_11 * V_11 , char * V_5 , struct V_3 * V_6 )
{
const struct V_48 * V_48 = F_26 () ;
struct V_16 * V_4 = V_11 -> V_3 -> V_17 ;
int error ;
struct V_49 * V_49 ;
struct V_50 V_51 ;
struct V_11 V_52 = {
. V_2 = V_11 -> V_2 ,
. V_3 = V_6 ,
} ;
struct V_43 V_53 = {
. V_38 . V_54 = F_24 ,
. V_5 = V_5 ,
} ;
error = - V_55 ;
if ( ! V_4 || ! F_27 ( V_4 -> V_56 ) )
goto V_57;
error = - V_58 ;
if ( ! V_4 -> V_59 )
goto V_57;
error = F_28 ( & V_52 , & V_51 ,
V_60 , V_61 ) ;
if ( error )
return error ;
V_53 . V_41 = V_51 . V_41 ;
V_49 = F_29 ( V_11 , V_62 , V_48 ) ;
error = F_20 ( V_49 ) ;
if ( F_18 ( V_49 ) )
goto V_57;
error = - V_58 ;
if ( ! V_49 -> V_63 -> V_64 && ! V_49 -> V_63 -> V_65 )
goto V_66;
V_53 . V_45 = 0 ;
while ( 1 ) {
int V_67 = V_53 . V_45 ;
error = F_30 ( V_49 , & V_53 . V_38 ) ;
if ( V_53 . V_47 ) {
error = 0 ;
break;
}
if ( error < 0 )
break;
error = - V_31 ;
if ( V_67 == V_53 . V_45 )
break;
}
V_66:
F_31 ( V_49 ) ;
V_57:
return error ;
}
static int F_32 ( struct V_16 * V_16 , struct V_68 * V_68 ,
int * V_69 , struct V_16 * V_21 )
{
int V_39 = * V_69 ;
int type = V_70 ;
if ( V_21 && ( V_39 < 4 ) ) {
* V_69 = 4 ;
return V_71 ;
} else if ( V_39 < 2 ) {
* V_69 = 2 ;
return V_71 ;
}
V_39 = 2 ;
V_68 -> V_72 . V_41 = V_16 -> V_30 ;
V_68 -> V_72 . V_73 = V_16 -> V_74 ;
if ( V_21 ) {
V_68 -> V_72 . V_75 = V_21 -> V_30 ;
V_68 -> V_72 . V_76 = V_21 -> V_74 ;
V_39 = 4 ;
type = V_77 ;
}
* V_69 = V_39 ;
return type ;
}
int F_33 ( struct V_16 * V_16 , struct V_68 * V_68 ,
int * V_69 , struct V_16 * V_21 )
{
const struct V_7 * V_8 = V_16 -> V_78 -> V_10 ;
if ( V_8 && V_8 -> V_79 )
return V_8 -> V_79 ( V_16 , V_68 -> V_80 , V_69 , V_21 ) ;
return F_32 ( V_16 , V_68 , V_69 , V_21 ) ;
}
int F_34 ( struct V_3 * V_3 , struct V_68 * V_68 , int * V_69 ,
int V_81 )
{
int error ;
struct V_3 * V_82 = NULL ;
struct V_16 * V_16 = V_3 -> V_17 , * V_21 = NULL ;
if ( V_81 && ! F_27 ( V_16 -> V_56 ) ) {
V_82 = F_10 ( V_3 ) ;
V_21 = V_82 -> V_17 ;
}
error = F_33 ( V_16 , V_68 , V_69 , V_21 ) ;
F_8 ( V_82 ) ;
return error ;
}
struct V_3 * F_35 ( struct V_1 * V_2 , struct V_68 * V_68 ,
int V_83 , int V_84 ,
int (* F_3)( void * , struct V_3 * ) , void * V_14 )
{
const struct V_7 * V_8 = V_2 -> V_27 -> V_10 ;
struct V_3 * V_13 , * V_85 ;
char V_23 [ V_46 + 1 ] ;
int V_25 ;
if ( ! V_8 || ! V_8 -> V_86 )
return F_15 ( - V_34 ) ;
V_13 = V_8 -> V_86 ( V_2 -> V_27 , V_68 , V_83 , V_84 ) ;
if ( F_20 ( V_13 ) == - V_87 )
return F_36 ( V_13 ) ;
if ( F_37 ( V_13 ) )
return F_15 ( - V_34 ) ;
if ( F_38 ( V_13 ) ) {
if ( V_13 -> V_19 & V_20 ) {
V_25 = F_22 ( V_2 , V_13 , V_23 ) ;
if ( V_25 )
goto V_88;
}
if ( ! F_3 ( V_14 , V_13 ) ) {
V_25 = - V_26 ;
goto V_88;
}
return V_13 ;
} else {
struct V_3 * V_35 , * V_89 ;
V_85 = F_2 ( V_13 , F_3 , V_14 ) ;
if ( V_85 )
return V_85 ;
V_25 = - V_34 ;
if ( ! V_8 -> V_90 )
goto V_88;
V_35 = V_8 -> V_90 ( V_2 -> V_27 , V_68 ,
V_83 , V_84 ) ;
if ( ! V_35 )
goto V_88;
V_25 = F_20 ( V_35 ) ;
if ( F_18 ( V_35 ) )
goto V_88;
V_25 = F_22 ( V_2 , V_35 , V_23 ) ;
if ( V_25 ) {
F_8 ( V_35 ) ;
goto V_88;
}
V_25 = F_1 ( V_2 , V_35 , V_23 , V_13 ) ;
if ( ! V_25 ) {
F_16 ( V_35 -> V_17 ) ;
V_89 = F_39 ( V_23 , V_35 ,
strlen ( V_23 ) ) ;
F_17 ( V_35 -> V_17 ) ;
if ( ! F_18 ( V_89 ) ) {
if ( V_89 -> V_17 ) {
F_8 ( V_13 ) ;
V_13 = V_89 ;
} else
F_8 ( V_89 ) ;
}
}
F_8 ( V_35 ) ;
V_85 = F_2 ( V_13 , F_3 , V_14 ) ;
if ( ! V_85 ) {
V_25 = - V_26 ;
goto V_88;
}
return V_85 ;
}
V_88:
F_8 ( V_13 ) ;
if ( V_25 != - V_87 )
V_25 = - V_34 ;
return F_15 ( V_25 ) ;
}
