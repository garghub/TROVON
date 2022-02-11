static struct V_1 * F_1 ( const char * type )
{
struct V_1 * V_2 ;
V_2 = F_2 ( sizeof( * V_2 ) , V_3 ) ;
if ( ! V_2 )
return NULL ;
V_2 -> type = type ;
V_2 -> signal = V_4 ;
V_2 -> V_5 = V_6 ;
F_3 ( & V_2 -> V_7 ) ;
F_4 ( & V_2 -> V_8 ) ;
F_4 ( & V_2 -> V_9 ) ;
return V_2 ;
}
static struct V_1 * F_5 ( int V_10 )
{
struct V_1 * V_2 ;
struct V_11 * V_12 ;
F_6 (p, &atm_devs) {
V_2 = F_7 ( V_12 , struct V_1 , V_13 ) ;
if ( V_2 -> V_10 == V_10 ) {
F_8 ( V_2 ) ;
return V_2 ;
}
}
return NULL ;
}
struct V_1 * F_9 ( int V_10 )
{
struct V_1 * V_2 ;
F_10 ( & V_14 ) ;
V_2 = F_5 ( V_10 ) ;
F_11 ( & V_14 ) ;
return V_2 ;
}
struct V_1 * F_12 ( const char * type , struct V_15 * V_16 ,
const struct V_17 * V_18 , int V_10 ,
unsigned long * V_19 )
{
struct V_1 * V_2 , * V_20 ;
V_2 = F_1 ( type ) ;
if ( ! V_2 ) {
F_13 ( L_1 , type ) ;
return NULL ;
}
F_10 ( & V_14 ) ;
if ( V_10 != - 1 ) {
V_20 = F_5 ( V_10 ) ;
if ( V_20 ) {
F_14 ( V_20 ) ;
F_11 ( & V_14 ) ;
F_15 ( V_2 ) ;
return NULL ;
}
V_2 -> V_10 = V_10 ;
} else {
V_2 -> V_10 = 0 ;
while ( ( V_20 = F_5 ( V_2 -> V_10 ) ) ) {
F_14 ( V_20 ) ;
V_2 -> V_10 ++ ;
}
}
V_2 -> V_18 = V_18 ;
if ( V_19 )
V_2 -> V_19 = * V_19 ;
else
memset ( & V_2 -> V_19 , 0 , sizeof( V_2 -> V_19 ) ) ;
memset ( & V_2 -> V_21 , 0 , sizeof( V_2 -> V_21 ) ) ;
F_16 ( & V_2 -> V_22 , 1 ) ;
if ( F_17 ( V_2 ) < 0 ) {
F_13 ( L_2 , type ) ;
goto V_23;
}
if ( F_18 ( V_2 , V_16 ) < 0 ) {
F_13 ( L_3 , type ) ;
F_19 ( V_2 ) ;
goto V_23;
}
F_20 ( & V_2 -> V_13 , & V_24 ) ;
V_25:
F_11 ( & V_14 ) ;
return V_2 ;
V_23:
F_15 ( V_2 ) ;
V_2 = NULL ;
goto V_25;
}
void F_21 ( struct V_1 * V_2 )
{
F_22 ( F_23 ( V_26 , & V_2 -> V_19 ) ) ;
F_24 ( V_26 , & V_2 -> V_19 ) ;
F_10 ( & V_14 ) ;
F_25 ( & V_2 -> V_13 ) ;
F_11 ( & V_14 ) ;
F_26 ( V_2 ) ;
F_27 ( V_2 ) ;
F_19 ( V_2 ) ;
F_14 ( V_2 ) ;
}
static void F_28 ( struct V_27 * V_28 ,
struct V_29 * V_30 )
{
#define F_29 ( T_1 ) to->i = atomic_read(&from->i)
V_31
#undef F_29
}
static void F_30 ( struct V_27 * V_28 ,
struct V_29 * V_30 )
{
#define F_29 ( T_1 ) atomic_sub(to->i, &from->i)
V_31
#undef F_29
}
static int F_31 ( struct V_1 * V_2 , struct V_32 T_2 * V_33 ,
int V_34 )
{
struct V_32 V_35 ;
int error = 0 ;
F_28 ( & V_2 -> V_21 . V_36 , & V_35 . V_36 ) ;
F_28 ( & V_2 -> V_21 . V_37 , & V_35 . V_37 ) ;
F_28 ( & V_2 -> V_21 . V_38 , & V_35 . V_38 ) ;
if ( V_33 )
error = F_32 ( V_33 , & V_35 , sizeof( V_35 ) ) ;
if ( V_34 && ! error ) {
F_30 ( & V_2 -> V_21 . V_36 , & V_35 . V_36 ) ;
F_30 ( & V_2 -> V_21 . V_37 , & V_35 . V_37 ) ;
F_30 ( & V_2 -> V_21 . V_38 , & V_35 . V_38 ) ;
}
return error ? - V_39 : 0 ;
}
int F_33 ( unsigned int V_40 , void T_2 * V_33 , int V_41 )
{
void T_2 * V_42 ;
int error , V_43 , V_10 , V_44 = 0 ;
struct V_1 * V_2 ;
struct V_11 * V_12 ;
int * V_45 , * V_46 ;
int T_2 * V_47 ;
int T_2 * V_48 ;
#ifndef F_34
V_41 = 0 ;
#endif
switch ( V_40 ) {
case V_49 :
if ( V_41 ) {
#ifdef F_34
struct V_50 T_2 * V_51 = V_33 ;
T_3 V_52 ;
V_48 = & V_51 -> V_53 ;
if ( F_35 ( V_52 , & V_51 -> V_54 ) )
return - V_39 ;
V_42 = F_36 ( V_52 ) ;
#endif
} else {
struct V_55 T_2 * V_56 = V_33 ;
V_48 = & V_56 -> V_53 ;
if ( F_35 ( V_42 , & V_56 -> V_54 ) )
return - V_39 ;
}
if ( F_35 ( V_43 , V_48 ) )
return - V_39 ;
F_10 ( & V_14 ) ;
F_6 (p, &atm_devs)
V_44 += sizeof( int ) ;
if ( V_44 > V_43 ) {
F_11 ( & V_14 ) ;
return - V_57 ;
}
V_45 = F_37 ( V_44 , V_58 ) ;
if ( ! V_45 ) {
F_11 ( & V_14 ) ;
return - V_59 ;
}
V_46 = V_45 ;
F_6 (p, &atm_devs) {
V_2 = F_7 ( V_12 , struct V_1 , V_13 ) ;
* V_46 ++ = V_2 -> V_10 ;
}
F_11 ( & V_14 ) ;
error = ( ( F_32 ( V_42 , V_45 , V_44 ) ) ||
F_38 ( V_44 , V_48 ) )
? - V_39 : 0 ;
F_15 ( V_45 ) ;
return error ;
default:
break;
}
if ( V_41 ) {
#ifdef F_34
struct V_60 T_2 * V_61 = V_33 ;
T_3 V_62 ;
V_47 = & V_61 -> V_53 ;
if ( F_35 ( V_62 , & V_61 -> V_33 ) )
return - V_39 ;
V_42 = F_36 ( V_62 ) ;
if ( F_35 ( V_43 , & V_61 -> V_53 ) )
return - V_39 ;
if ( F_35 ( V_10 , & V_61 -> V_10 ) )
return - V_39 ;
#endif
} else {
struct V_63 T_2 * V_64 = V_33 ;
V_47 = & V_64 -> V_53 ;
if ( F_35 ( V_42 , & V_64 -> V_33 ) )
return - V_39 ;
if ( F_35 ( V_43 , & V_64 -> V_53 ) )
return - V_39 ;
if ( F_35 ( V_10 , & V_64 -> V_10 ) )
return - V_39 ;
}
V_2 = F_39 ( F_9 ( V_10 ) , L_4 ,
V_10 ) ;
if ( ! V_2 )
return - V_65 ;
switch ( V_40 ) {
case V_66 :
V_44 = strlen ( V_2 -> type ) + 1 ;
if ( F_32 ( V_42 , V_2 -> type , V_44 ) ) {
error = - V_39 ;
goto V_67;
}
break;
case V_68 :
V_44 = V_69 ;
if ( F_32 ( V_42 , V_2 -> V_70 , V_44 ) ) {
error = - V_39 ;
goto V_67;
}
break;
case V_71 :
{
int T_1 ;
for ( T_1 = 0 ; T_1 < V_69 ; T_1 ++ )
if ( V_2 -> V_70 [ T_1 ] ) {
error = - V_72 ;
goto V_67;
}
}
case V_73 :
{
unsigned char V_70 [ V_69 ] ;
if ( ! F_40 ( V_74 ) ) {
error = - V_75 ;
goto V_67;
}
if ( F_41 ( V_70 , V_42 , V_69 ) ) {
error = - V_39 ;
goto V_67;
}
memcpy ( V_2 -> V_70 , V_70 , V_69 ) ;
error = V_69 ;
goto V_67;
}
case V_76 :
if ( ! F_40 ( V_74 ) ) {
error = - V_75 ;
goto V_67;
}
case V_77 :
V_44 = sizeof( struct V_32 ) ;
error = F_31 ( V_2 , V_42 , V_40 == V_76 ) ;
if ( error )
goto V_67;
break;
case V_78 :
V_44 = sizeof( struct V_79 ) ;
if ( F_32 ( V_42 , & V_2 -> V_80 , V_44 ) ) {
error = - V_39 ;
goto V_67;
}
break;
case V_81 :
V_44 = sizeof( int ) ;
if ( F_32 ( V_42 , & V_2 -> V_5 , V_44 ) ) {
error = - V_39 ;
goto V_67;
}
break;
case V_82 :
if ( ! F_40 ( V_74 ) ) {
error = - V_75 ;
goto V_67;
}
F_42 ( V_2 , V_83 ) ;
break;
case V_84 :
case V_85 :
case V_86 :
case V_87 :
{
struct V_88 V_89 ;
if ( ! F_40 ( V_74 ) ) {
error = - V_75 ;
goto V_67;
}
if ( F_41 ( & V_89 , V_42 , sizeof( V_89 ) ) ) {
error = - V_39 ;
goto V_67;
}
if ( V_40 == V_84 || V_40 == V_86 )
error = F_43 ( V_2 , & V_89 ,
( V_40 == V_84 ?
V_83 : V_90 ) ) ;
else
error = F_44 ( V_2 , & V_89 ,
( V_40 == V_85 ?
V_83 : V_90 ) ) ;
goto V_67;
}
case V_91 :
case V_92 :
error = F_45 ( V_2 , V_42 , V_43 ,
( V_40 == V_91 ?
V_83 : V_90 ) ) ;
if ( error < 0 )
goto V_67;
V_44 = error ;
error = F_38 ( V_44 , V_47 ) ? - V_39 : 0 ;
goto V_67;
case V_93 :
if ( F_46 ( ( int ) ( unsigned long ) V_42 ) &&
F_47 ( ( int ) ( unsigned long ) V_42 ) >
F_46 ( ( int ) ( unsigned long ) V_42 ) ) {
error = - V_94 ;
goto V_67;
}
case V_95 :
case V_96 :
case V_97 :
case V_98 :
case V_99 :
if ( ! F_40 ( V_74 ) ) {
error = - V_75 ;
goto V_67;
}
default:
if ( V_41 ) {
#ifdef F_34
if ( ! V_2 -> V_18 -> V_100 ) {
error = - V_94 ;
goto V_67;
}
V_44 = V_2 -> V_18 -> V_100 ( V_2 , V_40 , V_42 ) ;
#endif
} else {
if ( ! V_2 -> V_18 -> V_101 ) {
error = - V_94 ;
goto V_67;
}
V_44 = V_2 -> V_18 -> V_101 ( V_2 , V_40 , V_42 ) ;
}
if ( V_44 < 0 ) {
error = ( V_44 == - V_102 ? - V_103 : V_44 ) ;
goto V_67;
}
}
if ( V_44 )
error = F_38 ( V_44 , V_47 ) ? - V_39 : 0 ;
else
error = 0 ;
V_67:
F_14 ( V_2 ) ;
return error ;
}
void * F_48 ( struct V_104 * V_105 , T_4 * V_106 )
{
F_10 ( & V_14 ) ;
return F_49 ( & V_24 , * V_106 ) ;
}
void F_50 ( struct V_104 * V_105 , void * V_107 )
{
F_11 ( & V_14 ) ;
}
void * F_51 ( struct V_104 * V_105 , void * V_107 , T_4 * V_106 )
{
return F_52 ( V_107 , & V_24 , V_106 ) ;
}
