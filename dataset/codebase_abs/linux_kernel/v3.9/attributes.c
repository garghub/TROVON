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
F_10 ( V_21 L_2 ) ;
return - V_22 ;
}
F_11 ( V_15 ,
(struct V_12 * ) & V_16 -> V_10 . V_13 ,
V_20 , V_17 , V_18 ) ;
V_18 = F_12 ( V_16 -> V_10 . V_13 . V_23 ) ;
} else {
V_16 -> V_10 . V_13 . V_23 = 0 ;
V_18 = 0 ;
}
V_16 -> V_24 =
F_13 ( F_14 ( struct V_19 , V_13 ) +
2 * V_18 ) ;
return 0 ;
}
void F_15 ( T_1 * V_16 ,
T_3 V_11 ,
struct V_25 * V_17 )
{
int V_26 ;
memset ( V_16 , 0 , sizeof( struct V_19 ) ) ;
V_26 = F_12 ( V_17 -> V_23 ) ;
V_16 -> V_10 . V_11 = F_9 ( V_11 ) ;
V_16 -> V_10 . V_13 . V_23 = F_13 ( V_26 ) ;
V_26 *= 2 ;
memcpy ( V_16 -> V_10 . V_13 . V_27 , V_17 -> V_27 , V_26 ) ;
V_16 -> V_24 =
F_13 ( F_14 ( struct V_19 , V_13 ) +
V_26 ) ;
}
V_3 * F_16 ( void )
{
return F_17 ( V_1 , V_28 ) ;
}
void F_18 ( V_3 * V_29 )
{
if ( V_29 )
F_19 ( V_1 , V_29 ) ;
}
static int F_20 ( V_3 * V_29 , int V_30 ,
T_3 V_11 , const void * V_31 , T_4 V_32 )
{
if ( V_30 == V_33 ) {
memset ( V_29 , 0 , sizeof( * V_29 ) ) ;
return sizeof( struct V_34 ) ;
} else if ( V_30 == V_35 ) {
memset ( V_29 , 0 , sizeof( * V_29 ) ) ;
return sizeof( struct V_36 ) ;
} else if ( V_30 == V_37 ) {
T_5 V_18 ;
memset ( V_29 , 0 , sizeof( struct V_38 ) ) ;
V_29 -> V_39 . V_30 = F_9 ( V_30 ) ;
if ( V_32 <= V_40 )
V_18 = V_32 ;
else
return V_41 ;
V_29 -> V_39 . V_23 = F_13 ( V_18 ) ;
memcpy ( V_29 -> V_39 . V_42 , V_31 , V_18 ) ;
V_18 = F_21 ( V_18 , 2 ) ;
return F_14 ( struct V_38 , V_42 ) +
V_18 ;
} else
memset ( V_29 , 0 , sizeof( * V_29 ) ) ;
return V_41 ;
}
int F_22 ( struct V_14 * V_15 , T_3 V_11 ,
const char * V_17 , struct V_43 * V_44 )
{
int V_45 = 0 ;
F_23 ( V_46 , L_3 , V_17 ? V_17 : NULL , V_11 ) ;
if ( ! F_24 ( V_15 ) -> V_47 ) {
F_10 ( V_21 L_4 ) ;
return - V_22 ;
}
if ( V_17 ) {
V_45 = F_8 ( V_15 , V_44 -> V_48 , V_11 , V_17 ) ;
if ( V_45 )
goto V_49;
V_45 = F_25 ( V_44 , V_50 ) ;
if ( V_45 )
goto V_49;
} else {
V_45 = F_8 ( V_15 , V_44 -> V_48 , V_11 , NULL ) ;
if ( V_45 )
goto V_49;
V_45 = F_25 ( V_44 , V_51 ) ;
if ( V_45 )
goto V_49;
}
V_49:
return V_45 ;
}
int F_26 ( struct V_52 * V_52 , const char * V_17 )
{
int V_45 = 0 ;
struct V_14 * V_15 = V_52 -> V_53 ;
struct V_43 V_44 ;
if ( ! F_24 ( V_15 ) -> V_47 )
return 0 ;
V_45 = F_27 ( F_24 ( V_15 ) -> V_47 , & V_44 ) ;
if ( V_45 )
return 0 ;
V_45 = F_22 ( V_15 , V_52 -> V_54 , V_17 , & V_44 ) ;
if ( V_45 )
goto V_55;
F_28 ( & V_44 ) ;
return 1 ;
V_55:
F_28 ( & V_44 ) ;
return 0 ;
}
int F_29 ( struct V_52 * V_52 ,
const char * V_17 ,
const void * V_31 , T_4 V_32 )
{
struct V_14 * V_15 = V_52 -> V_53 ;
struct V_43 V_44 ;
V_3 * V_56 ;
int V_57 ;
int V_45 ;
F_23 ( V_46 , L_5 ,
V_17 ? V_17 : NULL , V_52 -> V_54 ) ;
if ( ! F_24 ( V_15 ) -> V_47 ) {
F_10 ( V_21 L_4 ) ;
return - V_22 ;
}
V_56 = F_16 () ;
if ( ! V_56 )
return - V_5 ;
V_45 = F_27 ( F_24 ( V_15 ) -> V_47 , & V_44 ) ;
if ( V_45 )
goto V_58;
if ( V_17 ) {
V_45 = F_8 ( V_15 , V_44 . V_48 ,
V_52 -> V_54 , V_17 ) ;
if ( V_45 )
goto V_59;
} else {
V_45 = - V_22 ;
goto V_59;
}
V_57 = F_20 ( V_56 ,
V_37 ,
V_52 -> V_54 ,
V_31 , V_32 ) ;
if ( V_57 == V_41 ) {
V_45 = - V_22 ;
goto V_59;
}
V_45 = F_25 ( & V_44 , V_50 ) ;
if ( V_45 != - V_60 ) {
if ( ! V_45 )
V_45 = - V_2 ;
goto V_59;
}
V_45 = F_30 ( & V_44 , V_56 , V_57 ) ;
if ( V_45 )
goto V_59;
F_31 ( V_52 , V_61 ) ;
V_59:
F_28 ( & V_44 ) ;
V_58:
F_18 ( V_56 ) ;
return V_45 ;
}
static int F_32 ( struct V_52 * V_52 , T_3 V_11 ,
struct V_43 * V_44 )
{
int V_45 = 0 ;
T_2 V_62 , V_30 ;
F_33 ( V_44 -> V_63 , & V_62 ,
V_44 -> V_64 +
F_14 ( struct V_19 , V_11 ) ,
sizeof( T_2 ) ) ;
if ( V_11 != F_6 ( V_62 ) )
return - V_60 ;
F_33 ( V_44 -> V_63 , & V_30 ,
V_44 -> V_65 , sizeof( V_30 ) ) ;
switch ( F_6 ( V_30 ) ) {
case V_37 :
break;
case V_33 :
case V_35 :
F_10 ( V_21 L_6 ) ;
return - V_66 ;
default:
F_10 ( V_21 L_7 ) ;
return - V_60 ;
}
V_45 = F_34 ( V_44 ) ;
if ( V_45 )
return V_45 ;
F_31 ( V_52 , V_61 ) ;
return V_45 ;
}
int F_35 ( struct V_52 * V_52 , const char * V_17 )
{
int V_45 = 0 ;
struct V_14 * V_15 = V_52 -> V_53 ;
struct V_43 V_44 ;
F_23 ( V_46 , L_8 ,
V_17 ? V_17 : NULL , V_52 -> V_54 ) ;
if ( ! F_24 ( V_15 ) -> V_47 ) {
F_10 ( V_21 L_4 ) ;
return - V_22 ;
}
V_45 = F_27 ( F_24 ( V_15 ) -> V_47 , & V_44 ) ;
if ( V_45 )
return V_45 ;
if ( V_17 ) {
V_45 = F_8 ( V_15 , V_44 . V_48 ,
V_52 -> V_54 , V_17 ) ;
if ( V_45 )
goto V_67;
} else {
F_10 ( V_21 L_9 ) ;
V_45 = - V_22 ;
goto V_67;
}
V_45 = F_25 ( & V_44 , V_50 ) ;
if ( V_45 )
goto V_67;
V_45 = F_32 ( V_52 , V_52 -> V_54 , & V_44 ) ;
if ( V_45 )
goto V_67;
V_67:
F_28 ( & V_44 ) ;
return V_45 ;
}
int F_36 ( struct V_52 * V_68 , T_3 V_11 )
{
int V_45 = 0 ;
struct V_43 V_44 ;
F_23 ( V_46 , L_10 , V_11 ) ;
if ( ! F_24 ( V_68 -> V_53 ) -> V_47 ) {
F_10 ( V_21 L_4 ) ;
return - V_22 ;
}
V_45 = F_27 ( F_24 ( V_68 -> V_53 ) -> V_47 , & V_44 ) ;
if ( V_45 )
return V_45 ;
for (; ; ) {
V_45 = F_22 ( V_68 -> V_53 , V_11 , NULL , & V_44 ) ;
if ( V_45 ) {
if ( V_45 != - V_60 )
F_10 ( V_21 L_11 ) ;
goto V_69;
}
V_45 = F_32 ( V_68 , V_11 , & V_44 ) ;
if ( V_45 )
goto V_69;
}
V_69:
F_28 ( & V_44 ) ;
return V_45 ;
}
