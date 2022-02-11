void * F_1 ( unsigned int V_1 , int type )
{
struct V_2 * V_3 ;
void * V_4 ;
if ( V_1 >= F_2 ( V_5 ) )
return NULL ;
F_3 ( & V_6 ) ;
V_3 = V_5 [ V_1 ] ;
if ( V_3 && V_3 -> type == type )
V_4 = V_3 -> V_4 ;
else
V_4 = NULL ;
F_4 ( & V_6 ) ;
return V_4 ;
}
static int F_5 ( int type , struct V_7 * V_8 , int V_9 )
{
int V_1 ;
switch ( type ) {
case V_10 :
if ( F_6 ( ! V_8 || V_9 < 0 || V_9 > 1 ) )
return - V_11 ;
V_1 = F_7 ( V_8 -> V_12 , ( V_9 ? V_13 : V_14 ) ) ;
break;
case V_15 :
V_1 = V_16 ;
break;
case V_17 :
V_1 = V_18 ;
break;
case V_19 :
if ( F_6 ( ! V_8 || V_9 < 0 || V_9 > 1 ) )
return - V_11 ;
V_1 = F_7 ( V_8 -> V_12 , ( V_9 ? V_20 : V_21 ) ) ;
break;
case V_22 :
if ( F_6 ( ! V_8 || V_9 < 0 || V_9 > 1 ) )
return - V_11 ;
V_1 = F_7 ( V_8 -> V_12 , ( V_9 ? V_23 : V_24 ) ) ;
break;
case V_25 :
V_1 = F_7 ( V_8 -> V_12 , V_26 ) ;
break;
case V_27 :
V_1 = V_28 ;
break;
default:
return - V_11 ;
}
if ( V_1 < 0 || V_1 >= V_29 )
return - V_11 ;
return V_1 ;
}
int F_8 ( int type , struct V_7 * V_8 , int V_9 ,
const struct V_30 * V_31 , void * V_4 ,
const char * V_32 )
{
int V_1 = F_5 ( type , V_8 , V_9 ) ;
int V_33 ;
struct V_2 * V_34 ;
int V_35 = F_9 ( V_1 ) ;
int V_36 = - 1 ;
int V_37 = - 1 , V_38 = - 1 ;
struct V_39 * V_40 = F_10 ( V_8 ) ;
if ( V_8 && V_8 -> V_12 >= 8 )
return 0 ;
if ( V_1 < 0 )
return V_1 ;
V_34 = F_11 ( sizeof( struct V_2 ) , V_41 ) ;
if ( V_34 == NULL )
return - V_42 ;
V_34 -> type = type ;
V_34 -> V_8 = V_8 ? V_8 -> V_12 : - 1 ;
V_34 -> V_39 = V_9 ;
V_34 -> V_31 = V_31 ;
V_34 -> V_4 = V_4 ;
F_3 ( & V_6 ) ;
V_5 [ V_1 ] = V_34 ;
V_33 = F_12 ( V_1 ) ;
switch ( V_33 ) {
case V_21 :
V_36 = F_7 ( V_35 , V_43 ) ;
break;
case V_24 :
V_36 = F_7 ( V_35 , V_44 ) ;
break;
case V_23 :
V_36 = F_7 ( V_35 , V_45 ) ;
break;
}
V_37 = F_13 ( V_31 , V_1 , V_40 ) ;
if ( V_37 != V_1 )
goto V_46;
if ( V_36 >= 0 ) {
V_38 = F_13 ( V_31 , V_36 ,
V_40 ) ;
if ( V_38 != V_36 )
goto V_46;
V_5 [ V_36 ] = V_34 ;
}
F_4 ( & V_6 ) ;
return 0 ;
V_46:
if ( V_38 >= 0 )
F_14 ( V_38 ) ;
if ( V_37 >= 0 )
F_14 ( V_37 ) ;
V_5 [ V_1 ] = NULL ;
F_4 ( & V_6 ) ;
F_15 ( V_34 ) ;
return - V_47 ;
}
int F_16 ( int type , struct V_7 * V_8 , int V_9 )
{
int V_1 = F_5 ( type , V_8 , V_9 ) ;
int V_35 = F_9 ( V_1 ) ;
int V_36 = - 1 ;
struct V_2 * V_48 ;
if ( V_8 && V_8 -> V_12 >= 8 )
return 0 ;
if ( V_1 < 0 )
return V_1 ;
F_3 ( & V_6 ) ;
V_48 = V_5 [ V_1 ] ;
if ( V_48 == NULL ) {
F_4 ( & V_6 ) ;
return - V_49 ;
}
F_14 ( V_1 ) ;
switch ( F_12 ( V_1 ) ) {
case V_21 :
V_36 = F_7 ( V_35 , V_43 ) ;
break;
case V_24 :
V_36 = F_7 ( V_35 , V_44 ) ;
break;
case V_23 :
V_36 = F_7 ( V_35 , V_45 ) ;
break;
}
if ( V_36 >= 0 ) {
F_14 ( V_36 ) ;
V_5 [ V_36 ] = NULL ;
}
V_5 [ V_1 ] = NULL ;
F_4 ( & V_6 ) ;
F_15 ( V_48 ) ;
return 0 ;
}
static const char * F_17 ( int type )
{
switch ( type ) {
case V_10 :
return L_1 ;
case V_15 :
case V_17 :
return L_2 ;
case V_19 :
return L_3 ;
case V_22 :
return L_4 ;
case V_25 :
return L_5 ;
default:
return L_6 ;
}
}
static void F_18 ( struct V_50 * V_51 ,
struct V_52 * V_53 )
{
int V_1 ;
struct V_2 * V_48 ;
F_3 ( & V_6 ) ;
for ( V_1 = 0 ; V_1 < V_29 ; ++ V_1 ) {
if ( ! ( V_48 = V_5 [ V_1 ] ) )
continue;
if ( V_48 -> V_8 >= 0 )
F_19 ( V_53 , L_7 , V_1 ,
V_48 -> V_8 , V_48 -> V_39 ,
F_17 ( V_48 -> type ) ) ;
else
F_19 ( V_53 , L_8 , V_1 ,
F_17 ( V_48 -> type ) ) ;
}
F_4 ( & V_6 ) ;
}
int T_1 F_20 ( void )
{
struct V_50 * V_51 ;
V_51 = F_21 ( V_54 , L_9 , V_55 ) ;
if ( V_51 ) {
V_51 -> V_56 . V_57 . V_58 = F_18 ;
if ( F_22 ( V_51 ) < 0 ) {
F_23 ( V_51 ) ;
V_51 = NULL ;
}
}
V_59 = V_51 ;
return 0 ;
}
int T_2 F_24 ( void )
{
F_23 ( V_59 ) ;
return 0 ;
}
