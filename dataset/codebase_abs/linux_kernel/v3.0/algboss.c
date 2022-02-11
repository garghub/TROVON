static int F_1 ( void * V_1 )
{
struct V_2 * V_3 = V_1 ;
struct V_4 * V_5 ;
struct V_6 * V_7 ;
int V_8 ;
V_5 = F_2 ( V_3 -> V_9 ) ;
if ( ! V_5 )
goto V_8;
do {
if ( V_5 -> V_10 ) {
V_8 = V_5 -> V_10 ( V_5 , V_3 -> V_11 ) ;
continue;
}
V_7 = V_5 -> V_12 ( V_3 -> V_11 ) ;
if ( F_3 ( V_7 ) )
V_8 = F_4 ( V_7 ) ;
else if ( ( V_8 = F_5 ( V_5 , V_7 ) ) )
V_5 -> free ( V_7 ) ;
} while ( V_8 == - V_13 && ! F_6 ( V_14 ) );
F_7 ( V_5 ) ;
if ( V_8 )
goto V_8;
V_15:
F_8 ( V_3 ) ;
F_9 ( 0 ) ;
V_8:
F_10 ( V_3 -> V_16 , V_3 -> V_17 , V_3 -> V_18 ) ;
goto V_15;
}
static int F_11 ( struct V_19 * V_16 )
{
struct V_20 * V_21 ;
struct V_2 * V_3 ;
const char * V_22 = V_16 -> V_23 . V_24 ;
const char * V_25 ;
unsigned int V_26 ;
int V_27 ;
if ( ! F_12 ( V_28 ) )
goto V_8;
V_3 = F_13 ( sizeof( * V_3 ) , V_29 ) ;
if ( ! V_3 )
goto V_30;
for ( V_25 = V_22 ; isalnum ( * V_25 ) || * V_25 == '-' || * V_25 == '_' ; V_25 ++ )
;
V_26 = V_25 - V_22 ;
if ( ! V_26 || * V_25 != '(' )
goto V_31;
memcpy ( V_3 -> V_9 , V_22 , V_26 ) ;
V_27 = 0 ;
for (; ; ) {
int V_32 = 0 ;
V_22 = ++ V_25 ;
V_26 = 0 ;
for (; isalnum ( * V_25 ) || * V_25 == '-' || * V_25 == '_' ; V_25 ++ )
V_32 |= ! isdigit ( * V_25 ) ;
if ( * V_25 == '(' ) {
int V_33 = 0 ;
for (; ; ) {
if ( ! * ++ V_25 )
goto V_31;
if ( * V_25 == '(' )
V_33 ++ ;
else if ( * V_25 == ')' && ! V_33 -- )
break;
}
V_32 = 1 ;
V_25 ++ ;
}
V_26 = V_25 - V_22 ;
if ( ! V_26 )
goto V_31;
if ( V_32 ) {
V_3 -> V_34 [ V_27 ] . V_23 . V_35 . V_36 =
sizeof( V_3 -> V_34 [ V_27 ] . V_23 ) ;
V_3 -> V_34 [ V_27 ] . V_23 . V_35 . V_37 = V_38 ;
memcpy ( V_3 -> V_34 [ V_27 ] . V_23 . V_1 . V_22 , V_22 , V_26 ) ;
} else {
V_3 -> V_34 [ V_27 ] . V_39 . V_35 . V_36 =
sizeof( V_3 -> V_34 [ V_27 ] . V_39 ) ;
V_3 -> V_34 [ V_27 ] . V_39 . V_35 . V_37 = V_40 ;
V_3 -> V_34 [ V_27 ] . V_39 . V_1 . V_41 =
F_14 ( V_22 , NULL , 0 ) ;
}
V_3 -> V_11 [ V_27 + 1 ] = & V_3 -> V_34 [ V_27 ] . V_35 ;
V_27 ++ ;
if ( V_27 >= V_42 )
goto V_31;
if ( * V_25 == ')' )
break;
if ( * V_25 != ',' )
goto V_31;
}
if ( ! V_27 )
goto V_31;
V_3 -> V_11 [ V_27 + 1 ] = NULL ;
V_3 -> type . V_35 . V_36 = sizeof( V_3 -> type ) ;
V_3 -> type . V_35 . V_37 = V_43 ;
V_3 -> type . V_1 . type = V_16 -> V_23 . V_44 & ~ V_45 ;
V_3 -> type . V_1 . V_46 = V_16 -> V_46 & ~ V_45 ;
V_3 -> V_11 [ 0 ] = & V_3 -> type . V_35 ;
V_3 -> V_17 = V_16 -> V_23 . V_44 ;
V_3 -> V_18 = V_16 -> V_46 ;
memcpy ( V_3 -> V_16 , V_16 -> V_23 . V_24 , V_47 ) ;
V_21 = F_15 ( F_1 , V_3 , L_1 ) ;
if ( F_3 ( V_21 ) )
goto V_31;
return V_48 ;
V_31:
F_8 ( V_3 ) ;
V_30:
F_16 ( V_28 ) ;
V_8:
return V_49 ;
}
static int F_17 ( void * V_1 )
{
struct V_50 * V_3 = V_1 ;
T_1 type = V_3 -> type ;
int V_8 = 0 ;
#ifdef F_18
goto V_51;
#endif
if ( type & V_45 )
goto V_51;
V_8 = F_19 ( V_3 -> V_52 , V_3 -> V_23 , type , V_45 ) ;
V_51:
F_20 ( V_3 -> V_52 , V_8 ) ;
F_8 ( V_3 ) ;
F_9 ( 0 ) ;
}
static int F_21 ( struct V_53 * V_23 )
{
struct V_20 * V_21 ;
struct V_50 * V_3 ;
T_1 type ;
if ( ! F_12 ( V_28 ) )
goto V_8;
V_3 = F_13 ( sizeof( * V_3 ) , V_29 ) ;
if ( ! V_3 )
goto V_30;
memcpy ( V_3 -> V_52 , V_23 -> V_54 , sizeof( V_3 -> V_52 ) ) ;
memcpy ( V_3 -> V_23 , V_23 -> V_24 , sizeof( V_3 -> V_23 ) ) ;
type = V_23 -> V_44 ;
if ( ( ! ( ( type ^ V_55 ) &
V_56 ) && ! ( type & V_57 ) &&
( ( V_23 -> V_44 & V_58 ) ==
V_55 ? V_23 -> V_59 . V_60 :
V_23 -> V_61 . V_60 ) ) ||
( ! ( ( type ^ V_62 ) & V_58 ) &&
V_23 -> V_63 == & V_64 && V_23 -> V_65 . V_60 ) )
type |= V_45 ;
V_3 -> type = type ;
V_21 = F_15 ( F_17 , V_3 , L_2 ) ;
if ( F_3 ( V_21 ) )
goto V_31;
return V_48 ;
V_31:
F_8 ( V_3 ) ;
V_30:
F_16 ( V_28 ) ;
V_8:
return V_49 ;
}
static int F_22 ( struct V_66 * V_67 , unsigned long V_68 ,
void * V_1 )
{
switch ( V_68 ) {
case V_69 :
return F_11 ( V_1 ) ;
case V_70 :
return F_21 ( V_1 ) ;
}
return V_71 ;
}
static int T_2 F_23 ( void )
{
return F_24 ( & V_72 ) ;
}
static void T_3 F_25 ( void )
{
int V_8 = F_26 ( & V_72 ) ;
F_27 ( V_8 ) ;
}
