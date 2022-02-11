static T_1 * F_1 ( void )
{
T_1 * V_1 = NULL ;
struct V_2 * V_3 ;
struct V_2 * V_4 ;
int V_5 ;
char V_6 [ V_7 ] ;
if ( F_2 ( & V_3 ) ) {
goto V_8;
}
for ( V_4 = V_3 ; V_4 != NULL ; V_4 = V_4 -> V_9 ) {
if ( V_4 -> V_10 == NULL )
continue;
V_5 = V_4 -> V_10 -> V_11 ;
memset ( V_6 , 0x0 , V_7 ) ;
switch ( V_5 ) {
case V_12 :
{
struct V_13 * V_14 = (struct V_13 * ) V_4 -> V_10 ;
F_3 ( & V_14 -> V_15 , V_6 , sizeof( V_6 ) ) ;
break;
}
case V_16 :
{
struct V_17 * V_18 = (struct V_17 * ) V_4 -> V_10 ;
F_4 ( & V_18 -> V_19 , V_6 , sizeof( V_6 ) ) ;
break;
}
default:
break;
}
if ( ! F_5 ( V_6 , L_1 ) || ! F_5 ( V_6 , L_2 ) )
continue;
if ( * V_6 ) {
V_1 = F_6 ( V_1 , F_7 ( V_6 ) ) ;
}
}
F_8 ( V_3 ) ;
V_8:
return V_1 ;
}
static T_1 * F_9 ( void )
{
T_1 * V_1 = NULL ;
T_2 V_20 = NULL ;
T_3 V_21 = V_22 ;
T_3 V_5 = V_23 ;
T_2 V_24 = NULL ;
T_4 V_25 = NULL ;
char V_6 [ 100 ] ;
T_5 V_26 = 100 ;
V_20 = ( V_27 * ) F_10 ( V_21 ) ;
if ( V_20 == NULL )
return NULL ;
if ( F_11 ( V_5 , 0 , NULL , V_20 , & V_21 ) != V_28 )
goto V_8;
V_24 = V_20 ;
while ( V_24 ) {
for ( V_25 = V_24 -> V_29 ; V_25 != NULL ; V_25 = V_25 -> V_30 ) {
if ( V_25 -> V_31 . V_32 -> V_11 == V_12 ) {
T_6 * V_33 = ( T_6 * ) V_25 -> V_31 . V_32 ;
F_3 ( & ( V_33 -> V_15 ) , V_6 , V_26 ) ;
if ( ! F_5 ( V_6 , L_1 ) )
continue;
if ( * V_6 )
V_1 = F_6 ( V_1 , F_7 ( V_6 ) ) ;
}
if ( V_25 -> V_31 . V_32 -> V_11 == V_16 ) {
T_7 * V_34 = ( T_7 * ) V_25 -> V_31 . V_32 ;
F_4 ( & ( V_34 -> V_19 ) , V_6 , V_26 ) ;
if ( ! F_5 ( V_6 , L_2 ) )
continue;
if ( * V_6 )
V_1 = F_6 ( V_1 , F_7 ( V_6 ) ) ;
}
}
V_24 = V_24 -> V_30 ;
}
V_8:
if ( V_20 )
F_12 ( V_20 ) ;
return V_1 ;
}
T_1 * F_13 ( void )
{
#if F_14 ( V_35 )
return F_9 () ;
#elif F_14 ( V_36 )
return F_1 () ;
#else
return NULL ;
#endif
}
