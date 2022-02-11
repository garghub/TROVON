T_1 * F_1 ( T_2 * V_1 )
{
T_1 * V_2 ;
V_2 = F_2 ( sizeof( * V_2 ) ) ;
if ( V_2 == NULL )
return NULL ;
V_2 -> V_1 = V_1 ;
if ( ( V_1 -> V_3 != NULL ) && ! V_1 -> V_3 ( V_2 ) ) {
F_3 ( V_2 ) ;
return NULL ;
}
return V_2 ;
}
void F_4 ( T_1 * V_4 )
{
if ( V_4 == NULL )
return;
if ( ( V_4 -> V_1 != NULL ) && ( V_4 -> V_1 -> free != NULL ) )
(* V_4 -> V_1 -> free ) ( V_4 ) ;
F_3 ( V_4 ) ;
}
int F_5 ( T_3 * V_5 )
{
return F_6 ( V_5 -> V_6 ) ;
}
int F_7 ( T_3 * V_5 )
{
return F_8 ( V_5 -> V_6 ) ;
}
int F_9 ( T_1 * V_4 )
{
if ( V_4 -> V_1 == NULL )
return 0 ;
if ( V_4 -> V_1 -> V_7 != NULL )
return V_4 -> V_1 -> V_7 ( V_4 ) ;
else
return 1 ;
}
int F_10 ( T_1 * V_4 )
{
if ( V_4 -> V_1 == NULL )
return 0 ;
if ( V_4 -> V_1 -> V_8 != NULL )
return V_4 -> V_1 -> V_8 ( V_4 ) ;
else
return 1 ;
}
int F_11 ( T_1 * V_4 , int V_9 , const char * V_10 , long V_11 ,
char * * V_2 )
{
if ( V_4 -> V_1 == NULL )
return - 1 ;
if ( V_4 -> V_1 -> V_12 != NULL )
return V_4 -> V_1 -> V_12 ( V_4 , V_9 , V_10 , V_11 , V_2 ) ;
else
return 1 ;
}
int F_12 ( T_1 * V_4 , T_4 type ,
T_5 * V_13 , T_6 * V_2 )
{
if ( ( V_4 -> V_1 == NULL ) || ( V_4 -> V_1 -> V_14 == NULL ) )
return 0 ;
if ( V_4 -> V_15 )
return 0 ;
return V_4 -> V_1 -> V_14 ( V_4 , type , V_13 , V_2 ) ;
}
int F_13 ( T_1 * V_4 , T_4 type ,
T_5 * V_13 , T_7 * V_16 ,
T_6 * V_2 )
{
if ( ( V_4 -> V_1 == NULL ) || ( V_4 -> V_1 -> V_17 == NULL ) )
return 0 ;
return V_4 -> V_1 -> V_17 ( V_4 , type , V_13 , V_16 , V_2 ) ;
}
int F_14 ( T_1 * V_4 , T_4 type ,
const unsigned char * V_18 , int V_19 ,
T_6 * V_2 )
{
if ( ( V_4 -> V_1 == NULL ) || ( V_4 -> V_1 -> V_20 == NULL ) )
return 0 ;
return V_4 -> V_1 -> V_20 ( V_4 , type , V_18 , V_19 , V_2 ) ;
}
int F_15 ( T_1 * V_4 , T_4 type ,
const char * V_21 , int V_19 , T_6 * V_2 )
{
if ( ( V_4 -> V_1 == NULL ) || ( V_4 -> V_1 -> V_22 == NULL ) )
return 0 ;
return V_4 -> V_1 -> V_22 ( V_4 , type , V_21 , V_19 , V_2 ) ;
}
static int F_16 ( const T_6 * const * V_23 ,
const T_6 * const * V_24 )
{
int V_2 ;
V_2 = ( ( * V_23 ) -> type - ( * V_24 ) -> type ) ;
if ( V_2 )
return V_2 ;
switch ( ( * V_23 ) -> type ) {
case V_25 :
V_2 = F_17 ( ( * V_23 ) -> V_26 . V_27 , ( * V_24 ) -> V_26 . V_27 ) ;
break;
case V_28 :
V_2 = F_18 ( ( * V_23 ) -> V_26 . V_29 , ( * V_24 ) -> V_26 . V_29 ) ;
break;
default:
return 0 ;
}
return V_2 ;
}
T_3 * F_19 ( void )
{
T_3 * V_2 ;
if ( ( V_2 = F_2 ( sizeof( * V_2 ) ) ) == NULL )
return NULL ;
if ( ( V_2 -> V_30 = F_20 ( F_16 ) ) == NULL )
goto V_31;
V_2 -> V_32 = 1 ;
if ( ( V_2 -> V_33 = F_21 () ) == NULL )
goto V_31;
if ( ( V_2 -> V_34 = F_22 () ) == NULL )
goto V_31;
if ( ! F_23 ( V_35 , V_2 , & V_2 -> V_36 ) )
goto V_31;
V_2 -> V_6 = F_24 () ;
if ( V_2 -> V_6 == NULL )
goto V_31;
V_2 -> V_37 = 1 ;
return V_2 ;
V_31:
F_25 ( V_2 -> V_34 ) ;
F_26 ( V_2 -> V_30 ) ;
F_27 ( V_2 -> V_33 ) ;
F_3 ( V_2 ) ;
return NULL ;
}
static void F_28 ( T_6 * V_23 )
{
if ( ! V_23 )
return;
if ( V_23 -> type == V_25 ) {
F_29 ( V_23 -> V_26 . V_27 ) ;
} else if ( V_23 -> type == V_28 ) {
F_30 ( V_23 -> V_26 . V_29 ) ;
} else {
}
F_3 ( V_23 ) ;
}
void F_31 ( T_3 * V_38 )
{
int V_39 ;
F_32 ( T_1 ) * V_40 ;
T_1 * V_41 ;
if ( V_38 == NULL )
return;
F_33 ( & V_38 -> V_37 , - 1 , & V_39 , V_38 -> V_6 ) ;
F_34 ( L_1 , V_38 ) ;
if ( V_39 > 0 )
return;
F_35 ( V_39 < 0 ) ;
V_40 = V_38 -> V_33 ;
for ( V_39 = 0 ; V_39 < F_36 ( V_40 ) ; V_39 ++ ) {
V_41 = F_37 ( V_40 , V_39 ) ;
F_10 ( V_41 ) ;
F_4 ( V_41 ) ;
}
F_27 ( V_40 ) ;
F_38 ( V_38 -> V_30 , F_28 ) ;
F_39 ( V_35 , V_38 , & V_38 -> V_36 ) ;
F_25 ( V_38 -> V_34 ) ;
F_40 ( V_38 -> V_6 ) ;
F_3 ( V_38 ) ;
}
int F_41 ( T_3 * V_38 )
{
int V_39 ;
if ( F_33 ( & V_38 -> V_37 , 1 , & V_39 , V_38 -> V_6 ) <= 0 )
return 0 ;
F_34 ( L_1 , V_23 ) ;
F_35 ( V_39 < 2 ) ;
return ( ( V_39 > 1 ) ? 1 : 0 ) ;
}
T_1 * F_42 ( T_3 * V_42 , T_2 * V_43 )
{
int V_39 ;
F_32 ( T_1 ) * V_40 ;
T_1 * V_41 ;
V_40 = V_42 -> V_33 ;
for ( V_39 = 0 ; V_39 < F_36 ( V_40 ) ; V_39 ++ ) {
V_41 = F_37 ( V_40 , V_39 ) ;
if ( V_43 == V_41 -> V_1 ) {
return V_41 ;
}
}
V_41 = F_1 ( V_43 ) ;
if ( V_41 == NULL )
return NULL ;
else {
V_41 -> V_44 = V_42 ;
if ( F_43 ( V_42 -> V_33 , V_41 ) )
return V_41 ;
else {
F_4 ( V_41 ) ;
return NULL ;
}
}
}
T_6 * F_44 ( T_8 * V_45 ,
T_4 type ,
T_5 * V_13 )
{
T_6 * V_2 = F_45 () ;
if ( V_2 == NULL )
return NULL ;
if ( ! F_46 ( V_45 , type , V_13 , V_2 ) ) {
F_47 ( V_2 ) ;
return NULL ;
}
return V_2 ;
}
int F_46 ( T_8 * V_45 , T_4 type ,
T_5 * V_13 , T_6 * V_2 )
{
T_3 * V_4 = V_45 -> V_4 ;
T_1 * V_41 ;
T_6 V_46 , * V_47 ;
int V_39 , V_48 ;
F_6 ( V_4 -> V_6 ) ;
V_47 = F_48 ( V_4 -> V_30 , type , V_13 ) ;
F_8 ( V_4 -> V_6 ) ;
if ( V_47 == NULL || type == V_28 ) {
for ( V_39 = 0 ; V_39 < F_36 ( V_4 -> V_33 ) ; V_39 ++ ) {
V_41 = F_37 ( V_4 -> V_33 , V_39 ) ;
V_48 = F_12 ( V_41 , type , V_13 , & V_46 ) ;
if ( V_48 ) {
V_47 = & V_46 ;
break;
}
}
if ( V_47 == NULL )
return 0 ;
}
V_2 -> type = V_47 -> type ;
V_2 -> V_26 . V_49 = V_47 -> V_26 . V_49 ;
F_49 ( V_2 ) ;
return 1 ;
}
int F_50 ( T_3 * V_4 , T_9 * V_50 )
{
T_6 * V_51 ;
int V_2 = 1 , V_52 = 1 ;
if ( V_50 == NULL )
return 0 ;
V_51 = F_45 () ;
if ( V_51 == NULL )
return 0 ;
V_51 -> type = V_25 ;
V_51 -> V_26 . V_27 = V_50 ;
F_49 ( V_51 ) ;
F_6 ( V_4 -> V_6 ) ;
if ( F_51 ( V_4 -> V_30 , V_51 ) ) {
F_52 ( V_53 ,
V_54 ) ;
V_2 = 0 ;
} else {
V_52 = F_53 ( V_4 -> V_30 , V_51 ) ;
V_2 = V_52 != 0 ;
}
F_8 ( V_4 -> V_6 ) ;
if ( ! V_2 )
F_47 ( V_51 ) ;
if ( ! V_52 )
F_52 ( V_53 , V_55 ) ;
return V_2 ;
}
int F_54 ( T_3 * V_4 , T_10 * V_50 )
{
T_6 * V_51 ;
int V_2 = 1 , V_52 = 1 ;
if ( V_50 == NULL )
return 0 ;
V_51 = F_45 () ;
if ( V_51 == NULL )
return 0 ;
V_51 -> type = V_28 ;
V_51 -> V_26 . V_29 = V_50 ;
F_49 ( V_51 ) ;
F_6 ( V_4 -> V_6 ) ;
if ( F_51 ( V_4 -> V_30 , V_51 ) ) {
F_52 ( V_56 , V_54 ) ;
V_2 = 0 ;
} else {
V_52 = F_53 ( V_4 -> V_30 , V_51 ) ;
V_2 = V_52 != 0 ;
}
F_8 ( V_4 -> V_6 ) ;
if ( ! V_2 )
F_47 ( V_51 ) ;
if ( ! V_52 )
F_52 ( V_56 , V_55 ) ;
return V_2 ;
}
int F_49 ( T_6 * V_23 )
{
switch ( V_23 -> type ) {
default:
break;
case V_25 :
return F_55 ( V_23 -> V_26 . V_27 ) ;
case V_28 :
return F_56 ( V_23 -> V_26 . V_29 ) ;
}
return 1 ;
}
T_9 * F_57 ( const T_6 * V_23 )
{
if ( V_23 == NULL || V_23 -> type != V_25 )
return NULL ;
return V_23 -> V_26 . V_27 ;
}
T_10 * F_58 ( T_6 * V_23 )
{
if ( V_23 == NULL || V_23 -> type != V_28 )
return NULL ;
return V_23 -> V_26 . V_29 ;
}
T_4 F_59 ( const T_6 * V_23 )
{
return V_23 -> type ;
}
T_6 * F_45 ()
{
T_6 * V_2 = F_2 ( sizeof( * V_2 ) ) ;
if ( V_2 == NULL ) {
F_52 ( V_57 , V_55 ) ;
return NULL ;
}
V_2 -> type = V_58 ;
return V_2 ;
}
void F_47 ( T_6 * V_23 )
{
if ( V_23 == NULL )
return;
switch ( V_23 -> type ) {
default:
break;
case V_25 :
F_29 ( V_23 -> V_26 . V_27 ) ;
break;
case V_28 :
F_30 ( V_23 -> V_26 . V_29 ) ;
break;
}
F_3 ( V_23 ) ;
}
int F_60 ( T_3 * V_4 , unsigned long V_59 )
{
return F_61 ( V_4 -> V_34 , V_59 ) ;
}
int F_62 ( T_3 * V_4 , int V_60 )
{
F_63 ( V_4 -> V_34 , V_60 ) ;
return 1 ;
}
int F_64 ( T_3 * V_4 , int V_61 )
{
return F_65 ( V_4 -> V_34 , V_61 ) ;
}
int F_66 ( T_3 * V_4 , int V_62 )
{
return F_67 ( V_4 -> V_34 , V_62 ) ;
}
int F_68 ( T_3 * V_4 , T_11 * V_34 )
{
return F_69 ( V_4 -> V_34 , V_34 ) ;
}
T_11 * F_70 ( T_3 * V_4 )
{
return V_4 -> V_34 ;
}
void F_71 ( T_3 * V_4 , T_12 V_63 )
{
V_4 -> V_63 = V_63 ;
}
T_12 F_72 ( T_3 * V_4 )
{
return V_4 -> V_63 ;
}
void F_73 ( T_3 * V_4 ,
T_13 V_64 )
{
V_4 -> V_64 = V_64 ;
}
T_13 F_74 ( T_3 * V_4 )
{
return V_4 -> V_64 ;
}
void F_75 ( T_3 * V_4 ,
T_14 V_65 )
{
V_4 -> V_65 = V_65 ;
}
T_14 F_76 ( T_3 * V_4 )
{
return V_4 -> V_65 ;
}
void F_77 ( T_3 * V_4 ,
T_15 V_66 )
{
V_4 -> V_66 = V_66 ;
}
T_15 F_78 ( T_3 * V_4 )
{
return V_4 -> V_66 ;
}
void F_79 ( T_3 * V_4 ,
T_16 V_67 )
{
V_4 -> V_67 = V_67 ;
}
T_16 F_80 ( T_3 * V_4 )
{
return V_4 -> V_67 ;
}
void F_81 ( T_3 * V_4 ,
T_17 V_68 )
{
V_4 -> V_68 = V_68 ;
}
T_17 F_82 ( T_3 * V_4 )
{
return V_4 -> V_68 ;
}
void F_83 ( T_3 * V_4 ,
T_18 V_69 )
{
V_4 -> V_69 = V_69 ;
}
T_18 F_84 ( T_3 * V_4 )
{
return V_4 -> V_69 ;
}
void F_85 ( T_3 * V_4 ,
T_19 V_70 )
{
V_4 -> V_70 = V_70 ;
}
T_19 F_86 ( T_3 * V_4 )
{
return V_4 -> V_70 ;
}
void F_87 ( T_3 * V_4 ,
T_20 V_71 )
{
V_4 -> V_71 = V_71 ;
}
T_20 F_88 ( T_3 * V_4 )
{
return V_4 -> V_71 ;
}
void F_89 ( T_3 * V_4 ,
T_21 V_72 )
{
V_4 -> V_72 = V_72 ;
}
T_21 F_90 ( T_3 * V_4 )
{
return V_4 -> V_72 ;
}
void F_91 ( T_3 * V_4 ,
T_22 V_73 )
{
V_4 -> V_73 = V_73 ;
}
T_22 F_92 ( T_3 * V_4 )
{
return V_4 -> V_73 ;
}
void F_93 ( T_3 * V_4 ,
T_23 V_74 )
{
V_4 -> F_28 = V_74 ;
}
T_23 F_94 ( T_3 * V_4 )
{
return V_4 -> F_28 ;
}
int F_95 ( T_3 * V_4 , int V_75 , void * V_26 )
{
return F_96 ( & V_4 -> V_36 , V_75 , V_26 ) ;
}
void * F_97 ( T_3 * V_4 , int V_75 )
{
return F_98 ( & V_4 -> V_36 , V_75 ) ;
}
T_3 * F_99 ( T_8 * V_4 )
{
return V_4 -> V_4 ;
}
