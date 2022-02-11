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
F_8 ( L_2 ,
V_10 -> V_20 -> V_21 . V_22 , V_11 ) ;
return V_11 ;
}
static int F_9 ( struct V_8 * V_8 , struct V_9 * V_10 )
{
F_8 ( L_3 , V_10 -> V_20 -> V_21 . V_22 ) ;
F_10 ( V_10 -> V_19 ) ;
V_10 -> V_19 = NULL ;
F_11 () ;
F_7 ( V_17 ) ;
return 0 ;
}
static T_2 F_12 ( struct V_9 * V_10 , T_2 V_23 , int V_24 )
{
switch ( V_24 ) {
case V_25 :
V_23 += V_10 -> V_26 ;
break;
case V_27 :
break;
case V_28 :
if ( V_10 -> V_19 ) {
F_10 ( V_10 -> V_19 ) ;
V_10 -> V_19 = NULL ;
}
break;
default:
return - V_14 ;
}
if ( V_23 < 0 )
return - V_14 ;
if ( V_10 -> V_26 != V_23 )
++ V_10 -> V_29 ;
V_10 -> V_26 = V_23 ;
return V_23 ;
}
static T_3 F_13 ( char T_4 * V_30 , T_2 V_31 ,
char T_5 * V_32 , T_6 V_33 )
{
T_3 V_34 ;
unsigned V_35 = V_36 ;
do {
V_34 = F_14 ( V_30 , V_31 , V_32 , V_33 ) ;
if ( V_34 != - V_37 )
break;
F_15 ( V_38 ) ;
} while ( -- V_35 > 0 );
return V_34 ;
}
static T_3 F_16 ( struct V_9 * V_10 , char T_5 * V_39 ,
T_6 V_33 , T_2 * V_23 )
{
T_3 V_34 ;
if ( ( ( V_10 -> V_12 & V_15 ) == V_40 ) ||
( V_10 -> V_19 == NULL ) ) {
return - V_41 ;
}
V_34 = F_13 ( ( char * ) V_10 -> V_19 ,
* V_23 , V_39 , V_33 ) ;
F_8 ( L_4 ,
V_10 -> V_20 -> V_21 . V_22 , ( long long ) * V_23 , V_34 , V_33 ) ;
if ( V_34 > 0 )
* V_23 += V_34 ;
return V_34 ;
}
static T_3 F_17 ( struct V_9 * V_10 , const char T_5 * V_39 ,
T_6 V_33 , T_2 * V_23 )
{
T_3 V_34 ;
F_8 ( L_5 ,
V_10 -> V_20 -> V_21 . V_22 , ( long long ) * V_23 , V_33 ) ;
if ( ! V_10 -> V_19 ) {
V_10 -> V_19 = F_18 ( V_33 + 1 , V_6 ) ;
if ( ! V_10 -> V_19 )
return - V_42 ;
if ( ! F_19 ( V_10 -> V_19 , V_39 , V_33 ) ) {
( ( char * ) V_10 -> V_19 ) [ V_33 ] = '\0' ;
return V_33 ;
}
F_10 ( V_10 -> V_19 ) ;
V_10 -> V_19 = NULL ;
return - V_43 ;
}
V_34 = F_13 ( ( char * ) V_10 -> V_19 ,
* V_23 , ( char T_5 * ) V_39 , V_33 ) ;
if ( V_34 > 0 )
* V_23 += V_34 ;
F_8 ( L_6 ,
V_10 -> V_20 -> V_21 . V_22 , V_34 ) ;
return V_34 ;
}
int F_20 ( void )
{
int V_11 ;
#ifdef F_21
struct V_1 * V_2 ;
V_11 = F_22 ( & V_44 , 0 , 1 , V_45 ) ;
if ( V_11 )
goto V_46;
F_23 ( & V_7 . V_2 , & V_47 ) ;
V_7 . V_2 . V_48 = V_17 ;
V_11 = F_24 ( & V_7 . V_2 , V_44 , 1 ) ;
if ( V_11 )
goto V_49;
V_50 = F_25 ( V_17 , F_21 ) ;
if ( F_26 ( V_50 ) ) {
V_11 = F_27 ( V_50 ) ;
goto V_51;
}
V_7 . V_3 = 0 ;
V_50 -> V_52 = F_1 ;
V_2 = F_28 ( V_50 , NULL , V_44 , NULL ,
L_1 , V_45 ) ;
if ( ! F_26 ( V_2 ) )
return 0 ;
V_11 = F_27 ( V_2 ) ;
F_29 ( V_50 ) ;
V_50 = NULL ;
V_51:
F_30 ( & V_7 . V_2 ) ;
V_49:
F_31 ( V_44 , 1 ) ;
V_46:
#else
V_7 . V_2 . V_53 = V_54 ;
V_7 . V_2 . V_22 = V_45 ;
V_7 . V_2 . V_55 = & V_47 ;
V_7 . V_2 . V_3 = 0 ;
V_11 = F_32 ( & V_7 . V_2 ) ;
#endif
return V_11 ;
}
void F_33 ( void )
{
#ifdef F_21
if ( ! F_34 ( V_50 ) ) {
F_35 ( V_50 , V_44 ) ;
F_29 ( V_50 ) ;
}
F_30 ( & V_7 . V_2 ) ;
F_31 ( V_44 , 1 ) ;
#else
F_36 ( & V_7 . V_2 ) ;
#endif
}
