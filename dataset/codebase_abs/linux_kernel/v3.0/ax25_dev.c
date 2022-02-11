T_1 * F_1 ( T_2 * V_1 )
{
T_1 * T_1 , * V_2 = NULL ;
F_2 ( & V_3 ) ;
for ( T_1 = V_4 ; T_1 != NULL ; T_1 = T_1 -> V_5 )
if ( F_3 ( V_1 , ( T_2 * ) T_1 -> V_6 -> V_7 ) == 0 ) {
V_2 = T_1 ;
}
F_4 ( & V_3 ) ;
return V_2 ;
}
void F_5 ( struct V_8 * V_6 )
{
T_1 * T_1 ;
if ( ( T_1 = F_6 ( sizeof( * T_1 ) , V_9 ) ) == NULL ) {
F_7 ( V_10 L_1 ) ;
return;
}
F_8 () ;
V_6 -> V_11 = T_1 ;
T_1 -> V_6 = V_6 ;
F_9 ( V_6 ) ;
T_1 -> V_12 = NULL ;
T_1 -> V_13 [ V_14 ] = V_15 ;
T_1 -> V_13 [ V_16 ] = V_17 ;
T_1 -> V_13 [ V_18 ] = V_19 ;
T_1 -> V_13 [ V_20 ] = V_21 ;
T_1 -> V_13 [ V_22 ] = V_23 ;
T_1 -> V_13 [ V_24 ] = V_25 ;
T_1 -> V_13 [ V_26 ] = V_27 ;
T_1 -> V_13 [ V_28 ] = V_29 ;
T_1 -> V_13 [ V_30 ] = V_31 ;
T_1 -> V_13 [ V_32 ] = V_33 ;
T_1 -> V_13 [ V_34 ] = V_35 ;
T_1 -> V_13 [ V_36 ] = V_37 ;
T_1 -> V_13 [ V_38 ] = V_39 ;
T_1 -> V_13 [ V_40 ] = V_41 ;
#if F_10 ( V_42 ) || F_10 ( V_43 )
F_11 ( T_1 ) ;
#endif
F_2 ( & V_3 ) ;
T_1 -> V_5 = V_4 ;
V_4 = T_1 ;
F_4 ( & V_3 ) ;
F_12 () ;
}
void F_13 ( struct V_8 * V_6 )
{
T_1 * V_44 , * T_1 ;
if ( ( T_1 = F_14 ( V_6 ) ) == NULL )
return;
F_8 () ;
F_2 ( & V_3 ) ;
#ifdef V_42
F_15 ( T_1 ) ;
#endif
for ( V_44 = V_4 ; V_44 != NULL ; V_44 = V_44 -> V_5 )
if ( V_44 -> V_12 == V_6 )
V_44 -> V_12 = NULL ;
if ( ( V_44 = V_4 ) == T_1 ) {
V_4 = V_44 -> V_5 ;
F_4 ( & V_3 ) ;
F_16 ( V_6 ) ;
F_17 ( T_1 ) ;
F_12 () ;
return;
}
while ( V_44 != NULL && V_44 -> V_5 != NULL ) {
if ( V_44 -> V_5 == T_1 ) {
V_44 -> V_5 = T_1 -> V_5 ;
F_4 ( & V_3 ) ;
F_16 ( V_6 ) ;
F_17 ( T_1 ) ;
F_12 () ;
return;
}
V_44 = V_44 -> V_5 ;
}
F_4 ( & V_3 ) ;
V_6 -> V_11 = NULL ;
F_12 () ;
}
int F_18 ( unsigned int V_45 , struct V_46 * V_47 )
{
T_1 * T_1 , * V_48 ;
if ( ( T_1 = F_1 ( & V_47 -> V_49 ) ) == NULL )
return - V_50 ;
switch ( V_45 ) {
case V_51 :
if ( ( V_48 = F_1 ( & V_47 -> V_52 ) ) == NULL )
return - V_50 ;
if ( T_1 -> V_12 != NULL )
return - V_50 ;
T_1 -> V_12 = V_48 -> V_6 ;
break;
case V_53 :
if ( T_1 -> V_12 == NULL )
return - V_50 ;
T_1 -> V_12 = NULL ;
break;
default:
return - V_50 ;
}
return 0 ;
}
struct V_8 * F_19 ( struct V_8 * V_6 )
{
T_1 * T_1 ;
if ( ( T_1 = F_14 ( V_6 ) ) == NULL )
return V_6 ;
if ( T_1 -> V_12 == NULL )
return V_6 ;
return T_1 -> V_12 ;
}
void T_3 F_20 ( void )
{
T_1 * V_44 , * T_1 ;
F_2 ( & V_3 ) ;
T_1 = V_4 ;
while ( T_1 != NULL ) {
V_44 = T_1 ;
F_16 ( T_1 -> V_6 ) ;
T_1 = T_1 -> V_5 ;
F_17 ( V_44 ) ;
}
V_4 = NULL ;
F_4 ( & V_3 ) ;
}
