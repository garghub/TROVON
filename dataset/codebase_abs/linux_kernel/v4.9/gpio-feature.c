static struct V_1 * F_1 ( char * V_2 ,
char * V_3 ,
int * V_4 ,
int * V_5 )
{
struct V_1 * V_6 , * V_7 ;
const T_1 * V_8 ;
const char * V_9 ;
* V_4 = - 1 ;
V_6 = F_2 ( NULL , V_2 ) ;
if ( ! V_6 ) {
V_7 = F_2 ( NULL , L_1 ) ;
if ( ! V_7 )
return NULL ;
while ( ( V_6 = F_3 ( V_7 , V_6 ) ) ) {
V_9 = F_4 ( V_6 , L_2 , NULL ) ;
if ( ! V_9 )
continue;
if ( strcmp ( V_9 , V_2 ) == 0 )
break;
if ( V_3 && ( strcmp ( V_9 , V_3 ) == 0 ) )
break;
}
if ( ! V_6 )
return NULL ;
}
V_8 = F_4 ( V_6 , L_3 , NULL ) ;
if ( ! V_8 )
return NULL ;
* V_4 = * V_8 ;
if ( * V_4 < 0x50 )
* V_4 += 0x50 ;
V_8 = F_4 ( V_6 , L_4 , NULL ) ;
if ( ! V_8 )
* V_5 = 0 ;
else
* V_5 = * V_8 ;
return V_6 ;
}
static void F_5 ( struct V_1 * V_6 , int * V_10 )
{
if ( V_6 )
* V_10 = F_6 ( V_6 , 0 ) ;
else
* V_10 = 0 ;
}
static void F_7 ( struct V_11 * V_12 , int V_13 )
{
int V_14 ;
if ( F_8 ( ! V_12 ) ) return;
if ( V_15 < 0 )
return;
V_14 = F_9 ( V_16 , NULL ,
V_15 , 0 ) ;
V_14 = F_10 ( V_17 , V_14 , V_13 ) ;
F_9 ( V_18 , NULL ,
V_15 , V_14 ) ;
}
static void F_11 ( struct V_11 * V_12 )
{
int V_19 ;
if ( F_8 ( ! V_12 ) ) return;
V_19 = V_12 -> V_20 ;
F_12 ( V_12 , 0 ) ;
F_13 ( V_12 , 0 ) ;
F_14 ( V_12 , 0 ) ;
if ( V_21 . V_22 )
F_15 ( V_12 , 0 ) ;
V_12 -> V_20 = V_19 ;
}
static void F_16 ( struct V_11 * V_12 )
{
int V_23 ;
if ( F_8 ( ! V_12 ) ) return;
V_23 = V_12 -> V_20 ;
F_12 ( V_12 , ( V_23 >> 0 ) & 1 ) ;
F_13 ( V_12 , ( V_23 >> 1 ) & 1 ) ;
F_14 ( V_12 , ( V_23 >> 2 ) & 1 ) ;
if ( V_21 . V_22 )
F_15 ( V_12 , ( V_23 >> 3 ) & 1 ) ;
}
static void F_17 ( struct V_24 * V_25 )
{
struct V_26 * V_27 =
F_18 ( V_25 , struct V_26 , V_25 . V_25 ) ;
F_19 ( & V_27 -> V_28 ) ;
if ( V_27 -> V_29 )
V_27 -> V_29 ( V_27 -> V_30 ) ;
F_20 ( & V_27 -> V_28 ) ;
}
static void F_21 ( int V_7 )
{
int V_14 ;
if ( V_7 == - 1 )
return;
V_14 = F_9 ( V_16 , NULL , V_7 , 0 ) ;
V_14 |= 0x80 ;
F_9 ( V_18 , NULL , V_7 , V_14 ) ;
}
static void F_22 ( struct V_11 * V_12 )
{
F_1 ( L_5 , NULL ,
& V_31 ,
& V_32 ) ;
F_1 ( L_6 , NULL ,
& V_33 ,
& V_34 ) ;
F_1 ( L_7 , NULL ,
& V_35 ,
& V_36 ) ;
F_1 ( L_8 , L_9 ,
& V_15 ,
& V_37 ) ;
if ( F_1 ( L_10 , NULL ,
& V_38 ,
& V_39 ) ) {
V_21 . V_22 = F_15 ;
V_21 . V_40 = V_41 ;
}
V_42 = F_1 ( L_11 , NULL ,
& V_43 ,
& V_44 ) ;
V_45 = F_1 ( L_12 , L_13 ,
& V_46 ,
& V_47 ) ;
V_48 = F_1 ( L_14 , L_15 ,
& V_49 ,
& V_50 ) ;
F_21 ( V_43 ) ;
F_21 ( V_46 ) ;
F_21 ( V_49 ) ;
F_5 ( V_42 , & V_51 ) ;
F_5 ( V_45 , & V_52 ) ;
F_5 ( V_48 , & V_53 ) ;
F_11 ( V_12 ) ;
V_12 -> V_20 = 0 ;
F_23 ( & V_12 -> V_54 . V_25 , F_17 ) ;
F_23 ( & V_12 -> V_55 . V_25 , F_17 ) ;
F_23 ( & V_12 -> V_56 . V_25 , F_17 ) ;
F_24 ( & V_12 -> V_54 . V_28 ) ;
F_24 ( & V_12 -> V_55 . V_28 ) ;
F_24 ( & V_12 -> V_56 . V_28 ) ;
}
static void F_25 ( struct V_11 * V_12 )
{
F_11 ( V_12 ) ;
V_12 -> V_20 = 0 ;
if ( V_12 -> V_54 . V_29 )
F_26 ( V_51 , & V_12 -> V_54 ) ;
if ( V_12 -> V_55 . V_57 )
F_26 ( V_53 , & V_12 -> V_55 ) ;
if ( V_12 -> V_56 . V_57 )
F_26 ( V_52 , & V_12 -> V_56 ) ;
F_27 ( & V_12 -> V_54 . V_25 ) ;
F_27 ( & V_12 -> V_55 . V_25 ) ;
F_27 ( & V_12 -> V_56 . V_25 ) ;
F_28 ( & V_12 -> V_54 . V_28 ) ;
F_28 ( & V_12 -> V_55 . V_28 ) ;
F_28 ( & V_12 -> V_56 . V_28 ) ;
}
static T_2 F_29 ( int V_58 , void * V_30 )
{
struct V_26 * V_27 = V_30 ;
F_30 ( & V_27 -> V_25 , 0 ) ;
return V_59 ;
}
static int F_31 ( struct V_11 * V_12 ,
enum V_60 type ,
T_3 V_29 ,
void * V_30 )
{
struct V_26 * V_27 ;
T_3 V_61 ;
int V_62 ;
char * V_2 ;
int V_63 = - V_64 ;
switch ( type ) {
case V_65 :
V_27 = & V_12 -> V_54 ;
V_2 = L_11 ;
V_62 = V_51 ;
break;
case V_66 :
V_27 = & V_12 -> V_55 ;
V_2 = L_14 ;
V_62 = V_53 ;
break;
case V_67 :
V_27 = & V_12 -> V_56 ;
V_2 = L_12 ;
V_62 = V_52 ;
break;
default:
return - V_68 ;
}
if ( ! V_62 )
return - V_69 ;
F_19 ( & V_27 -> V_28 ) ;
V_61 = V_27 -> V_29 ;
if ( ! V_61 && ! V_29 ) {
V_63 = 0 ;
goto V_70;
}
if ( V_61 && V_29 ) {
if ( V_61 == V_29 && V_27 -> V_30 == V_30 )
V_63 = 0 ;
goto V_70;
}
if ( V_61 && ! V_29 )
F_26 ( V_62 , V_27 ) ;
if ( ! V_61 && V_29 ) {
V_63 = F_32 ( V_62 , F_29 , 0 , V_2 , V_27 ) ;
if ( V_63 )
goto V_70;
}
V_27 -> V_29 = V_29 ;
V_27 -> V_30 = V_30 ;
V_63 = 0 ;
V_70:
F_20 ( & V_27 -> V_28 ) ;
return V_63 ;
}
static int F_33 ( struct V_11 * V_12 ,
enum V_60 type )
{
int V_7 , V_71 , V_72 ;
switch ( type ) {
case V_65 :
V_7 = V_43 ;
V_72 = V_44 ;
break;
case V_66 :
V_7 = V_49 ;
V_72 = V_50 ;
break;
case V_67 :
V_7 = V_46 ;
V_72 = V_47 ;
break;
default:
return - V_68 ;
}
if ( V_7 == - 1 )
return - V_69 ;
V_71 = F_9 ( V_16 , NULL , V_7 , 0 ) ;
if ( V_71 < 0 )
return V_71 ;
return ( ( V_71 >> 1 ) & 1 ) == V_72 ;
}
