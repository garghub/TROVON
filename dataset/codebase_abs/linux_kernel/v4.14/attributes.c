int T_1 F_1 ( void )
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
int F_5 ( const T_2 * V_6 ,
const T_2 * V_7 )
{
T_3 V_8 , V_9 ;
V_8 = V_6 -> V_10 . V_11 ;
V_9 = V_7 -> V_10 . V_11 ;
if ( V_8 != V_9 )
return F_6 ( V_8 ) < F_6 ( V_9 ) ? - 1 : 1 ;
return F_7 (
( const struct V_12 * ) & V_6 -> V_10 . V_13 ,
( const struct V_12 * ) & V_7 -> V_10 . V_13 ) ;
}
int F_8 ( struct V_14 * V_15 , T_2 * V_16 ,
T_4 V_11 , const char * V_17 )
{
int V_18 ;
memset ( V_16 , 0 , sizeof( struct V_19 ) ) ;
V_16 -> V_10 . V_11 = F_9 ( V_11 ) ;
if ( V_17 ) {
int V_20 = F_10 ( V_15 ,
(struct V_12 * ) & V_16 -> V_10 . V_13 ,
V_21 , V_17 , strlen ( V_17 ) ) ;
if ( V_20 )
return V_20 ;
V_18 = F_11 ( V_16 -> V_10 . V_13 . V_22 ) ;
} else {
V_16 -> V_10 . V_13 . V_22 = 0 ;
V_18 = 0 ;
}
V_16 -> V_23 =
F_12 ( F_13 ( struct V_19 , V_13 ) +
2 * V_18 ) ;
return 0 ;
}
V_3 * F_14 ( void )
{
return F_15 ( V_1 , V_24 ) ;
}
void F_16 ( V_3 * V_25 )
{
if ( V_25 )
F_17 ( V_1 , V_25 ) ;
}
static int F_18 ( V_3 * V_25 , int V_26 ,
T_4 V_11 , const void * V_27 , T_5 V_28 )
{
if ( V_26 == V_29 ) {
memset ( V_25 , 0 , sizeof( * V_25 ) ) ;
return sizeof( struct V_30 ) ;
} else if ( V_26 == V_31 ) {
memset ( V_25 , 0 , sizeof( * V_25 ) ) ;
return sizeof( struct V_32 ) ;
} else if ( V_26 == V_33 ) {
T_6 V_18 ;
memset ( V_25 , 0 , sizeof( struct V_34 ) ) ;
V_25 -> V_35 . V_26 = F_9 ( V_26 ) ;
if ( V_28 <= V_36 )
V_18 = V_28 ;
else
return V_37 ;
V_25 -> V_35 . V_22 = F_12 ( V_18 ) ;
memcpy ( V_25 -> V_35 . V_38 , V_27 , V_18 ) ;
V_18 = F_19 ( V_18 , 2 ) ;
return F_13 ( struct V_34 , V_38 ) +
V_18 ;
} else
memset ( V_25 , 0 , sizeof( * V_25 ) ) ;
return V_37 ;
}
int F_20 ( struct V_14 * V_15 , T_4 V_11 ,
const char * V_17 , struct V_39 * V_40 )
{
int V_41 = 0 ;
F_21 ( V_42 , L_2 , V_17 ? V_17 : NULL , V_11 ) ;
if ( ! F_22 ( V_15 ) -> V_43 ) {
F_23 ( L_3 ) ;
return - V_44 ;
}
if ( V_17 ) {
V_41 = F_8 ( V_15 , V_40 -> V_45 , V_11 , V_17 ) ;
if ( V_41 )
goto V_46;
V_41 = F_24 ( V_40 , V_47 ) ;
if ( V_41 )
goto V_46;
} else {
V_41 = F_8 ( V_15 , V_40 -> V_45 , V_11 , NULL ) ;
if ( V_41 )
goto V_46;
V_41 = F_24 ( V_40 , V_48 ) ;
if ( V_41 )
goto V_46;
}
V_46:
return V_41 ;
}
int F_25 ( struct V_49 * V_49 , const char * V_17 )
{
int V_41 = 0 ;
struct V_14 * V_15 = V_49 -> V_50 ;
struct V_39 V_40 ;
if ( ! F_22 ( V_15 ) -> V_43 )
return 0 ;
V_41 = F_26 ( F_22 ( V_15 ) -> V_43 , & V_40 ) ;
if ( V_41 )
return 0 ;
V_41 = F_20 ( V_15 , V_49 -> V_51 , V_17 , & V_40 ) ;
if ( V_41 )
goto V_52;
F_27 ( & V_40 ) ;
return 1 ;
V_52:
F_27 ( & V_40 ) ;
return 0 ;
}
int F_28 ( struct V_49 * V_49 ,
const char * V_17 ,
const void * V_27 , T_5 V_28 )
{
struct V_14 * V_15 = V_49 -> V_50 ;
struct V_39 V_40 ;
V_3 * V_53 ;
int V_54 ;
int V_41 ;
F_21 ( V_42 , L_4 ,
V_17 ? V_17 : NULL , V_49 -> V_51 ) ;
if ( ! F_22 ( V_15 ) -> V_43 ) {
F_23 ( L_3 ) ;
return - V_44 ;
}
V_53 = F_14 () ;
if ( ! V_53 )
return - V_5 ;
V_41 = F_26 ( F_22 ( V_15 ) -> V_43 , & V_40 ) ;
if ( V_41 )
goto V_55;
if ( V_17 ) {
V_41 = F_8 ( V_15 , V_40 . V_45 ,
V_49 -> V_51 , V_17 ) ;
if ( V_41 )
goto V_56;
} else {
V_41 = - V_44 ;
goto V_56;
}
V_54 = F_18 ( V_53 ,
V_33 ,
V_49 -> V_51 ,
V_27 , V_28 ) ;
if ( V_54 == V_37 ) {
V_41 = - V_44 ;
goto V_56;
}
V_41 = F_24 ( & V_40 , V_47 ) ;
if ( V_41 != - V_57 ) {
if ( ! V_41 )
V_41 = - V_2 ;
goto V_56;
}
V_41 = F_29 ( & V_40 , V_53 , V_54 ) ;
if ( V_41 )
goto V_56;
F_30 ( V_49 , V_58 ) ;
V_56:
F_27 ( & V_40 ) ;
V_55:
F_16 ( V_53 ) ;
return V_41 ;
}
static int F_31 ( struct V_49 * V_49 , T_4 V_11 ,
struct V_39 * V_40 )
{
int V_41 = 0 ;
T_3 V_59 , V_26 ;
F_32 ( V_40 -> V_60 , & V_59 ,
V_40 -> V_61 +
F_13 ( struct V_19 , V_11 ) ,
sizeof( T_3 ) ) ;
if ( V_11 != F_6 ( V_59 ) )
return - V_57 ;
F_32 ( V_40 -> V_60 , & V_26 ,
V_40 -> V_62 , sizeof( V_26 ) ) ;
switch ( F_6 ( V_26 ) ) {
case V_33 :
break;
case V_29 :
case V_31 :
F_23 ( L_5 ) ;
return - V_63 ;
default:
F_23 ( L_6 ) ;
return - V_57 ;
}
V_41 = F_33 ( V_40 ) ;
if ( V_41 )
return V_41 ;
F_30 ( V_49 , V_58 ) ;
return V_41 ;
}
int F_34 ( struct V_49 * V_49 , const char * V_17 )
{
int V_41 = 0 ;
struct V_14 * V_15 = V_49 -> V_50 ;
struct V_39 V_40 ;
F_21 ( V_42 , L_7 ,
V_17 ? V_17 : NULL , V_49 -> V_51 ) ;
if ( ! F_22 ( V_15 ) -> V_43 ) {
F_23 ( L_3 ) ;
return - V_44 ;
}
V_41 = F_26 ( F_22 ( V_15 ) -> V_43 , & V_40 ) ;
if ( V_41 )
return V_41 ;
if ( V_17 ) {
V_41 = F_8 ( V_15 , V_40 . V_45 ,
V_49 -> V_51 , V_17 ) ;
if ( V_41 )
goto V_64;
} else {
F_23 ( L_8 ) ;
V_41 = - V_44 ;
goto V_64;
}
V_41 = F_24 ( & V_40 , V_47 ) ;
if ( V_41 )
goto V_64;
V_41 = F_31 ( V_49 , V_49 -> V_51 , & V_40 ) ;
if ( V_41 )
goto V_64;
V_64:
F_27 ( & V_40 ) ;
return V_41 ;
}
int F_35 ( struct V_49 * V_65 , T_4 V_11 )
{
int V_41 = 0 ;
struct V_39 V_40 ;
F_21 ( V_42 , L_9 , V_11 ) ;
if ( ! F_22 ( V_65 -> V_50 ) -> V_43 ) {
F_23 ( L_3 ) ;
return - V_44 ;
}
V_41 = F_26 ( F_22 ( V_65 -> V_50 ) -> V_43 , & V_40 ) ;
if ( V_41 )
return V_41 ;
for (; ; ) {
V_41 = F_20 ( V_65 -> V_50 , V_11 , NULL , & V_40 ) ;
if ( V_41 ) {
if ( V_41 != - V_57 )
F_23 ( L_10 ) ;
goto V_66;
}
V_41 = F_31 ( V_65 , V_11 , & V_40 ) ;
if ( V_41 )
goto V_66;
}
V_66:
F_27 ( & V_40 ) ;
return V_41 ;
}
