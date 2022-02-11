void * F_1 ( unsigned int V_1 , int type )
{
struct V_2 * V_3 ;
void * V_4 ;
if ( V_1 >= F_2 ( V_5 ) )
return NULL ;
F_3 ( & V_6 ) ;
V_3 = V_5 [ V_1 ] ;
if ( V_3 && V_3 -> type == type ) {
V_4 = V_3 -> V_4 ;
if ( V_4 && V_3 -> V_7 )
F_4 ( & V_3 -> V_7 -> V_8 ) ;
} else
V_4 = NULL ;
F_5 ( & V_6 ) ;
return V_4 ;
}
static int F_6 ( int type , struct V_9 * V_10 , int V_11 )
{
int V_1 ;
switch ( type ) {
case V_12 :
if ( F_7 ( ! V_10 || V_11 < 0 || V_11 > 1 ) )
return - V_13 ;
V_1 = F_8 ( V_10 -> V_14 , ( V_11 ? V_15 : V_16 ) ) ;
break;
case V_17 :
V_1 = V_18 ;
break;
case V_19 :
V_1 = V_20 ;
break;
case V_21 :
if ( F_7 ( ! V_10 || V_11 < 0 || V_11 > 1 ) )
return - V_13 ;
V_1 = F_8 ( V_10 -> V_14 , ( V_11 ? V_22 : V_23 ) ) ;
break;
case V_24 :
if ( F_7 ( ! V_10 || V_11 < 0 || V_11 > 1 ) )
return - V_13 ;
V_1 = F_8 ( V_10 -> V_14 , ( V_11 ? V_25 : V_26 ) ) ;
break;
case V_27 :
V_1 = F_8 ( V_10 -> V_14 , V_28 ) ;
break;
case V_29 :
V_1 = V_30 ;
break;
default:
return - V_13 ;
}
if ( V_1 < 0 || V_1 >= V_31 )
return - V_13 ;
return V_1 ;
}
int F_9 ( int type , struct V_9 * V_10 , int V_11 ,
const struct V_32 * V_33 , void * V_4 )
{
int V_1 = F_6 ( type , V_10 , V_11 ) ;
int V_34 ;
struct V_2 * V_35 ;
int V_36 = F_10 ( V_1 ) ;
int V_37 = - 1 ;
int V_38 = - 1 , V_39 = - 1 ;
struct V_40 * V_41 = F_11 ( V_10 ) ;
if ( V_10 && V_10 -> V_14 >= V_42 )
return 0 ;
if ( V_1 < 0 )
return V_1 ;
V_35 = F_12 ( sizeof( struct V_2 ) , V_43 ) ;
if ( V_35 == NULL )
return - V_44 ;
V_35 -> type = type ;
V_35 -> V_10 = V_10 ? V_10 -> V_14 : - 1 ;
V_35 -> V_40 = V_11 ;
V_35 -> V_33 = V_33 ;
V_35 -> V_4 = V_4 ;
V_35 -> V_7 = V_10 ;
F_3 ( & V_6 ) ;
V_5 [ V_1 ] = V_35 ;
V_34 = F_13 ( V_1 ) ;
switch ( V_34 ) {
case V_23 :
V_37 = F_8 ( V_36 , V_45 ) ;
break;
case V_26 :
V_37 = F_8 ( V_36 , V_46 ) ;
break;
case V_25 :
V_37 = F_8 ( V_36 , V_47 ) ;
break;
}
V_38 = F_14 ( V_33 , V_1 , V_41 ) ;
if ( V_38 != V_1 )
goto V_48;
if ( V_37 >= 0 ) {
V_39 = F_14 ( V_33 , V_37 ,
V_41 ) ;
if ( V_39 != V_37 )
goto V_48;
V_5 [ V_37 ] = V_35 ;
}
F_5 ( & V_6 ) ;
return 0 ;
V_48:
if ( V_39 >= 0 )
F_15 ( V_39 ) ;
if ( V_38 >= 0 )
F_15 ( V_38 ) ;
V_5 [ V_1 ] = NULL ;
F_5 ( & V_6 ) ;
F_16 ( V_35 ) ;
return - V_49 ;
}
int F_17 ( int type , struct V_9 * V_10 , int V_11 )
{
int V_1 = F_6 ( type , V_10 , V_11 ) ;
int V_36 = F_10 ( V_1 ) ;
int V_37 = - 1 ;
struct V_2 * V_50 ;
if ( V_10 && V_10 -> V_14 >= V_42 )
return 0 ;
if ( V_1 < 0 )
return V_1 ;
F_3 ( & V_6 ) ;
V_50 = V_5 [ V_1 ] ;
if ( V_50 == NULL ) {
F_5 ( & V_6 ) ;
return - V_51 ;
}
F_15 ( V_1 ) ;
switch ( F_13 ( V_1 ) ) {
case V_23 :
V_37 = F_8 ( V_36 , V_45 ) ;
break;
case V_26 :
V_37 = F_8 ( V_36 , V_46 ) ;
break;
case V_25 :
V_37 = F_8 ( V_36 , V_47 ) ;
break;
}
if ( V_37 >= 0 ) {
F_15 ( V_37 ) ;
V_5 [ V_37 ] = NULL ;
}
V_5 [ V_1 ] = NULL ;
F_5 ( & V_6 ) ;
F_16 ( V_50 ) ;
return 0 ;
}
static const char * F_18 ( int type )
{
switch ( type ) {
case V_12 :
return L_1 ;
case V_17 :
case V_19 :
return L_2 ;
case V_21 :
return L_3 ;
case V_24 :
return L_4 ;
case V_27 :
return L_5 ;
default:
return L_6 ;
}
}
static void F_19 ( struct V_52 * V_53 ,
struct V_54 * V_55 )
{
int V_1 ;
struct V_2 * V_50 ;
F_3 ( & V_6 ) ;
for ( V_1 = 0 ; V_1 < V_31 ; ++ V_1 ) {
if ( ! ( V_50 = V_5 [ V_1 ] ) )
continue;
if ( V_50 -> V_10 >= 0 )
F_20 ( V_55 , L_7 , V_1 ,
V_50 -> V_10 , V_50 -> V_40 ,
F_18 ( V_50 -> type ) ) ;
else
F_20 ( V_55 , L_8 , V_1 ,
F_18 ( V_50 -> type ) ) ;
}
F_5 ( & V_6 ) ;
}
int T_1 F_21 ( void )
{
struct V_52 * V_53 ;
V_53 = F_22 ( V_56 , L_9 , V_57 ) ;
if ( ! V_53 )
return - V_44 ;
V_53 -> V_58 . V_59 . V_60 = F_19 ;
return F_23 ( V_53 ) ;
}
