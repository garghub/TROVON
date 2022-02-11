static int F_1 ( struct V_1 * V_2 )
{
unsigned char * V_3 = ( V_4 * ) ( F_2 ( V_2 ) + 1 ) ;
T_1 V_5 ;
const unsigned char * V_6 = F_3 ( V_2 ) ;
int V_7 = V_3 - V_6 ;
int V_8 = ( V_3 [ 1 ] + 1 ) << 3 ;
if ( ( V_3 + V_8 ) - V_2 -> V_9 > F_4 ( V_2 ) )
goto V_10;
V_7 += 2 ;
V_8 -= 2 ;
while ( V_8 > 0 ) {
int V_11 = V_6 [ V_7 + 1 ] + 2 ;
switch ( V_6 [ V_7 ] ) {
case V_12 :
V_11 = 1 ;
break;
case V_13 :
break;
case V_14 :
if ( V_6 [ V_7 + 1 ] != 4 || ( V_7 & 3 ) != 2 )
goto V_10;
V_5 = F_5 ( * ( V_15 * ) ( V_6 + V_7 + 2 ) ) ;
if ( V_5 <= V_16 ||
F_2 ( V_2 ) -> V_17 )
goto V_10;
if ( V_5 > V_2 -> V_8 - sizeof( struct V_18 ) )
goto V_10;
if ( F_6 ( V_2 ,
V_5 + sizeof( struct V_18 ) ) )
goto V_10;
V_6 = F_3 ( V_2 ) ;
break;
default:
if ( V_11 > V_8 )
goto V_10;
break;
}
V_7 += V_11 ;
V_8 -= V_11 ;
}
if ( V_8 == 0 )
return 0 ;
V_10:
return - 1 ;
}
int F_7 ( struct V_19 * V_19 , struct V_1 * V_2 )
{
const struct V_18 * V_20 ;
struct V_21 * V_22 = F_8 ( V_2 -> V_23 ) ;
T_1 V_5 ;
V_4 V_24 = sizeof( struct V_18 ) ;
if ( ! F_9 ( V_2 , V_24 ) )
goto V_25;
if ( V_2 -> V_8 < V_24 )
goto V_26;
V_20 = F_2 ( V_2 ) ;
if ( V_20 -> V_27 != 6 )
goto V_25;
V_5 = F_10 ( V_20 -> V_17 ) ;
if ( V_5 || V_20 -> V_28 != V_29 ) {
if ( V_5 + V_24 > V_2 -> V_8 ) {
F_11 ( V_19 , V_22 ,
V_30 ) ;
goto V_26;
}
if ( F_6 ( V_2 , V_5 + V_24 ) ) {
F_11 ( V_19 , V_22 ,
V_31 ) ;
goto V_26;
}
}
if ( V_20 -> V_28 == V_29 && F_1 ( V_2 ) )
goto V_26;
memset ( F_12 ( V_2 ) , 0 , sizeof( struct V_32 ) ) ;
return 0 ;
V_25:
F_11 ( V_19 , V_22 , V_33 ) ;
V_26:
return - 1 ;
}
static inline bool
F_13 ( const struct V_1 * V_2 ,
const struct V_34 * V_35 )
{
return memcmp ( & V_35 -> V_36 , & F_2 ( V_2 ) -> V_37 ,
sizeof( F_2 ( V_2 ) -> V_37 ) ) != 0 ;
}
static int F_14 ( struct V_19 * V_19 , struct V_38 * V_39 , struct V_1 * V_2 )
{
struct V_34 * V_35 = F_15 ( V_2 ) ;
struct V_40 * V_41 ;
struct V_42 * V_23 = V_2 -> V_23 ;
const struct V_43 * V_44 = F_16 () ;
V_35 -> V_45 = F_12 ( V_2 ) -> V_45 ;
if ( V_35 -> V_46 ) {
V_2 -> V_47 = V_48 ;
V_35 -> V_46 = false ;
}
V_35 -> V_49 = 0 ;
if ( F_13 ( V_2 , V_35 ) ) {
F_17 ( V_2 ) ;
V_44 -> V_50 ( V_2 ) ;
if ( F_18 ( V_2 ) -> error ) {
F_19 ( V_2 ) ;
return 0 ;
}
if ( F_18 ( V_2 ) -> V_23 == V_23 ) {
V_2 -> V_23 = V_35 -> V_51 ;
F_20 ( V_2 ) ;
F_21 ( V_2 ) ;
F_22 ( V_52 , V_53 ,
V_19 , V_39 , V_2 , V_2 -> V_23 , NULL ,
V_54 ,
1 ) ;
return 0 ;
}
F_23 ( F_24 ( V_2 ) -> V_55 , V_23 -> V_56 ) ;
V_2 -> V_47 = V_57 ;
} else {
V_41 = F_25 ( V_35 -> V_51 ) ;
if ( ! V_41 ) {
F_19 ( V_2 ) ;
return 0 ;
}
F_26 ( V_2 , & V_41 -> V_58 ) ;
}
V_2 -> V_23 = V_35 -> V_51 ;
F_20 ( V_2 ) ;
F_21 ( V_2 ) ;
F_22 ( V_52 , V_53 , V_19 , V_39 , V_2 ,
V_2 -> V_23 , NULL ,
V_59 , 1 ) ;
return 0 ;
}
unsigned int F_27 ( void * V_60 ,
struct V_1 * V_2 ,
const struct V_61 * V_62 )
{
struct V_34 * V_35 ;
if ( F_7 ( V_62 -> V_19 , V_2 ) )
return V_63 ;
F_28 ( V_2 -> V_35 ) ;
if ( ! F_29 ( V_2 ) )
return V_63 ;
if ( ! F_30 ( V_2 ) )
return V_63 ;
V_35 = F_15 ( V_2 ) ;
V_35 -> V_36 = F_2 ( V_2 ) -> V_37 ;
V_2 -> V_64 = F_31 ( V_65 ) ;
F_32 ( V_66 , V_67 , V_62 -> V_19 , V_62 -> V_39 , V_2 ,
V_2 -> V_23 , NULL ,
F_14 ) ;
return V_68 ;
}
