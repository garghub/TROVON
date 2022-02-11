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
F_5 (dentry, &inode->i_dentry, d_alias) {
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
static struct V_3 *
F_9 ( struct V_3 * V_3 )
{
F_6 ( V_3 ) ;
while ( ! F_10 ( V_3 ) ) {
struct V_3 * V_19 = F_11 ( V_3 ) ;
if ( ! ( V_19 -> V_20 & V_21 ) ) {
F_8 ( V_19 ) ;
break;
}
F_8 ( V_3 ) ;
V_3 = V_19 ;
}
return V_3 ;
}
static int
F_12 ( struct V_1 * V_2 , struct V_3 * V_22 , char * V_23 )
{
int V_24 = 0 ;
int V_25 = - V_26 ;
while ( V_22 -> V_20 & V_21 && V_24 ++ < 10 ) {
struct V_3 * V_27 = F_9 ( V_22 ) ;
if ( ! F_10 ( V_27 ) ) {
F_4 ( & V_27 -> V_28 ) ;
V_27 -> V_20 &= ~ V_21 ;
F_7 ( & V_27 -> V_28 ) ;
V_24 = 0 ;
} else if ( V_27 == V_2 -> V_29 -> V_30 ) {
F_13 ( V_31 L_1 ) ;
F_4 ( & V_27 -> V_28 ) ;
V_27 -> V_20 &= ~ V_21 ;
F_7 ( & V_27 -> V_28 ) ;
V_24 = 0 ;
} else {
struct V_3 * V_32 = F_14 ( - V_33 ) ;
struct V_3 * V_34 ;
F_15 ( & V_27 -> V_17 -> V_35 ) ;
if ( V_2 -> V_29 -> V_10 -> V_36 )
V_32 = V_2 -> V_29 -> V_10 -> V_36 ( V_27 ) ;
F_16 ( & V_27 -> V_17 -> V_35 ) ;
if ( F_17 ( V_32 ) ) {
V_25 = F_18 ( V_32 ) ;
F_19 ( L_2 ,
V_37 , V_27 -> V_17 -> V_38 , V_25 ) ;
F_8 ( V_27 ) ;
break;
}
F_19 ( L_3 , V_37 ,
V_27 -> V_17 -> V_38 , V_32 -> V_17 -> V_38 ) ;
V_25 = F_1 ( V_2 , V_32 , V_23 , V_27 ) ;
if ( V_25 ) {
F_8 ( V_32 ) ;
F_8 ( V_27 ) ;
if ( V_25 == - V_39 )
continue;
break;
}
F_19 ( L_4 , V_37 , V_23 ) ;
F_15 ( & V_32 -> V_17 -> V_35 ) ;
V_34 = F_20 ( V_23 , V_32 , strlen ( V_23 ) ) ;
F_16 ( & V_32 -> V_17 -> V_35 ) ;
if ( F_17 ( V_34 ) ) {
V_25 = F_18 ( V_34 ) ;
F_19 ( L_5 ,
V_37 , V_25 ) ;
F_8 ( V_32 ) ;
F_8 ( V_27 ) ;
break;
}
if ( V_34 == V_27 )
V_24 = 0 ;
else
F_13 ( L_6 , V_37 ) ;
F_8 ( V_34 ) ;
F_8 ( V_32 ) ;
if ( F_10 ( V_27 ) ) {
F_8 ( V_27 ) ;
break;
}
}
F_8 ( V_27 ) ;
}
if ( V_22 -> V_20 & V_21 ) {
if ( ! V_25 )
V_25 = - V_26 ;
return V_25 ;
}
return 0 ;
}
static int F_21 ( void * V_40 , const char * V_5 , int V_41 ,
T_1 V_42 , T_2 V_43 , unsigned int V_44 )
{
struct V_45 * V_46 = V_40 ;
int V_13 = 0 ;
V_46 -> V_47 ++ ;
if ( V_46 -> V_43 == V_43 ) {
memcpy ( V_46 -> V_5 , V_5 , V_41 ) ;
V_46 -> V_5 [ V_41 ] = '\0' ;
V_46 -> V_48 = 1 ;
V_13 = - 1 ;
}
return V_13 ;
}
static int V_12 ( const struct V_11 * V_11 , char * V_5 , struct V_3 * V_6 )
{
const struct V_49 * V_49 = F_22 () ;
struct V_16 * V_4 = V_11 -> V_3 -> V_17 ;
int error ;
struct V_50 * V_50 ;
struct V_45 V_51 ;
error = - V_52 ;
if ( ! V_4 || ! F_23 ( V_4 -> V_53 ) )
goto V_54;
error = - V_55 ;
if ( ! V_4 -> V_56 )
goto V_54;
V_50 = F_24 ( V_11 , V_57 , V_49 ) ;
error = F_18 ( V_50 ) ;
if ( F_17 ( V_50 ) )
goto V_54;
error = - V_55 ;
if ( ! V_50 -> V_58 -> V_59 )
goto V_60;
V_51 . V_5 = V_5 ;
V_51 . V_43 = V_6 -> V_17 -> V_38 ;
V_51 . V_48 = 0 ;
V_51 . V_47 = 0 ;
while ( 1 ) {
int V_61 = V_51 . V_47 ;
error = F_25 ( V_50 , F_21 , & V_51 ) ;
if ( V_51 . V_48 ) {
error = 0 ;
break;
}
if ( error < 0 )
break;
error = - V_39 ;
if ( V_61 == V_51 . V_47 )
break;
}
V_60:
F_26 ( V_50 ) ;
V_54:
return error ;
}
static int F_27 ( struct V_16 * V_16 , struct V_62 * V_62 ,
int * V_63 , struct V_16 * V_19 )
{
int V_41 = * V_63 ;
int type = V_64 ;
if ( V_19 && ( V_41 < 4 ) ) {
* V_63 = 4 ;
return V_65 ;
} else if ( V_41 < 2 ) {
* V_63 = 2 ;
return V_65 ;
}
V_41 = 2 ;
V_62 -> V_66 . V_43 = V_16 -> V_38 ;
V_62 -> V_66 . V_67 = V_16 -> V_68 ;
if ( V_19 ) {
V_62 -> V_66 . V_69 = V_19 -> V_38 ;
V_62 -> V_66 . V_70 = V_19 -> V_68 ;
V_41 = 4 ;
type = V_71 ;
}
* V_63 = V_41 ;
return type ;
}
int F_28 ( struct V_16 * V_16 , struct V_62 * V_62 ,
int * V_63 , struct V_16 * V_19 )
{
const struct V_7 * V_8 = V_16 -> V_72 -> V_10 ;
if ( V_8 && V_8 -> V_73 )
return V_8 -> V_73 ( V_16 , V_62 -> V_74 , V_63 , V_19 ) ;
return F_27 ( V_16 , V_62 , V_63 , V_19 ) ;
}
int F_29 ( struct V_3 * V_3 , struct V_62 * V_62 , int * V_63 ,
int V_75 )
{
int error ;
struct V_3 * V_76 = NULL ;
struct V_16 * V_16 = V_3 -> V_17 , * V_19 = NULL ;
if ( V_75 && ! F_23 ( V_16 -> V_53 ) ) {
V_76 = F_11 ( V_3 ) ;
V_19 = V_76 -> V_17 ;
}
error = F_28 ( V_16 , V_62 , V_63 , V_19 ) ;
F_8 ( V_76 ) ;
return error ;
}
struct V_3 * F_30 ( struct V_1 * V_2 , struct V_62 * V_62 ,
int V_77 , int V_78 ,
int (* F_3)( void * , struct V_3 * ) , void * V_14 )
{
const struct V_7 * V_8 = V_2 -> V_29 -> V_10 ;
struct V_3 * V_13 , * V_79 ;
char V_23 [ V_80 + 1 ] ;
int V_25 ;
if ( ! V_8 || ! V_8 -> V_81 )
return F_14 ( - V_26 ) ;
V_13 = V_8 -> V_81 ( V_2 -> V_29 , V_62 , V_77 , V_78 ) ;
if ( ! V_13 )
V_13 = F_14 ( - V_26 ) ;
if ( F_17 ( V_13 ) )
return V_13 ;
if ( F_23 ( V_13 -> V_17 -> V_53 ) ) {
if ( V_13 -> V_20 & V_21 ) {
V_25 = F_12 ( V_2 , V_13 , V_23 ) ;
if ( V_25 )
goto V_82;
}
if ( ! F_3 ( V_14 , V_13 ) ) {
V_25 = - V_33 ;
goto V_82;
}
return V_13 ;
} else {
struct V_3 * V_22 , * V_83 ;
V_79 = F_2 ( V_13 , F_3 , V_14 ) ;
if ( V_79 )
return V_79 ;
V_25 = - V_26 ;
if ( ! V_8 -> V_84 )
goto V_82;
V_22 = V_8 -> V_84 ( V_2 -> V_29 , V_62 ,
V_77 , V_78 ) ;
if ( ! V_22 )
goto V_82;
V_25 = F_18 ( V_22 ) ;
if ( F_17 ( V_22 ) )
goto V_82;
V_25 = F_12 ( V_2 , V_22 , V_23 ) ;
if ( V_25 ) {
F_8 ( V_22 ) ;
goto V_82;
}
V_25 = F_1 ( V_2 , V_22 , V_23 , V_13 ) ;
if ( ! V_25 ) {
F_15 ( & V_22 -> V_17 -> V_35 ) ;
V_83 = F_20 ( V_23 , V_22 ,
strlen ( V_23 ) ) ;
F_16 ( & V_22 -> V_17 -> V_35 ) ;
if ( ! F_17 ( V_83 ) ) {
if ( V_83 -> V_17 ) {
F_8 ( V_13 ) ;
V_13 = V_83 ;
} else
F_8 ( V_83 ) ;
}
}
F_8 ( V_22 ) ;
V_79 = F_2 ( V_13 , F_3 , V_14 ) ;
if ( ! V_79 ) {
V_25 = - V_33 ;
goto V_82;
}
return V_79 ;
}
V_82:
F_8 ( V_13 ) ;
return F_14 ( V_25 ) ;
}
