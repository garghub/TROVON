const T_1 * F_1 ( T_2 * V_1 )
{
return V_1 -> V_2 ;
}
T_2 * F_2 ( void )
{
T_2 * V_1 ;
V_1 = F_3 () ;
if ( V_1 )
{
V_1 -> V_2 = F_4 ( V_3 ) ;
F_5 ( V_1 , 0 ) ;
}
return V_1 ;
}
T_3 * F_6 ( T_2 * V_1 )
{
T_4 * * V_4 = F_7 ( V_1 ) ;
if ( ! V_4 )
return NULL ;
if ( ! * V_4 )
return F_8 ( F_9 () ) ;
if ( ! * V_4 || ( ( * V_4 ) -> V_5 == V_6 ) )
return F_8 ( F_10 () ) ;
return F_11 ( ( * V_4 ) -> V_7 , ( * V_4 ) -> V_8 ) ;
}
T_3 * F_12 ( T_2 * V_1 , T_3 * V_9 )
{
T_3 * V_10 , * V_11 ;
if ( V_9 )
V_11 = V_9 ;
else
V_11 = F_6 ( V_1 ) ;
if ( ! V_11 )
{
F_13 ( V_12 , V_13 ) ;
return NULL ;
}
switch ( F_14 ( V_1 -> V_2 ) )
{
case V_3 :
return V_11 ;
case V_14 :
V_10 = F_15 ( V_1 ) ;
break;
case V_15 :
V_10 = F_16 ( V_1 ) ;
break;
#ifdef F_17
case V_16 :
V_10 = F_18 ( V_1 ) ;
break;
#endif
case V_17 :
V_10 = F_19 ( V_1 ) ;
break;
case V_18 :
V_10 = F_20 ( V_1 ) ;
break;
default:
F_13 ( V_12 , V_19 ) ;
return NULL ;
}
if ( V_10 )
return F_21 ( V_10 , V_11 ) ;
if ( ! V_9 )
F_22 ( V_11 ) ;
return NULL ;
}
int F_23 ( T_2 * V_1 , T_3 * V_10 )
{
T_4 * * V_4 = F_7 ( V_1 ) ;
if ( ! V_4 )
return 0 ;
if ( * V_4 && ( ( * V_4 ) -> V_5 & V_6 ) )
{
T_3 * V_20 ;
unsigned char * V_11 ;
long V_21 ;
V_20 = F_24 ( V_10 , V_22 ) ;
if ( ! V_20 )
{
F_13 ( V_23 , V_24 ) ;
return 0 ;
}
V_21 = F_25 ( V_20 , & V_11 ) ;
F_26 ( V_20 , V_25 ) ;
F_27 ( V_20 , 0 ) ;
F_28 ( * V_4 , V_11 , V_21 ) ;
( * V_4 ) -> V_5 &= ~ V_6 ;
}
switch ( F_14 ( V_1 -> V_2 ) )
{
case V_3 :
case V_18 :
case V_17 :
case V_16 :
return 1 ;
case V_14 :
return F_29 ( V_1 , V_10 ) ;
case V_15 :
return F_30 ( V_1 , V_10 , 0 ) ;
default:
F_13 ( V_23 , V_19 ) ;
return 0 ;
}
}
T_4 * * F_7 ( T_2 * V_1 )
{
switch ( F_14 ( V_1 -> V_2 ) )
{
case V_3 :
return & V_1 -> V_26 . V_7 ;
case V_14 :
return & V_1 -> V_26 . V_27 -> V_28 -> V_29 ;
case V_18 :
return & V_1 -> V_26 . V_30 -> V_31 -> V_32 ;
case V_15 :
return & V_1 -> V_26 . V_33 -> V_28 -> V_29 ;
case V_17 :
return & V_1 -> V_26 . V_34 -> V_31 -> V_32 ;
case V_35 :
return & V_1 -> V_26 . V_36 -> V_28 -> V_29 ;
case V_16 :
return & V_1 -> V_26 . V_37 -> V_28 -> V_29 ;
default:
if ( V_1 -> V_26 . V_38 -> type == V_39 )
return & V_1 -> V_26 . V_38 -> V_40 . V_41 ;
F_13 ( V_42 , V_43 ) ;
return NULL ;
}
}
static T_1 * * F_31 ( T_2 * V_1 )
{
switch ( F_14 ( V_1 -> V_2 ) )
{
case V_14 :
return & V_1 -> V_26 . V_27 -> V_28 -> V_44 ;
case V_18 :
return & V_1 -> V_26 . V_30 -> V_31 -> V_2 ;
case V_15 :
return & V_1 -> V_26 . V_33 -> V_28 -> V_44 ;
case V_17 :
return & V_1 -> V_26 . V_34 -> V_31 -> V_2 ;
case V_35 :
return & V_1 -> V_26 . V_36 -> V_28 -> V_44 ;
case V_16 :
return & V_1 -> V_26 . V_37 -> V_28 -> V_44 ;
default:
F_13 ( V_45 ,
V_43 ) ;
return NULL ;
}
}
const T_1 * F_32 ( T_2 * V_1 )
{
T_1 * * V_46 ;
V_46 = F_31 ( V_1 ) ;
if ( V_46 )
return * V_46 ;
return NULL ;
}
int F_33 ( T_2 * V_1 , const T_1 * V_47 )
{
T_1 * * V_46 , * V_48 ;
V_46 = F_31 ( V_1 ) ;
if ( ! V_46 )
return 0 ;
if ( ! V_47 )
return 1 ;
V_48 = F_34 ( V_47 ) ;
if ( ! V_48 )
return 0 ;
F_35 ( * V_46 ) ;
* V_46 = V_48 ;
return 1 ;
}
int F_36 ( T_2 * V_1 )
{
T_4 * * V_4 ;
V_4 = F_7 ( V_1 ) ;
if ( ! V_4 )
return - 1 ;
if ( * V_4 )
return 0 ;
return 1 ;
}
int F_5 ( T_2 * V_1 , int V_49 )
{
T_4 * * V_4 ;
V_4 = F_7 ( V_1 ) ;
if ( ! V_4 )
return 0 ;
if ( V_49 )
{
if ( * V_4 )
{
F_37 ( * V_4 ) ;
* V_4 = NULL ;
}
return 1 ;
}
if ( ! * V_4 )
* V_4 = F_38 () ;
if ( * V_4 )
{
( * V_4 ) -> V_5 |= V_6 ;
return 1 ;
}
F_13 ( V_50 , V_51 ) ;
return 0 ;
}
void F_39 ( T_5 * V_52 , const T_6 * V_53 )
{
int V_54 ;
if ( V_53 -> V_5 & V_55 )
V_54 = V_56 ;
else
V_54 = V_57 ;
F_40 ( V_52 , F_4 ( F_41 ( V_53 ) ) , V_54 , NULL ) ;
}
T_3 * F_42 ( T_5 * V_58 )
{
T_3 * V_59 = NULL ;
T_1 * V_60 ;
const T_6 * V_61 ;
F_43 ( & V_60 , NULL , NULL , V_58 ) ;
V_61 = F_44 ( V_60 ) ;
if ( ! V_61 )
{
F_13 ( V_62 ,
V_63 ) ;
goto V_64;
}
V_59 = F_8 ( F_45 () ) ;
if ( ! V_59 || ! F_46 ( V_59 , V_61 ) )
{
F_13 ( V_62 ,
V_65 ) ;
goto V_64;
}
return V_59 ;
V_64:
if ( V_59 )
F_22 ( V_59 ) ;
return NULL ;
}
int F_47 ( T_7 * V_66 , T_3 * V_67 ,
T_5 * V_68 )
{
int V_69 ;
T_1 * V_70 ;
F_43 ( & V_70 , NULL , NULL , V_68 ) ;
V_69 = F_14 ( V_70 ) ;
for (; ; )
{
T_7 * V_71 ;
V_67 = F_24 ( V_67 , V_72 ) ;
if ( V_67 == NULL )
{
F_13 ( V_73 ,
V_74 ) ;
return 0 ;
}
F_48 ( V_67 , & V_71 ) ;
if ( F_49 ( V_71 ) == V_69
|| F_50 ( F_51 ( V_71 ) ) == V_69 )
{
return F_52 ( V_66 , V_71 ) ;
}
V_67 = F_53 ( V_67 ) ;
}
}
int F_54 ( T_2 * V_1 , T_8 * V_75 )
{
int V_76 ;
V_76 = F_55 ( V_1 , V_75 ) ;
if ( V_76 > 0 )
F_56 ( & V_75 -> V_77 , 1 , V_78 ) ;
return V_76 ;
}
int F_57 ( T_2 * V_1 , T_9 * V_79 )
{
int V_76 ;
V_76 = F_58 ( V_1 , V_79 ) ;
if ( V_76 > 0 )
F_56 ( & V_79 -> V_77 , 1 , V_80 ) ;
return V_76 ;
}
