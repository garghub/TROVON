static int F_1 ( struct V_1 * V_2 , struct V_3 * V_4 ,
char * V_5 , struct V_3 * V_6 )
{
const struct V_7 * V_8 = V_4 -> V_9 -> V_10 ;
if ( V_8 -> V_11 )
return V_8 -> V_11 ( V_4 , V_5 , V_6 ) ;
else
return V_11 ( V_2 , V_4 , V_5 , V_6 ) ;
}
static struct V_3 *
F_2 ( struct V_3 * V_12 ,
int (* F_3)( void * V_13 , struct V_3 * V_3 ) ,
void * V_13 )
{
struct V_3 * V_3 , * V_14 = NULL ;
struct V_15 * V_15 ;
if ( F_3 ( V_13 , V_12 ) )
return V_12 ;
V_15 = V_12 -> V_16 ;
F_4 ( & V_15 -> V_17 ) ;
F_5 (dentry, &inode->i_dentry, d_alias) {
F_6 ( V_3 ) ;
F_7 ( & V_15 -> V_17 ) ;
if ( V_14 )
F_8 ( V_14 ) ;
if ( V_3 != V_12 && F_3 ( V_13 , V_3 ) ) {
F_8 ( V_12 ) ;
return V_3 ;
}
F_4 ( & V_15 -> V_17 ) ;
V_14 = V_3 ;
}
F_7 ( & V_15 -> V_17 ) ;
if ( V_14 )
F_8 ( V_14 ) ;
return NULL ;
}
static struct V_3 *
F_9 ( struct V_3 * V_3 )
{
F_6 ( V_3 ) ;
while ( ! F_10 ( V_3 ) ) {
struct V_3 * V_18 = F_11 ( V_3 ) ;
if ( ! ( V_18 -> V_19 & V_20 ) ) {
F_8 ( V_18 ) ;
break;
}
F_8 ( V_3 ) ;
V_3 = V_18 ;
}
return V_3 ;
}
static int
F_12 ( struct V_1 * V_2 , struct V_3 * V_21 , char * V_22 )
{
int V_23 = 0 ;
int V_24 = - V_25 ;
while ( V_21 -> V_19 & V_20 && V_23 ++ < 10 ) {
struct V_3 * V_26 = F_9 ( V_21 ) ;
if ( ! F_10 ( V_26 ) ) {
F_4 ( & V_26 -> V_27 ) ;
V_26 -> V_19 &= ~ V_20 ;
F_7 ( & V_26 -> V_27 ) ;
V_23 = 0 ;
} else if ( V_26 == V_2 -> V_28 -> V_29 ) {
F_13 ( V_30 L_1 ) ;
F_4 ( & V_26 -> V_27 ) ;
V_26 -> V_19 &= ~ V_20 ;
F_7 ( & V_26 -> V_27 ) ;
V_23 = 0 ;
} else {
struct V_3 * V_31 = F_14 ( - V_32 ) ;
struct V_3 * V_33 ;
F_15 ( & V_26 -> V_16 -> V_34 ) ;
if ( V_2 -> V_28 -> V_10 -> V_35 )
V_31 = V_2 -> V_28 -> V_10 -> V_35 ( V_26 ) ;
F_16 ( & V_26 -> V_16 -> V_34 ) ;
if ( F_17 ( V_31 ) ) {
V_24 = F_18 ( V_31 ) ;
F_19 ( L_2 ,
V_36 , V_26 -> V_16 -> V_37 , V_24 ) ;
F_8 ( V_26 ) ;
break;
}
F_19 ( L_3 , V_36 ,
V_26 -> V_16 -> V_37 , V_31 -> V_16 -> V_37 ) ;
V_24 = F_1 ( V_2 , V_31 , V_22 , V_26 ) ;
if ( V_24 ) {
F_8 ( V_31 ) ;
F_8 ( V_26 ) ;
if ( V_24 == - V_38 )
continue;
break;
}
F_19 ( L_4 , V_36 , V_22 ) ;
F_15 ( & V_31 -> V_16 -> V_34 ) ;
V_33 = F_20 ( V_22 , V_31 , strlen ( V_22 ) ) ;
F_16 ( & V_31 -> V_16 -> V_34 ) ;
if ( F_17 ( V_33 ) ) {
V_24 = F_18 ( V_33 ) ;
F_19 ( L_5 ,
V_36 , V_24 ) ;
F_8 ( V_31 ) ;
F_8 ( V_26 ) ;
break;
}
if ( V_33 == V_26 )
V_23 = 0 ;
else
F_13 ( L_6 , V_36 ) ;
F_8 ( V_33 ) ;
F_8 ( V_31 ) ;
if ( F_10 ( V_26 ) ) {
F_8 ( V_26 ) ;
break;
}
}
F_8 ( V_26 ) ;
}
if ( V_21 -> V_19 & V_20 ) {
if ( ! V_24 )
V_24 = - V_25 ;
return V_24 ;
}
return 0 ;
}
static int F_21 ( void * V_39 , const char * V_5 , int V_40 ,
T_1 V_41 , T_2 V_42 , unsigned int V_43 )
{
struct V_44 * V_45 = V_39 ;
int V_12 = 0 ;
V_45 -> V_46 ++ ;
if ( V_45 -> V_42 == V_42 ) {
memcpy ( V_45 -> V_5 , V_5 , V_40 ) ;
V_45 -> V_5 [ V_40 ] = '\0' ;
V_45 -> V_47 = 1 ;
V_12 = - 1 ;
}
return V_12 ;
}
static int V_11 ( struct V_1 * V_2 , struct V_3 * V_3 ,
char * V_5 , struct V_3 * V_6 )
{
const struct V_48 * V_48 = F_22 () ;
struct V_15 * V_4 = V_3 -> V_16 ;
int error ;
struct V_49 * V_49 ;
struct V_44 V_50 ;
error = - V_51 ;
if ( ! V_4 || ! F_23 ( V_4 -> V_52 ) )
goto V_53;
error = - V_54 ;
if ( ! V_4 -> V_55 )
goto V_53;
V_49 = F_24 ( F_6 ( V_3 ) , F_25 ( V_2 ) , V_56 , V_48 ) ;
error = F_18 ( V_49 ) ;
if ( F_17 ( V_49 ) )
goto V_53;
error = - V_54 ;
if ( ! V_49 -> V_57 -> V_58 )
goto V_59;
V_50 . V_5 = V_5 ;
V_50 . V_42 = V_6 -> V_16 -> V_37 ;
V_50 . V_47 = 0 ;
V_50 . V_46 = 0 ;
while ( 1 ) {
int V_60 = V_50 . V_46 ;
error = F_26 ( V_49 , F_21 , & V_50 ) ;
if ( V_50 . V_47 ) {
error = 0 ;
break;
}
if ( error < 0 )
break;
error = - V_38 ;
if ( V_60 == V_50 . V_46 )
break;
}
V_59:
F_27 ( V_49 ) ;
V_53:
return error ;
}
static int F_28 ( struct V_3 * V_3 , struct V_61 * V_61 ,
int * V_62 , int V_63 )
{
struct V_15 * V_15 = V_3 -> V_16 ;
int V_40 = * V_62 ;
int type = V_64 ;
if ( V_63 && ( V_40 < 4 ) ) {
* V_62 = 4 ;
return 255 ;
} else if ( V_40 < 2 ) {
* V_62 = 2 ;
return 255 ;
}
V_40 = 2 ;
V_61 -> V_65 . V_42 = V_15 -> V_37 ;
V_61 -> V_65 . V_66 = V_15 -> V_67 ;
if ( V_63 && ! F_23 ( V_15 -> V_52 ) ) {
struct V_15 * V_18 ;
F_4 ( & V_3 -> V_27 ) ;
V_18 = V_3 -> V_68 -> V_16 ;
V_61 -> V_65 . V_69 = V_18 -> V_37 ;
V_61 -> V_65 . V_70 = V_18 -> V_67 ;
F_7 ( & V_3 -> V_27 ) ;
V_40 = 4 ;
type = V_71 ;
}
* V_62 = V_40 ;
return type ;
}
int F_29 ( struct V_3 * V_3 , struct V_61 * V_61 , int * V_62 ,
int V_63 )
{
const struct V_7 * V_8 = V_3 -> V_9 -> V_10 ;
int error ;
if ( V_8 -> V_72 )
error = V_8 -> V_72 ( V_3 , V_61 -> V_73 , V_62 , V_63 ) ;
else
error = F_28 ( V_3 , V_61 , V_62 , V_63 ) ;
return error ;
}
struct V_3 * F_30 ( struct V_1 * V_2 , struct V_61 * V_61 ,
int V_74 , int V_75 ,
int (* F_3)( void * , struct V_3 * ) , void * V_13 )
{
const struct V_7 * V_8 = V_2 -> V_28 -> V_10 ;
struct V_3 * V_12 , * V_76 ;
char V_22 [ V_77 + 1 ] ;
int V_24 ;
if ( ! V_8 || ! V_8 -> V_78 )
return F_14 ( - V_25 ) ;
V_12 = V_8 -> V_78 ( V_2 -> V_28 , V_61 , V_74 , V_75 ) ;
if ( ! V_12 )
V_12 = F_14 ( - V_25 ) ;
if ( F_17 ( V_12 ) )
return V_12 ;
if ( F_23 ( V_12 -> V_16 -> V_52 ) ) {
if ( V_12 -> V_19 & V_20 ) {
V_24 = F_12 ( V_2 , V_12 , V_22 ) ;
if ( V_24 )
goto V_79;
}
if ( ! F_3 ( V_13 , V_12 ) ) {
V_24 = - V_32 ;
goto V_79;
}
return V_12 ;
} else {
struct V_3 * V_21 , * V_80 ;
V_76 = F_2 ( V_12 , F_3 , V_13 ) ;
if ( V_76 )
return V_76 ;
V_24 = - V_25 ;
if ( ! V_8 -> V_81 )
goto V_79;
V_21 = V_8 -> V_81 ( V_2 -> V_28 , V_61 ,
V_74 , V_75 ) ;
if ( ! V_21 )
goto V_79;
V_24 = F_18 ( V_21 ) ;
if ( F_17 ( V_21 ) )
goto V_79;
V_24 = F_12 ( V_2 , V_21 , V_22 ) ;
if ( V_24 ) {
F_8 ( V_21 ) ;
goto V_79;
}
V_24 = F_1 ( V_2 , V_21 , V_22 , V_12 ) ;
if ( ! V_24 ) {
F_15 ( & V_21 -> V_16 -> V_34 ) ;
V_80 = F_20 ( V_22 , V_21 ,
strlen ( V_22 ) ) ;
F_16 ( & V_21 -> V_16 -> V_34 ) ;
if ( ! F_17 ( V_80 ) ) {
if ( V_80 -> V_16 ) {
F_8 ( V_12 ) ;
V_12 = V_80 ;
} else
F_8 ( V_80 ) ;
}
}
F_8 ( V_21 ) ;
V_76 = F_2 ( V_12 , F_3 , V_13 ) ;
if ( ! V_76 ) {
V_24 = - V_32 ;
goto V_79;
}
return V_76 ;
}
V_79:
F_8 ( V_12 ) ;
return F_14 ( V_24 ) ;
}
