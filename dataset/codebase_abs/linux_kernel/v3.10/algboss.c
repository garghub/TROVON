static int F_1 ( void * V_1 )
{
struct V_2 * V_3 = V_1 ;
struct V_4 * V_5 ;
struct V_6 * V_7 ;
int V_8 ;
V_5 = F_2 ( V_3 -> V_9 ) ;
if ( ! V_5 )
goto V_10;
do {
if ( V_5 -> V_11 ) {
V_8 = V_5 -> V_11 ( V_5 , V_3 -> V_12 ) ;
continue;
}
V_7 = V_5 -> V_13 ( V_3 -> V_12 ) ;
if ( F_3 ( V_7 ) )
V_8 = F_4 ( V_7 ) ;
else if ( ( V_8 = F_5 ( V_5 , V_7 ) ) )
V_5 -> free ( V_7 ) ;
} while ( V_8 == - V_14 && ! F_6 ( V_15 ) );
F_7 ( V_5 ) ;
V_10:
F_8 ( & V_3 -> V_16 -> V_17 ) ;
F_9 ( & V_3 -> V_16 -> V_18 ) ;
F_10 ( V_3 ) ;
F_11 ( 0 ) ;
}
static int F_12 ( struct V_19 * V_16 )
{
struct V_20 * V_21 ;
struct V_2 * V_3 ;
const char * V_22 = V_16 -> V_18 . V_23 ;
const char * V_24 ;
unsigned int V_25 ;
int V_26 ;
if ( ! F_13 ( V_27 ) )
goto V_8;
V_3 = F_14 ( sizeof( * V_3 ) , V_28 ) ;
if ( ! V_3 )
goto V_29;
for ( V_24 = V_22 ; isalnum ( * V_24 ) || * V_24 == '-' || * V_24 == '_' ; V_24 ++ )
;
V_25 = V_24 - V_22 ;
if ( ! V_25 || * V_24 != '(' )
goto V_30;
memcpy ( V_3 -> V_9 , V_22 , V_25 ) ;
V_26 = 0 ;
for (; ; ) {
int V_31 = 0 ;
V_22 = ++ V_24 ;
V_25 = 0 ;
for (; isalnum ( * V_24 ) || * V_24 == '-' || * V_24 == '_' ; V_24 ++ )
V_31 |= ! isdigit ( * V_24 ) ;
if ( * V_24 == '(' ) {
int V_32 = 0 ;
for (; ; ) {
if ( ! * ++ V_24 )
goto V_30;
if ( * V_24 == '(' )
V_32 ++ ;
else if ( * V_24 == ')' && ! V_32 -- )
break;
}
V_31 = 1 ;
V_24 ++ ;
}
V_25 = V_24 - V_22 ;
if ( ! V_25 )
goto V_30;
if ( V_31 ) {
V_3 -> V_33 [ V_26 ] . V_18 . V_34 . V_35 =
sizeof( V_3 -> V_33 [ V_26 ] . V_18 ) ;
V_3 -> V_33 [ V_26 ] . V_18 . V_34 . V_36 = V_37 ;
memcpy ( V_3 -> V_33 [ V_26 ] . V_18 . V_1 . V_22 , V_22 , V_25 ) ;
} else {
V_3 -> V_33 [ V_26 ] . V_38 . V_34 . V_35 =
sizeof( V_3 -> V_33 [ V_26 ] . V_38 ) ;
V_3 -> V_33 [ V_26 ] . V_38 . V_34 . V_36 = V_39 ;
V_3 -> V_33 [ V_26 ] . V_38 . V_1 . V_40 =
F_15 ( V_22 , NULL , 0 ) ;
}
V_3 -> V_12 [ V_26 + 1 ] = & V_3 -> V_33 [ V_26 ] . V_34 ;
V_26 ++ ;
if ( V_26 >= V_41 )
goto V_30;
if ( * V_24 == ')' )
break;
if ( * V_24 != ',' )
goto V_30;
}
if ( ! V_26 )
goto V_30;
V_3 -> V_12 [ V_26 + 1 ] = NULL ;
V_3 -> type . V_34 . V_35 = sizeof( V_3 -> type ) ;
V_3 -> type . V_34 . V_36 = V_42 ;
V_3 -> type . V_1 . type = V_16 -> V_18 . V_43 & ~ V_44 ;
V_3 -> type . V_1 . V_45 = V_16 -> V_45 & ~ V_44 ;
V_3 -> V_12 [ 0 ] = & V_3 -> type . V_34 ;
V_3 -> V_46 = V_16 -> V_18 . V_43 ;
V_3 -> V_47 = V_16 -> V_45 ;
F_16 ( & V_16 -> V_18 ) ;
V_3 -> V_16 = V_16 ;
V_21 = F_17 ( F_1 , V_3 , L_1 ) ;
if ( F_3 ( V_21 ) )
goto V_48;
F_18 ( & V_16 -> V_17 ) ;
return V_49 ;
V_48:
F_9 ( & V_16 -> V_18 ) ;
V_30:
F_10 ( V_3 ) ;
V_29:
F_19 ( V_27 ) ;
V_8:
return V_50 ;
}
static int F_20 ( void * V_1 )
{
struct V_51 * V_3 = V_1 ;
T_1 type = V_3 -> type ;
int V_8 = 0 ;
#ifdef F_21
goto V_52;
#endif
if ( type & V_44 )
goto V_52;
V_8 = F_22 ( V_3 -> V_53 , V_3 -> V_18 , type , V_44 ) ;
V_52:
F_23 ( V_3 -> V_53 , V_8 ) ;
F_10 ( V_3 ) ;
F_11 ( 0 ) ;
}
static int F_24 ( struct V_54 * V_18 )
{
struct V_20 * V_21 ;
struct V_51 * V_3 ;
T_1 type ;
if ( ! F_13 ( V_27 ) )
goto V_8;
V_3 = F_14 ( sizeof( * V_3 ) , V_28 ) ;
if ( ! V_3 )
goto V_29;
memcpy ( V_3 -> V_53 , V_18 -> V_55 , sizeof( V_3 -> V_53 ) ) ;
memcpy ( V_3 -> V_18 , V_18 -> V_23 , sizeof( V_3 -> V_18 ) ) ;
type = V_18 -> V_43 ;
if ( ( ! ( ( type ^ V_56 ) &
V_57 ) && ! ( type & V_58 ) &&
( ( V_18 -> V_43 & V_59 ) ==
V_56 ? V_18 -> V_60 . V_61 :
V_18 -> V_62 . V_61 ) ) ||
( ! ( ( type ^ V_63 ) & V_59 ) &&
V_18 -> V_64 == & V_65 && V_18 -> V_66 . V_61 ) )
type |= V_44 ;
V_3 -> type = type ;
V_21 = F_17 ( F_20 , V_3 , L_2 ) ;
if ( F_3 ( V_21 ) )
goto V_30;
return V_49 ;
V_30:
F_10 ( V_3 ) ;
V_29:
F_19 ( V_27 ) ;
V_8:
return V_50 ;
}
static int F_25 ( struct V_67 * V_68 , unsigned long V_69 ,
void * V_1 )
{
switch ( V_69 ) {
case V_70 :
return F_12 ( V_1 ) ;
case V_71 :
return F_24 ( V_1 ) ;
}
return V_72 ;
}
static int T_2 F_26 ( void )
{
return F_27 ( & V_73 ) ;
}
static void T_3 F_28 ( void )
{
int V_8 = F_29 ( & V_73 ) ;
F_30 ( V_8 ) ;
}
