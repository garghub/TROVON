int F_1 ( void )
{
if ( V_1 )
return - V_2 ;
V_1 =
F_2 ( L_1 ,
sizeof( V_3 ) , 0 ,
V_4 , NULL ) ;
if ( ! V_1 )
return - V_5 ;
return 0 ;
}
void F_3 ( void )
{
F_4 ( V_1 ) ;
}
int F_5 ( const T_1 * V_6 ,
const T_1 * V_7 )
{
T_2 V_8 , V_9 ;
V_8 = V_6 -> V_10 . V_11 ;
V_9 = V_7 -> V_10 . V_11 ;
if ( V_8 != V_9 )
return F_6 ( V_8 ) < F_6 ( V_9 ) ? - 1 : 1 ;
return F_7 (
( const struct V_12 * ) & V_6 -> V_10 . V_13 ,
( const struct V_12 * ) & V_7 -> V_10 . V_13 ) ;
}
int F_8 ( struct V_14 * V_15 , T_1 * V_16 ,
T_3 V_11 , const char * V_17 )
{
int V_18 ;
memset ( V_16 , 0 , sizeof( struct V_19 ) ) ;
V_16 -> V_10 . V_11 = F_9 ( V_11 ) ;
if ( V_17 ) {
V_18 = strlen ( V_17 ) ;
if ( V_18 > V_20 ) {
F_10 ( L_2 ) ;
return - V_21 ;
}
F_11 ( V_15 ,
(struct V_12 * ) & V_16 -> V_10 . V_13 ,
V_20 , V_17 , V_18 ) ;
V_18 = F_12 ( V_16 -> V_10 . V_13 . V_22 ) ;
} else {
V_16 -> V_10 . V_13 . V_22 = 0 ;
V_18 = 0 ;
}
V_16 -> V_23 =
F_13 ( F_14 ( struct V_19 , V_13 ) +
2 * V_18 ) ;
return 0 ;
}
void F_15 ( T_1 * V_16 ,
T_3 V_11 ,
struct V_24 * V_17 )
{
int V_25 ;
memset ( V_16 , 0 , sizeof( struct V_19 ) ) ;
V_25 = F_12 ( V_17 -> V_22 ) ;
V_16 -> V_10 . V_11 = F_9 ( V_11 ) ;
V_16 -> V_10 . V_13 . V_22 = F_13 ( V_25 ) ;
V_25 *= 2 ;
memcpy ( V_16 -> V_10 . V_13 . V_26 , V_17 -> V_26 , V_25 ) ;
V_16 -> V_23 =
F_13 ( F_14 ( struct V_19 , V_13 ) +
V_25 ) ;
}
V_3 * F_16 ( void )
{
return F_17 ( V_1 , V_27 ) ;
}
void F_18 ( V_3 * V_28 )
{
if ( V_28 )
F_19 ( V_1 , V_28 ) ;
}
static int F_20 ( V_3 * V_28 , int V_29 ,
T_3 V_11 , const void * V_30 , T_4 V_31 )
{
if ( V_29 == V_32 ) {
memset ( V_28 , 0 , sizeof( * V_28 ) ) ;
return sizeof( struct V_33 ) ;
} else if ( V_29 == V_34 ) {
memset ( V_28 , 0 , sizeof( * V_28 ) ) ;
return sizeof( struct V_35 ) ;
} else if ( V_29 == V_36 ) {
T_5 V_18 ;
memset ( V_28 , 0 , sizeof( struct V_37 ) ) ;
V_28 -> V_38 . V_29 = F_9 ( V_29 ) ;
if ( V_31 <= V_39 )
V_18 = V_31 ;
else
return V_40 ;
V_28 -> V_38 . V_22 = F_13 ( V_18 ) ;
memcpy ( V_28 -> V_38 . V_41 , V_30 , V_18 ) ;
V_18 = F_21 ( V_18 , 2 ) ;
return F_14 ( struct V_37 , V_41 ) +
V_18 ;
} else
memset ( V_28 , 0 , sizeof( * V_28 ) ) ;
return V_40 ;
}
int F_22 ( struct V_14 * V_15 , T_3 V_11 ,
const char * V_17 , struct V_42 * V_43 )
{
int V_44 = 0 ;
F_23 ( V_45 , L_3 , V_17 ? V_17 : NULL , V_11 ) ;
if ( ! F_24 ( V_15 ) -> V_46 ) {
F_10 ( L_4 ) ;
return - V_21 ;
}
if ( V_17 ) {
V_44 = F_8 ( V_15 , V_43 -> V_47 , V_11 , V_17 ) ;
if ( V_44 )
goto V_48;
V_44 = F_25 ( V_43 , V_49 ) ;
if ( V_44 )
goto V_48;
} else {
V_44 = F_8 ( V_15 , V_43 -> V_47 , V_11 , NULL ) ;
if ( V_44 )
goto V_48;
V_44 = F_25 ( V_43 , V_50 ) ;
if ( V_44 )
goto V_48;
}
V_48:
return V_44 ;
}
int F_26 ( struct V_51 * V_51 , const char * V_17 )
{
int V_44 = 0 ;
struct V_14 * V_15 = V_51 -> V_52 ;
struct V_42 V_43 ;
if ( ! F_24 ( V_15 ) -> V_46 )
return 0 ;
V_44 = F_27 ( F_24 ( V_15 ) -> V_46 , & V_43 ) ;
if ( V_44 )
return 0 ;
V_44 = F_22 ( V_15 , V_51 -> V_53 , V_17 , & V_43 ) ;
if ( V_44 )
goto V_54;
F_28 ( & V_43 ) ;
return 1 ;
V_54:
F_28 ( & V_43 ) ;
return 0 ;
}
int F_29 ( struct V_51 * V_51 ,
const char * V_17 ,
const void * V_30 , T_4 V_31 )
{
struct V_14 * V_15 = V_51 -> V_52 ;
struct V_42 V_43 ;
V_3 * V_55 ;
int V_56 ;
int V_44 ;
F_23 ( V_45 , L_5 ,
V_17 ? V_17 : NULL , V_51 -> V_53 ) ;
if ( ! F_24 ( V_15 ) -> V_46 ) {
F_10 ( L_4 ) ;
return - V_21 ;
}
V_55 = F_16 () ;
if ( ! V_55 )
return - V_5 ;
V_44 = F_27 ( F_24 ( V_15 ) -> V_46 , & V_43 ) ;
if ( V_44 )
goto V_57;
if ( V_17 ) {
V_44 = F_8 ( V_15 , V_43 . V_47 ,
V_51 -> V_53 , V_17 ) ;
if ( V_44 )
goto V_58;
} else {
V_44 = - V_21 ;
goto V_58;
}
V_56 = F_20 ( V_55 ,
V_36 ,
V_51 -> V_53 ,
V_30 , V_31 ) ;
if ( V_56 == V_40 ) {
V_44 = - V_21 ;
goto V_58;
}
V_44 = F_25 ( & V_43 , V_49 ) ;
if ( V_44 != - V_59 ) {
if ( ! V_44 )
V_44 = - V_2 ;
goto V_58;
}
V_44 = F_30 ( & V_43 , V_55 , V_56 ) ;
if ( V_44 )
goto V_58;
F_31 ( V_51 , V_60 ) ;
V_58:
F_28 ( & V_43 ) ;
V_57:
F_18 ( V_55 ) ;
return V_44 ;
}
static int F_32 ( struct V_51 * V_51 , T_3 V_11 ,
struct V_42 * V_43 )
{
int V_44 = 0 ;
T_2 V_61 , V_29 ;
F_33 ( V_43 -> V_62 , & V_61 ,
V_43 -> V_63 +
F_14 ( struct V_19 , V_11 ) ,
sizeof( T_2 ) ) ;
if ( V_11 != F_6 ( V_61 ) )
return - V_59 ;
F_33 ( V_43 -> V_62 , & V_29 ,
V_43 -> V_64 , sizeof( V_29 ) ) ;
switch ( F_6 ( V_29 ) ) {
case V_36 :
break;
case V_32 :
case V_34 :
F_10 ( L_6 ) ;
return - V_65 ;
default:
F_10 ( L_7 ) ;
return - V_59 ;
}
V_44 = F_34 ( V_43 ) ;
if ( V_44 )
return V_44 ;
F_31 ( V_51 , V_60 ) ;
return V_44 ;
}
int F_35 ( struct V_51 * V_51 , const char * V_17 )
{
int V_44 = 0 ;
struct V_14 * V_15 = V_51 -> V_52 ;
struct V_42 V_43 ;
F_23 ( V_45 , L_8 ,
V_17 ? V_17 : NULL , V_51 -> V_53 ) ;
if ( ! F_24 ( V_15 ) -> V_46 ) {
F_10 ( L_4 ) ;
return - V_21 ;
}
V_44 = F_27 ( F_24 ( V_15 ) -> V_46 , & V_43 ) ;
if ( V_44 )
return V_44 ;
if ( V_17 ) {
V_44 = F_8 ( V_15 , V_43 . V_47 ,
V_51 -> V_53 , V_17 ) ;
if ( V_44 )
goto V_66;
} else {
F_10 ( L_9 ) ;
V_44 = - V_21 ;
goto V_66;
}
V_44 = F_25 ( & V_43 , V_49 ) ;
if ( V_44 )
goto V_66;
V_44 = F_32 ( V_51 , V_51 -> V_53 , & V_43 ) ;
if ( V_44 )
goto V_66;
V_66:
F_28 ( & V_43 ) ;
return V_44 ;
}
int F_36 ( struct V_51 * V_67 , T_3 V_11 )
{
int V_44 = 0 ;
struct V_42 V_43 ;
F_23 ( V_45 , L_10 , V_11 ) ;
if ( ! F_24 ( V_67 -> V_52 ) -> V_46 ) {
F_10 ( L_4 ) ;
return - V_21 ;
}
V_44 = F_27 ( F_24 ( V_67 -> V_52 ) -> V_46 , & V_43 ) ;
if ( V_44 )
return V_44 ;
for (; ; ) {
V_44 = F_22 ( V_67 -> V_52 , V_11 , NULL , & V_43 ) ;
if ( V_44 ) {
if ( V_44 != - V_59 )
F_10 ( L_11 ) ;
goto V_68;
}
V_44 = F_32 ( V_67 , V_11 , & V_43 ) ;
if ( V_44 )
goto V_68;
}
V_68:
F_28 ( & V_43 ) ;
return V_44 ;
}
