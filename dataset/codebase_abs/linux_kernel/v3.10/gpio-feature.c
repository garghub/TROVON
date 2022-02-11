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
* V_10 = V_11 ;
}
static void F_7 ( struct V_12 * V_13 , int V_14 )
{
int V_15 ;
if ( F_8 ( ! V_13 ) ) return;
if ( V_16 < 0 )
return;
V_15 = F_9 ( V_17 , NULL ,
V_16 , 0 ) ;
V_15 = F_10 ( V_18 , V_15 , V_14 ) ;
F_9 ( V_19 , NULL ,
V_16 , V_15 ) ;
}
static void F_11 ( struct V_12 * V_13 )
{
int V_20 ;
if ( F_8 ( ! V_13 ) ) return;
V_20 = V_13 -> V_21 ;
F_12 ( V_13 , 0 ) ;
F_13 ( V_13 , 0 ) ;
F_14 ( V_13 , 0 ) ;
if ( V_22 . V_23 )
F_15 ( V_13 , 0 ) ;
V_13 -> V_21 = V_20 ;
}
static void F_16 ( struct V_12 * V_13 )
{
int V_24 ;
if ( F_8 ( ! V_13 ) ) return;
V_24 = V_13 -> V_21 ;
F_12 ( V_13 , ( V_24 >> 0 ) & 1 ) ;
F_13 ( V_13 , ( V_24 >> 1 ) & 1 ) ;
F_14 ( V_13 , ( V_24 >> 2 ) & 1 ) ;
if ( V_22 . V_23 )
F_15 ( V_13 , ( V_24 >> 3 ) & 1 ) ;
}
static void F_17 ( struct V_25 * V_26 )
{
struct V_27 * V_28 =
F_18 ( V_26 , struct V_27 , V_26 . V_26 ) ;
F_19 ( & V_28 -> V_29 ) ;
if ( V_28 -> V_30 )
V_28 -> V_30 ( V_28 -> V_31 ) ;
F_20 ( & V_28 -> V_29 ) ;
}
static void F_21 ( int V_7 )
{
int V_15 ;
if ( V_7 == - 1 )
return;
V_15 = F_9 ( V_17 , NULL , V_7 , 0 ) ;
V_15 |= 0x80 ;
F_9 ( V_19 , NULL , V_7 , V_15 ) ;
}
static void F_22 ( struct V_12 * V_13 )
{
F_1 ( L_5 , NULL ,
& V_32 ,
& V_33 ) ;
F_1 ( L_6 , NULL ,
& V_34 ,
& V_35 ) ;
F_1 ( L_7 , NULL ,
& V_36 ,
& V_37 ) ;
F_1 ( L_8 , L_9 ,
& V_16 ,
& V_38 ) ;
if ( F_1 ( L_10 , NULL ,
& V_39 ,
& V_40 ) ) {
V_22 . V_23 = F_15 ;
V_22 . V_41 = V_42 ;
}
V_43 = F_1 ( L_11 , NULL ,
& V_44 ,
& V_45 ) ;
V_46 = F_1 ( L_12 , L_13 ,
& V_47 ,
& V_48 ) ;
V_49 = F_1 ( L_14 , L_15 ,
& V_50 ,
& V_51 ) ;
F_21 ( V_44 ) ;
F_21 ( V_47 ) ;
F_21 ( V_50 ) ;
F_5 ( V_43 , & V_52 ) ;
F_5 ( V_46 , & V_53 ) ;
F_5 ( V_49 , & V_54 ) ;
F_11 ( V_13 ) ;
V_13 -> V_21 = 0 ;
F_23 ( & V_13 -> V_55 . V_26 , F_17 ) ;
F_23 ( & V_13 -> V_56 . V_26 , F_17 ) ;
F_23 ( & V_13 -> V_57 . V_26 , F_17 ) ;
F_24 ( & V_13 -> V_55 . V_29 ) ;
F_24 ( & V_13 -> V_56 . V_29 ) ;
F_24 ( & V_13 -> V_57 . V_29 ) ;
}
static void F_25 ( struct V_12 * V_13 )
{
F_11 ( V_13 ) ;
V_13 -> V_21 = 0 ;
if ( V_13 -> V_55 . V_30 )
F_26 ( V_52 , & V_13 -> V_55 ) ;
if ( V_13 -> V_56 . V_58 )
F_26 ( V_54 , & V_13 -> V_56 ) ;
if ( V_13 -> V_57 . V_58 )
F_26 ( V_53 , & V_13 -> V_57 ) ;
F_27 ( & V_13 -> V_55 . V_26 ) ;
F_27 ( & V_13 -> V_56 . V_26 ) ;
F_27 ( & V_13 -> V_57 . V_26 ) ;
F_28 ( & V_13 -> V_55 . V_29 ) ;
F_28 ( & V_13 -> V_56 . V_29 ) ;
F_28 ( & V_13 -> V_57 . V_29 ) ;
}
static T_2 F_29 ( int V_59 , void * V_31 )
{
struct V_27 * V_28 = V_31 ;
F_30 ( & V_28 -> V_26 , 0 ) ;
return V_60 ;
}
static int F_31 ( struct V_12 * V_13 ,
enum V_61 type ,
T_3 V_30 ,
void * V_31 )
{
struct V_27 * V_28 ;
T_3 V_62 ;
int V_63 ;
char * V_2 ;
int V_64 = - V_65 ;
switch ( type ) {
case V_66 :
V_28 = & V_13 -> V_55 ;
V_2 = L_11 ;
V_63 = V_52 ;
break;
case V_67 :
V_28 = & V_13 -> V_56 ;
V_2 = L_14 ;
V_63 = V_54 ;
break;
case V_68 :
V_28 = & V_13 -> V_57 ;
V_2 = L_12 ;
V_63 = V_53 ;
break;
default:
return - V_69 ;
}
if ( V_63 == V_11 )
return - V_70 ;
F_19 ( & V_28 -> V_29 ) ;
V_62 = V_28 -> V_30 ;
if ( ! V_62 && ! V_30 ) {
V_64 = 0 ;
goto V_71;
}
if ( V_62 && V_30 ) {
if ( V_62 == V_30 && V_28 -> V_31 == V_31 )
V_64 = 0 ;
goto V_71;
}
if ( V_62 && ! V_30 )
F_26 ( V_63 , V_28 ) ;
if ( ! V_62 && V_30 ) {
V_64 = F_32 ( V_63 , F_29 , 0 , V_2 , V_28 ) ;
if ( V_64 )
goto V_71;
}
V_28 -> V_30 = V_30 ;
V_28 -> V_31 = V_31 ;
V_64 = 0 ;
V_71:
F_20 ( & V_28 -> V_29 ) ;
return V_64 ;
}
static int F_33 ( struct V_12 * V_13 ,
enum V_61 type )
{
int V_7 , V_72 , V_73 ;
switch ( type ) {
case V_66 :
V_7 = V_44 ;
V_73 = V_45 ;
break;
case V_67 :
V_7 = V_50 ;
V_73 = V_51 ;
break;
case V_68 :
V_7 = V_47 ;
V_73 = V_48 ;
break;
default:
return - V_69 ;
}
if ( V_7 == - 1 )
return - V_70 ;
V_72 = F_9 ( V_17 , NULL , V_7 , 0 ) ;
if ( V_72 < 0 )
return V_72 ;
return ( ( V_72 >> 1 ) & 1 ) == V_73 ;
}
