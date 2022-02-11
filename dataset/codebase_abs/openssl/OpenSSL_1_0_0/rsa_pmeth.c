static int F_1 ( T_1 * V_1 )
{
T_2 * V_2 ;
V_2 = F_2 ( sizeof( T_2 ) ) ;
if ( ! V_2 )
return 0 ;
V_2 -> V_3 = 1024 ;
V_2 -> V_4 = NULL ;
V_2 -> V_5 = V_6 ;
V_2 -> V_7 = NULL ;
V_2 -> V_8 = NULL ;
V_2 -> V_9 = - 2 ;
V_1 -> V_10 = V_2 ;
V_1 -> V_11 = V_2 -> V_12 ;
V_1 -> V_13 = 2 ;
return 1 ;
}
static int F_3 ( T_1 * V_14 , T_1 * V_15 )
{
T_2 * V_16 , * V_17 ;
if ( ! F_1 ( V_14 ) )
return 0 ;
V_17 = V_15 -> V_10 ;
V_16 = V_14 -> V_10 ;
V_16 -> V_3 = V_17 -> V_3 ;
if ( V_17 -> V_4 )
{
V_16 -> V_4 = F_4 ( V_17 -> V_4 ) ;
if ( ! V_16 -> V_4 )
return 0 ;
}
V_16 -> V_5 = V_17 -> V_5 ;
V_16 -> V_7 = V_17 -> V_7 ;
return 1 ;
}
static int F_5 ( T_2 * V_1 , T_1 * V_18 )
{
if ( V_1 -> V_8 )
return 1 ;
V_1 -> V_8 = F_2 ( F_6 ( V_18 -> V_19 ) ) ;
if ( ! V_1 -> V_8 )
return 0 ;
return 1 ;
}
static void F_7 ( T_1 * V_1 )
{
T_2 * V_2 = V_1 -> V_10 ;
if ( V_2 )
{
if ( V_2 -> V_4 )
F_8 ( V_2 -> V_4 ) ;
if ( V_2 -> V_8 )
F_9 ( V_2 -> V_8 ) ;
F_9 ( V_2 ) ;
}
}
static int F_10 ( T_1 * V_1 , unsigned char * V_20 , T_3 * V_21 ,
const unsigned char * V_22 , T_3 V_23 )
{
int V_24 ;
T_2 * V_2 = V_1 -> V_10 ;
T_4 * V_25 = V_1 -> V_19 -> V_19 . V_25 ;
if ( V_2 -> V_7 )
{
if ( V_23 != ( T_3 ) F_11 ( V_2 -> V_7 ) )
{
F_12 ( V_26 ,
V_27 ) ;
return - 1 ;
}
if ( V_2 -> V_5 == V_28 )
{
if ( ! F_5 ( V_2 , V_1 ) )
return - 1 ;
memcpy ( V_2 -> V_8 , V_22 , V_23 ) ;
V_2 -> V_8 [ V_23 ] =
F_13 ( F_14 ( V_2 -> V_7 ) ) ;
V_24 = F_15 ( V_23 + 1 , V_2 -> V_8 ,
V_20 , V_25 , V_28 ) ;
}
else if ( V_2 -> V_5 == V_6 )
{
unsigned int V_29 ;
V_24 = F_16 ( F_14 ( V_2 -> V_7 ) ,
V_22 , V_23 , V_20 , & V_29 , V_25 ) ;
if ( V_24 <= 0 )
return V_24 ;
V_24 = V_29 ;
}
else if ( V_2 -> V_5 == V_30 )
{
if ( ! F_5 ( V_2 , V_1 ) )
return - 1 ;
if ( ! F_17 ( V_25 , V_2 -> V_8 , V_22 ,
V_2 -> V_7 , V_2 -> V_9 ) )
return - 1 ;
V_24 = F_15 ( F_18 ( V_25 ) , V_2 -> V_8 ,
V_20 , V_25 , V_31 ) ;
}
else
return - 1 ;
}
else
V_24 = F_15 ( V_23 , V_22 , V_20 , V_1 -> V_19 -> V_19 . V_25 ,
V_2 -> V_5 ) ;
if ( V_24 < 0 )
return V_24 ;
* V_21 = V_24 ;
return 1 ;
}
static int F_19 ( T_1 * V_1 ,
unsigned char * V_32 , T_3 * V_33 ,
const unsigned char * V_20 , T_3 V_21 )
{
int V_24 ;
T_2 * V_2 = V_1 -> V_10 ;
if ( V_2 -> V_7 )
{
if ( V_2 -> V_5 == V_28 )
{
if ( ! F_5 ( V_2 , V_1 ) )
return - 1 ;
V_24 = F_20 ( V_21 , V_20 ,
V_2 -> V_8 , V_1 -> V_19 -> V_19 . V_25 ,
V_28 ) ;
if ( V_24 < 1 )
return 0 ;
V_24 -- ;
if ( V_2 -> V_8 [ V_24 ] !=
F_13 ( F_14 ( V_2 -> V_7 ) ) )
{
F_12 ( V_34 ,
V_35 ) ;
return 0 ;
}
if ( V_24 != F_11 ( V_2 -> V_7 ) )
{
F_12 ( V_34 ,
V_27 ) ;
return 0 ;
}
if ( V_32 )
memcpy ( V_32 , V_2 -> V_8 , V_24 ) ;
}
else if ( V_2 -> V_5 == V_6 )
{
T_3 V_29 ;
V_24 = F_21 ( F_14 ( V_2 -> V_7 ) ,
NULL , 0 , V_32 , & V_29 ,
V_20 , V_21 , V_1 -> V_19 -> V_19 . V_25 ) ;
V_24 = V_29 ;
}
else
return - 1 ;
}
else
V_24 = F_20 ( V_21 , V_20 , V_32 , V_1 -> V_19 -> V_19 . V_25 ,
V_2 -> V_5 ) ;
if ( V_24 < 0 )
return V_24 ;
* V_33 = V_24 ;
return 1 ;
}
static int F_22 ( T_1 * V_1 ,
const unsigned char * V_20 , T_3 V_21 ,
const unsigned char * V_22 , T_3 V_23 )
{
T_2 * V_2 = V_1 -> V_10 ;
T_4 * V_25 = V_1 -> V_19 -> V_19 . V_25 ;
T_3 V_36 ;
if ( V_2 -> V_7 )
{
if ( V_2 -> V_5 == V_6 )
return F_23 ( F_14 ( V_2 -> V_7 ) , V_22 , V_23 ,
V_20 , V_21 , V_25 ) ;
if ( V_2 -> V_5 == V_28 )
{
if ( F_19 ( V_1 , NULL , & V_36 ,
V_20 , V_21 ) <= 0 )
return 0 ;
}
else if ( V_2 -> V_5 == V_30 )
{
int V_24 ;
if ( ! F_5 ( V_2 , V_1 ) )
return - 1 ;
V_24 = F_20 ( V_21 , V_20 , V_2 -> V_8 ,
V_25 , V_31 ) ;
if ( V_24 <= 0 )
return 0 ;
V_24 = F_24 ( V_25 , V_22 , V_2 -> V_7 ,
V_2 -> V_8 , V_2 -> V_9 ) ;
if ( V_24 <= 0 )
return 0 ;
return 1 ;
}
else
return - 1 ;
}
else
{
if ( ! F_5 ( V_2 , V_1 ) )
return - 1 ;
V_36 = F_20 ( V_21 , V_20 , V_2 -> V_8 ,
V_25 , V_2 -> V_5 ) ;
if ( V_36 == 0 )
return 0 ;
}
if ( ( V_36 != V_23 ) || memcmp ( V_22 , V_2 -> V_8 , V_36 ) )
return 0 ;
return 1 ;
}
static int F_25 ( T_1 * V_1 ,
unsigned char * V_37 , T_3 * V_38 ,
const unsigned char * V_39 , T_3 V_40 )
{
int V_24 ;
T_2 * V_2 = V_1 -> V_10 ;
V_24 = F_26 ( V_40 , V_39 , V_37 , V_1 -> V_19 -> V_19 . V_25 ,
V_2 -> V_5 ) ;
if ( V_24 < 0 )
return V_24 ;
* V_38 = V_24 ;
return 1 ;
}
static int F_27 ( T_1 * V_1 ,
unsigned char * V_37 , T_3 * V_38 ,
const unsigned char * V_39 , T_3 V_40 )
{
int V_24 ;
T_2 * V_2 = V_1 -> V_10 ;
V_24 = F_28 ( V_40 , V_39 , V_37 , V_1 -> V_19 -> V_19 . V_25 ,
V_2 -> V_5 ) ;
if ( V_24 < 0 )
return V_24 ;
* V_38 = V_24 ;
return 1 ;
}
static int F_29 ( const T_5 * V_7 , int V_41 )
{
if ( ! V_7 )
return 1 ;
if ( V_41 == V_31 )
{
F_12 ( V_42 , V_43 ) ;
return 0 ;
}
if ( V_41 == V_28 )
{
if ( F_13 ( F_14 ( V_7 ) ) == - 1 )
{
F_12 ( V_42 ,
V_44 ) ;
return 0 ;
}
return 1 ;
}
return 1 ;
}
static int F_30 ( T_1 * V_1 , int type , int V_45 , void * V_46 )
{
T_2 * V_2 = V_1 -> V_10 ;
switch ( type )
{
case V_47 :
if ( ( V_45 >= V_6 ) && ( V_45 <= V_30 ) )
{
if ( ! F_29 ( V_2 -> V_7 , V_45 ) )
return 0 ;
if ( V_45 == V_30 )
{
if ( ! ( V_1 -> V_48 &
( V_49 | V_50 ) ) )
goto V_51;
if ( ! V_2 -> V_7 )
V_2 -> V_7 = F_31 () ;
}
if ( V_45 == V_52 )
{
if ( ! ( V_1 -> V_48 & V_53 ) )
goto V_51;
if ( ! V_2 -> V_7 )
V_2 -> V_7 = F_31 () ;
}
V_2 -> V_5 = V_45 ;
return 1 ;
}
V_51:
F_12 ( V_54 ,
V_55 ) ;
return - 2 ;
case V_56 :
if ( V_45 < - 2 )
return - 2 ;
if ( V_2 -> V_5 != V_30 )
{
F_12 ( V_54 , V_57 ) ;
return - 2 ;
}
V_2 -> V_9 = V_45 ;
return 1 ;
case V_58 :
if ( V_45 < 256 )
{
F_12 ( V_54 , V_59 ) ;
return - 2 ;
}
V_2 -> V_3 = V_45 ;
return 1 ;
case V_60 :
if ( ! V_46 )
return - 2 ;
V_2 -> V_4 = V_46 ;
return 1 ;
case V_61 :
if ( ! F_29 ( V_46 , V_2 -> V_5 ) )
return 0 ;
V_2 -> V_7 = V_46 ;
return 1 ;
case V_62 :
case V_63 :
case V_64 :
case V_65 :
#ifndef F_32
case V_66 :
case V_67 :
case V_68 :
#endif
return 1 ;
case V_69 :
F_12 ( V_54 ,
V_70 ) ;
return - 2 ;
default:
return - 2 ;
}
}
static int F_33 ( T_1 * V_1 ,
const char * type , const char * V_71 )
{
if ( ! V_71 )
{
F_12 ( V_72 , V_73 ) ;
return 0 ;
}
if ( ! strcmp ( type , L_1 ) )
{
int V_74 ;
if ( ! strcmp ( V_71 , L_2 ) )
V_74 = V_6 ;
else if ( ! strcmp ( V_71 , L_3 ) )
V_74 = V_75 ;
else if ( ! strcmp ( V_71 , L_4 ) )
V_74 = V_31 ;
else if ( ! strcmp ( V_71 , L_5 ) )
V_74 = V_52 ;
else if ( ! strcmp ( V_71 , L_6 ) )
V_74 = V_28 ;
else if ( ! strcmp ( V_71 , L_7 ) )
V_74 = V_30 ;
else
{
F_12 ( V_72 ,
V_76 ) ;
return - 2 ;
}
return F_34 ( V_1 , V_74 ) ;
}
if ( ! strcmp ( type , L_8 ) )
{
int V_9 ;
V_9 = atoi ( V_71 ) ;
return F_35 ( V_1 , V_9 ) ;
}
if ( ! strcmp ( type , L_9 ) )
{
int V_3 ;
V_3 = atoi ( V_71 ) ;
return F_36 ( V_1 , V_3 ) ;
}
if ( ! strcmp ( type , L_10 ) )
{
int V_24 ;
T_6 * V_77 = NULL ;
if ( ! F_37 ( & V_77 , V_71 ) )
return 0 ;
V_24 = F_38 ( V_1 , V_77 ) ;
if ( V_24 <= 0 )
F_8 ( V_77 ) ;
return V_24 ;
}
return - 2 ;
}
static int F_39 ( T_1 * V_1 , T_7 * V_19 )
{
T_4 * V_25 = NULL ;
T_2 * V_2 = V_1 -> V_10 ;
T_8 * V_78 , V_79 ;
int V_24 ;
if ( ! V_2 -> V_4 )
{
V_2 -> V_4 = F_40 () ;
if ( ! V_2 -> V_4 || ! F_41 ( V_2 -> V_4 , V_80 ) )
return 0 ;
}
V_25 = F_42 () ;
if ( ! V_25 )
return 0 ;
if ( V_1 -> V_81 )
{
V_78 = & V_79 ;
F_43 ( V_78 , V_1 ) ;
}
else
V_78 = NULL ;
V_24 = F_44 ( V_25 , V_2 -> V_3 , V_2 -> V_4 , V_78 ) ;
if ( V_24 > 0 )
F_45 ( V_19 , V_25 ) ;
else
F_46 ( V_25 ) ;
return V_24 ;
}
