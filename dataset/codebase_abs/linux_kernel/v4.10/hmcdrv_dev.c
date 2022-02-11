static char * F_1 ( struct V_1 * V_2 , T_1 * V_3 )
{
char * V_4 = NULL ;
const char * V_5 = F_2 ( V_2 ) ;
if ( V_5 )
V_4 = F_3 ( V_6 , L_1 , V_5 ) ;
if ( V_3 )
* V_3 = V_7 . V_3 ;
return V_4 ;
}
static int F_4 ( struct V_8 * V_8 , struct V_9 * V_10 )
{
int V_11 ;
if ( V_10 -> V_12 & V_13 )
return - V_14 ;
if ( ( V_10 -> V_12 & V_15 ) == V_16 )
return - V_14 ;
if ( ! F_5 ( V_17 ) )
return - V_18 ;
V_10 -> V_19 = NULL ;
V_11 = F_6 () ;
if ( V_11 )
F_7 ( V_17 ) ;
F_8 ( L_2 , V_10 , V_11 ) ;
return V_11 ;
}
static int F_9 ( struct V_8 * V_8 , struct V_9 * V_10 )
{
F_8 ( L_3 , V_10 ) ;
F_10 ( V_10 -> V_19 ) ;
V_10 -> V_19 = NULL ;
F_11 () ;
F_7 ( V_17 ) ;
return 0 ;
}
static T_2 F_12 ( struct V_9 * V_10 , T_2 V_20 , int V_21 )
{
switch ( V_21 ) {
case V_22 :
V_20 += V_10 -> V_23 ;
break;
case V_24 :
break;
case V_25 :
if ( V_10 -> V_19 ) {
F_10 ( V_10 -> V_19 ) ;
V_10 -> V_19 = NULL ;
}
break;
default:
return - V_14 ;
}
if ( V_20 < 0 )
return - V_14 ;
if ( V_10 -> V_23 != V_20 )
++ V_10 -> V_26 ;
V_10 -> V_23 = V_20 ;
return V_20 ;
}
static T_3 F_13 ( char T_4 * V_27 , T_2 V_28 ,
char T_5 * V_29 , T_6 V_30 )
{
T_3 V_31 ;
unsigned V_32 = V_33 ;
do {
V_31 = F_14 ( V_27 , V_28 , V_29 , V_30 ) ;
if ( V_31 != - V_34 )
break;
F_15 ( V_35 ) ;
} while ( -- V_32 > 0 );
return V_31 ;
}
static T_3 F_16 ( struct V_9 * V_10 , char T_5 * V_36 ,
T_6 V_30 , T_2 * V_20 )
{
T_3 V_31 ;
if ( ( ( V_10 -> V_12 & V_15 ) == V_37 ) ||
( V_10 -> V_19 == NULL ) ) {
return - V_38 ;
}
V_31 = F_13 ( ( char * ) V_10 -> V_19 ,
* V_20 , V_36 , V_30 ) ;
F_8 ( L_4 ,
V_10 , ( long long ) * V_20 , V_31 , V_30 ) ;
if ( V_31 > 0 )
* V_20 += V_31 ;
return V_31 ;
}
static T_3 F_17 ( struct V_9 * V_10 , const char T_5 * V_36 ,
T_6 V_30 , T_2 * V_20 )
{
T_3 V_31 ;
F_8 ( L_5 ,
V_10 , ( long long ) * V_20 , V_30 ) ;
if ( ! V_10 -> V_19 ) {
V_10 -> V_19 = F_18 ( V_30 + 1 , V_6 ) ;
if ( ! V_10 -> V_19 )
return - V_39 ;
if ( ! F_19 ( V_10 -> V_19 , V_36 , V_30 ) ) {
( ( char * ) V_10 -> V_19 ) [ V_30 ] = '\0' ;
return V_30 ;
}
F_10 ( V_10 -> V_19 ) ;
V_10 -> V_19 = NULL ;
return - V_40 ;
}
V_31 = F_13 ( ( char * ) V_10 -> V_19 ,
* V_20 , ( char T_5 * ) V_36 , V_30 ) ;
if ( V_31 > 0 )
* V_20 += V_31 ;
F_8 ( L_6 , V_10 , V_31 ) ;
return V_31 ;
}
int F_20 ( void )
{
int V_11 ;
#ifdef F_21
struct V_1 * V_2 ;
V_11 = F_22 ( & V_41 , 0 , 1 , V_42 ) ;
if ( V_11 )
goto V_43;
F_23 ( & V_7 . V_2 , & V_44 ) ;
V_7 . V_2 . V_45 = V_17 ;
V_11 = F_24 ( & V_7 . V_2 , V_41 , 1 ) ;
if ( V_11 )
goto V_46;
V_47 = F_25 ( V_17 , F_21 ) ;
if ( F_26 ( V_47 ) ) {
V_11 = F_27 ( V_47 ) ;
goto V_48;
}
V_7 . V_3 = 0 ;
V_47 -> V_49 = F_1 ;
V_2 = F_28 ( V_47 , NULL , V_41 , NULL ,
L_1 , V_42 ) ;
if ( ! F_26 ( V_2 ) )
return 0 ;
V_11 = F_27 ( V_2 ) ;
F_29 ( V_47 ) ;
V_47 = NULL ;
V_48:
F_30 ( & V_7 . V_2 ) ;
V_46:
F_31 ( V_41 , 1 ) ;
V_43:
#else
V_7 . V_2 . V_50 = V_51 ;
V_7 . V_2 . V_52 = V_42 ;
V_7 . V_2 . V_53 = & V_44 ;
V_7 . V_2 . V_3 = 0 ;
V_11 = F_32 ( & V_7 . V_2 ) ;
#endif
return V_11 ;
}
void F_33 ( void )
{
#ifdef F_21
if ( ! F_34 ( V_47 ) ) {
F_35 ( V_47 , V_41 ) ;
F_29 ( V_47 ) ;
}
F_30 ( & V_7 . V_2 ) ;
F_31 ( V_41 , 1 ) ;
#else
F_36 ( & V_7 . V_2 ) ;
#endif
}
