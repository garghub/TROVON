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
struct V_17 * V_18 ;
if ( F_3 ( V_14 , V_13 ) )
return V_13 ;
V_16 = V_13 -> V_19 ;
F_4 ( & V_16 -> V_20 ) ;
F_5 (dentry, p, &inode->i_dentry, d_alias) {
F_6 ( V_3 ) ;
F_7 ( & V_16 -> V_20 ) ;
if ( V_15 )
F_8 ( V_15 ) ;
if ( V_3 != V_13 && F_3 ( V_14 , V_3 ) ) {
F_8 ( V_13 ) ;
return V_3 ;
}
F_4 ( & V_16 -> V_20 ) ;
V_15 = V_3 ;
}
F_7 ( & V_16 -> V_20 ) ;
if ( V_15 )
F_8 ( V_15 ) ;
return NULL ;
}
static struct V_3 *
F_9 ( struct V_3 * V_3 )
{
F_6 ( V_3 ) ;
while ( ! F_10 ( V_3 ) ) {
struct V_3 * V_21 = F_11 ( V_3 ) ;
if ( ! ( V_21 -> V_22 & V_23 ) ) {
F_8 ( V_21 ) ;
break;
}
F_8 ( V_3 ) ;
V_3 = V_21 ;
}
return V_3 ;
}
static int
F_12 ( struct V_1 * V_2 , struct V_3 * V_24 , char * V_25 )
{
int V_26 = 0 ;
int V_27 = - V_28 ;
while ( V_24 -> V_22 & V_23 && V_26 ++ < 10 ) {
struct V_3 * V_29 = F_9 ( V_24 ) ;
if ( ! F_10 ( V_29 ) ) {
F_4 ( & V_29 -> V_30 ) ;
V_29 -> V_22 &= ~ V_23 ;
F_7 ( & V_29 -> V_30 ) ;
V_26 = 0 ;
} else if ( V_29 == V_2 -> V_31 -> V_32 ) {
F_13 ( V_33 L_1 ) ;
F_4 ( & V_29 -> V_30 ) ;
V_29 -> V_22 &= ~ V_23 ;
F_7 ( & V_29 -> V_30 ) ;
V_26 = 0 ;
} else {
struct V_3 * V_34 = F_14 ( - V_35 ) ;
struct V_3 * V_36 ;
F_15 ( & V_29 -> V_19 -> V_37 ) ;
if ( V_2 -> V_31 -> V_10 -> V_38 )
V_34 = V_2 -> V_31 -> V_10 -> V_38 ( V_29 ) ;
F_16 ( & V_29 -> V_19 -> V_37 ) ;
if ( F_17 ( V_34 ) ) {
V_27 = F_18 ( V_34 ) ;
F_19 ( L_2 ,
V_39 , V_29 -> V_19 -> V_40 , V_27 ) ;
F_8 ( V_29 ) ;
break;
}
F_19 ( L_3 , V_39 ,
V_29 -> V_19 -> V_40 , V_34 -> V_19 -> V_40 ) ;
V_27 = F_1 ( V_2 , V_34 , V_25 , V_29 ) ;
if ( V_27 ) {
F_8 ( V_34 ) ;
F_8 ( V_29 ) ;
if ( V_27 == - V_41 )
continue;
break;
}
F_19 ( L_4 , V_39 , V_25 ) ;
F_15 ( & V_34 -> V_19 -> V_37 ) ;
V_36 = F_20 ( V_25 , V_34 , strlen ( V_25 ) ) ;
F_16 ( & V_34 -> V_19 -> V_37 ) ;
if ( F_17 ( V_36 ) ) {
V_27 = F_18 ( V_36 ) ;
F_19 ( L_5 ,
V_39 , V_27 ) ;
F_8 ( V_34 ) ;
F_8 ( V_29 ) ;
break;
}
if ( V_36 == V_29 )
V_26 = 0 ;
else
F_13 ( L_6 , V_39 ) ;
F_8 ( V_36 ) ;
F_8 ( V_34 ) ;
if ( F_10 ( V_29 ) ) {
F_8 ( V_29 ) ;
break;
}
}
F_8 ( V_29 ) ;
}
if ( V_24 -> V_22 & V_23 ) {
if ( ! V_27 )
V_27 = - V_28 ;
return V_27 ;
}
return 0 ;
}
static int F_21 ( void * V_42 , const char * V_5 , int V_43 ,
T_1 V_44 , T_2 V_45 , unsigned int V_46 )
{
struct V_47 * V_48 = V_42 ;
int V_13 = 0 ;
V_48 -> V_49 ++ ;
if ( V_48 -> V_45 == V_45 ) {
memcpy ( V_48 -> V_5 , V_5 , V_43 ) ;
V_48 -> V_5 [ V_43 ] = '\0' ;
V_48 -> V_50 = 1 ;
V_13 = - 1 ;
}
return V_13 ;
}
static int V_12 ( const struct V_11 * V_11 , char * V_5 , struct V_3 * V_6 )
{
const struct V_51 * V_51 = F_22 () ;
struct V_16 * V_4 = V_11 -> V_3 -> V_19 ;
int error ;
struct V_52 * V_52 ;
struct V_47 V_53 ;
error = - V_54 ;
if ( ! V_4 || ! F_23 ( V_4 -> V_55 ) )
goto V_56;
error = - V_57 ;
if ( ! V_4 -> V_58 )
goto V_56;
V_52 = F_24 ( V_11 , V_59 , V_51 ) ;
error = F_18 ( V_52 ) ;
if ( F_17 ( V_52 ) )
goto V_56;
error = - V_57 ;
if ( ! V_52 -> V_60 -> V_61 )
goto V_62;
V_53 . V_5 = V_5 ;
V_53 . V_45 = V_6 -> V_19 -> V_40 ;
V_53 . V_50 = 0 ;
V_53 . V_49 = 0 ;
while ( 1 ) {
int V_63 = V_53 . V_49 ;
error = F_25 ( V_52 , F_21 , & V_53 ) ;
if ( V_53 . V_50 ) {
error = 0 ;
break;
}
if ( error < 0 )
break;
error = - V_41 ;
if ( V_63 == V_53 . V_49 )
break;
}
V_62:
F_26 ( V_52 ) ;
V_56:
return error ;
}
static int F_27 ( struct V_16 * V_16 , struct V_64 * V_64 ,
int * V_65 , struct V_16 * V_21 )
{
int V_43 = * V_65 ;
int type = V_66 ;
if ( V_21 && ( V_43 < 4 ) ) {
* V_65 = 4 ;
return V_67 ;
} else if ( V_43 < 2 ) {
* V_65 = 2 ;
return V_67 ;
}
V_43 = 2 ;
V_64 -> V_68 . V_45 = V_16 -> V_40 ;
V_64 -> V_68 . V_69 = V_16 -> V_70 ;
if ( V_21 ) {
V_64 -> V_68 . V_71 = V_21 -> V_40 ;
V_64 -> V_68 . V_72 = V_21 -> V_70 ;
V_43 = 4 ;
type = V_73 ;
}
* V_65 = V_43 ;
return type ;
}
int F_28 ( struct V_16 * V_16 , struct V_64 * V_64 ,
int * V_65 , struct V_16 * V_21 )
{
const struct V_7 * V_8 = V_16 -> V_74 -> V_10 ;
if ( V_8 && V_8 -> V_75 )
return V_8 -> V_75 ( V_16 , V_64 -> V_76 , V_65 , V_21 ) ;
return F_27 ( V_16 , V_64 , V_65 , V_21 ) ;
}
int F_29 ( struct V_3 * V_3 , struct V_64 * V_64 , int * V_65 ,
int V_77 )
{
int error ;
struct V_3 * V_18 = NULL ;
struct V_16 * V_16 = V_3 -> V_19 , * V_21 = NULL ;
if ( V_77 && ! F_23 ( V_16 -> V_55 ) ) {
V_18 = F_11 ( V_3 ) ;
V_21 = V_18 -> V_19 ;
}
error = F_28 ( V_16 , V_64 , V_65 , V_21 ) ;
F_8 ( V_18 ) ;
return error ;
}
struct V_3 * F_30 ( struct V_1 * V_2 , struct V_64 * V_64 ,
int V_78 , int V_79 ,
int (* F_3)( void * , struct V_3 * ) , void * V_14 )
{
const struct V_7 * V_8 = V_2 -> V_31 -> V_10 ;
struct V_3 * V_13 , * V_80 ;
char V_25 [ V_81 + 1 ] ;
int V_27 ;
if ( ! V_8 || ! V_8 -> V_82 )
return F_14 ( - V_28 ) ;
V_13 = V_8 -> V_82 ( V_2 -> V_31 , V_64 , V_78 , V_79 ) ;
if ( ! V_13 )
V_13 = F_14 ( - V_28 ) ;
if ( F_17 ( V_13 ) )
return V_13 ;
if ( F_23 ( V_13 -> V_19 -> V_55 ) ) {
if ( V_13 -> V_22 & V_23 ) {
V_27 = F_12 ( V_2 , V_13 , V_25 ) ;
if ( V_27 )
goto V_83;
}
if ( ! F_3 ( V_14 , V_13 ) ) {
V_27 = - V_35 ;
goto V_83;
}
return V_13 ;
} else {
struct V_3 * V_24 , * V_84 ;
V_80 = F_2 ( V_13 , F_3 , V_14 ) ;
if ( V_80 )
return V_80 ;
V_27 = - V_28 ;
if ( ! V_8 -> V_85 )
goto V_83;
V_24 = V_8 -> V_85 ( V_2 -> V_31 , V_64 ,
V_78 , V_79 ) ;
if ( ! V_24 )
goto V_83;
V_27 = F_18 ( V_24 ) ;
if ( F_17 ( V_24 ) )
goto V_83;
V_27 = F_12 ( V_2 , V_24 , V_25 ) ;
if ( V_27 ) {
F_8 ( V_24 ) ;
goto V_83;
}
V_27 = F_1 ( V_2 , V_24 , V_25 , V_13 ) ;
if ( ! V_27 ) {
F_15 ( & V_24 -> V_19 -> V_37 ) ;
V_84 = F_20 ( V_25 , V_24 ,
strlen ( V_25 ) ) ;
F_16 ( & V_24 -> V_19 -> V_37 ) ;
if ( ! F_17 ( V_84 ) ) {
if ( V_84 -> V_19 ) {
F_8 ( V_13 ) ;
V_13 = V_84 ;
} else
F_8 ( V_84 ) ;
}
}
F_8 ( V_24 ) ;
V_80 = F_2 ( V_13 , F_3 , V_14 ) ;
if ( ! V_80 ) {
V_27 = - V_35 ;
goto V_83;
}
return V_80 ;
}
V_83:
F_8 ( V_13 ) ;
return F_14 ( V_27 ) ;
}
