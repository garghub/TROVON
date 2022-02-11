const char * F_1 ( struct V_1 * V_2 )
{
switch ( V_2 -> V_3 ) {
case V_4 :
return L_1 ;
case V_5 :
return L_2 ;
case V_6 :
return L_3 ;
case V_7 :
return L_4 ;
case V_8 :
return L_5 ;
case V_9 :
return L_6 ;
case V_10 :
return L_7 ;
default:
return L_8 ;
}
}
struct V_1 * F_2 ( struct V_11 * V_12 , int V_3 ,
void T_1 * V_13 )
{
struct V_1 * V_2 = NULL ;
switch ( V_3 & V_14 ) {
case V_15 :
V_2 = F_3 ( V_12 , V_3 ) ;
break;
case V_16 :
V_2 = F_4 ( V_12 ) ;
break;
}
if ( ! V_2 ) {
F_5 ( L_9 ) ;
return NULL ;
}
V_2 -> V_3 = V_3 ;
V_2 -> V_12 = V_12 ;
V_2 -> V_17 = V_13 ;
V_2 -> V_18 -> V_19 ( V_2 ) ;
F_6 ( L_10 , F_1 ( V_2 ) ) ;
return V_2 ;
}
int F_7 ( struct V_1 * V_2 , struct V_20 * V_21 ,
struct V_22 * V_23 , int V_24 ,
int V_25 , int V_26 , int V_27 , int V_28 ,
int V_29 , int V_30 , int V_31 , int V_32 )
{
int V_33 ;
unsigned int V_34 ;
struct V_35 * V_36 ;
if ( ! V_2 || ! V_21 || ! V_23 ) {
F_5 ( L_11 ) ;
return 1 ;
}
V_36 = F_8 ( V_21 , 0 ) ;
if ( ! V_36 ) {
F_5 ( L_12 ) ;
return 1 ;
}
V_2 -> V_21 = V_21 ;
V_2 -> V_23 = V_23 ;
V_2 -> V_24 = V_24 ;
V_2 -> V_37 = V_25 ;
V_2 -> V_38 = V_26 ;
V_2 -> V_39 = F_9 ( V_27 , 0 , V_23 -> V_40 - V_25 ) ;
V_2 -> V_41 = F_9 ( V_28 , 0 , V_23 -> V_42 - V_26 ) ;
V_2 -> V_29 = V_29 ;
V_2 -> V_30 = V_30 ;
V_2 -> V_31 = V_31 ;
V_2 -> V_32 = V_32 ;
V_2 -> V_43 = V_21 -> V_44 ;
V_2 -> V_45 = V_36 -> V_45 ;
for ( V_34 = 0 ; V_34 < 4 ; V_34 ++ ) {
V_2 -> V_46 [ V_34 ] = V_21 -> V_46 [ V_34 ] ;
V_2 -> V_47 [ V_34 ] = V_21 -> V_47 [ V_34 ] ;
}
F_6 ( L_13 ,
F_1 ( V_2 ) ,
V_2 -> V_24 ) ;
F_6 ( L_14 ,
F_1 ( V_2 ) ,
V_2 -> V_39 , V_2 -> V_41 , V_2 -> V_37 , V_2 -> V_38 ,
V_2 -> V_31 , V_2 -> V_32 , V_2 -> V_29 ,
V_2 -> V_30 ) ;
F_6 ( L_15 , V_21 -> V_48 . V_49 ,
( char * ) & V_2 -> V_43 , ( unsigned long ) V_2 -> V_45 ) ;
if ( ! V_2 -> V_18 -> V_50 )
goto V_51;
V_33 = V_2 -> V_18 -> V_50 ( V_2 , ! V_2 -> V_52 ) ;
if ( ! V_33 )
V_2 -> V_52 = true ;
return V_33 ;
V_51:
F_5 ( L_16 ) ;
return 1 ;
}
int F_10 ( struct V_1 * V_2 )
{
if ( ! V_2 )
return 1 ;
if ( ! V_2 -> V_18 -> V_53 )
goto V_54;
return V_2 -> V_18 -> V_53 ( V_2 ) ;
V_54:
F_5 ( L_17 ) ;
return 1 ;
}
int F_11 ( struct V_1 * V_2 )
{
int V_33 ;
F_6 ( L_18 , F_1 ( V_2 ) ) ;
if ( ! V_2 )
return 1 ;
if ( ! V_2 -> V_52 )
return 0 ;
if ( ! V_2 -> V_18 -> V_55 )
goto V_56;
V_33 = V_2 -> V_18 -> V_55 ( V_2 ) ;
if ( ! V_33 )
V_2 -> V_52 = false ;
else
F_5 ( L_19 ) ;
return V_33 ;
V_56:
F_5 ( L_20 ) ;
return 1 ;
}
const T_2 * F_12 ( struct V_1 * V_2 )
{
if ( ! V_2 )
return NULL ;
if ( ! V_2 -> V_18 -> V_57 )
return NULL ;
return V_2 -> V_18 -> V_57 ( V_2 ) ;
}
unsigned int F_13 ( struct V_1 * V_2 )
{
if ( ! V_2 )
return 0 ;
if ( ! V_2 -> V_18 -> V_58 )
return 0 ;
return V_2 -> V_18 -> V_58 ( V_2 ) ;
}
