static int F_1 ( struct V_1 * V_2 , int V_3 )
{
const struct V_4 * V_5 = NULL ;
for (; ; ) {
struct V_6 * V_7 ;
int V_8 ;
if ( V_3 != V_9 ) {
V_5 = F_2 ( V_10 [ V_3 ] ) ;
if ( F_3 ( ! V_5 ) )
break;
if ( ! ( V_5 -> V_11 & V_12 ) )
break;
}
if ( F_3 ( ! F_4 ( V_2 , 8 ) ) )
break;
V_7 = ( void * ) V_2 -> V_13 ;
V_8 = F_5 ( V_7 ) ;
if ( F_3 ( ! F_4 ( V_2 , V_8 ) ) )
break;
V_3 = V_7 -> V_14 ;
F_6 ( V_2 , V_8 ) ;
}
return V_3 ;
}
static int F_7 ( struct V_1 * V_2 )
{
const struct V_15 * V_16 ;
const struct V_4 * V_5 ;
int V_17 = - V_18 ;
if ( F_3 ( ! F_4 ( V_2 , sizeof( * V_16 ) ) ) )
goto V_19;
V_16 = F_8 ( V_2 ) ;
F_6 ( V_2 , sizeof( * V_16 ) ) ;
V_17 = - V_20 ;
F_9 () ;
V_5 = F_2 ( V_10 [
F_1 ( V_2 , V_16 -> V_14 ) ] ) ;
if ( F_10 ( V_5 && V_5 -> V_21 . V_22 ) ) {
F_11 ( V_2 ) ;
V_17 = V_5 -> V_21 . V_22 ( V_2 ) ;
}
F_12 () ;
V_19:
return V_17 ;
}
static struct V_1 * F_13 ( struct V_1 * V_2 ,
T_1 V_23 )
{
struct V_1 * V_24 = F_14 ( - V_18 ) ;
struct V_15 * V_16 ;
const struct V_4 * V_5 ;
int V_3 ;
struct V_25 * V_26 ;
unsigned int V_27 ;
T_2 * V_28 ;
int V_29 = 0 ;
if ( ! ( V_23 & V_30 ) )
V_23 &= ~ V_31 ;
if ( F_3 ( F_15 ( V_2 ) -> V_32 &
~ ( V_33 |
V_34 |
V_35 |
V_36 |
0 ) ) )
goto V_19;
if ( F_3 ( ! F_4 ( V_2 , sizeof( * V_16 ) ) ) )
goto V_19;
V_16 = F_8 ( V_2 ) ;
F_6 ( V_2 , sizeof( * V_16 ) ) ;
V_24 = F_14 ( - V_20 ) ;
V_3 = F_1 ( V_2 , V_16 -> V_14 ) ;
F_9 () ;
V_5 = F_2 ( V_10 [ V_3 ] ) ;
if ( F_10 ( V_5 && V_5 -> V_21 . V_37 ) ) {
F_11 ( V_2 ) ;
V_24 = V_5 -> V_21 . V_37 ( V_2 , V_23 ) ;
}
F_12 () ;
if ( F_16 ( V_24 ) )
goto V_19;
for ( V_2 = V_24 ; V_2 ; V_2 = V_2 -> V_38 ) {
V_16 = F_8 ( V_2 ) ;
V_16 -> V_39 = F_17 ( V_2 -> V_8 - V_2 -> V_40 -
sizeof( * V_16 ) ) ;
if ( V_3 == V_41 ) {
V_27 = F_18 ( V_2 , & V_28 ) ;
V_26 = (struct V_25 * ) ( F_19 ( V_2 ) +
V_27 ) ;
V_26 -> V_42 = F_17 ( V_29 ) ;
if ( V_2 -> V_38 != NULL )
V_26 -> V_42 |= F_17 ( V_43 ) ;
V_29 += ( F_20 ( V_16 -> V_39 ) -
sizeof( struct V_25 ) ) ;
}
}
V_19:
return V_24 ;
}
static struct V_1 * * F_21 ( struct V_1 * * V_44 ,
struct V_1 * V_2 )
{
const struct V_4 * V_5 ;
struct V_1 * * V_45 = NULL ;
struct V_1 * V_46 ;
struct V_15 * V_47 ;
unsigned int V_48 ;
unsigned int V_49 ;
unsigned int V_50 ;
int V_51 = 1 ;
int V_3 ;
T_3 V_52 ;
V_50 = F_22 ( V_2 ) ;
V_49 = V_50 + sizeof( * V_47 ) ;
V_47 = F_23 ( V_2 , V_50 ) ;
if ( F_24 ( V_2 , V_49 ) ) {
V_47 = F_25 ( V_2 , V_49 , V_50 ) ;
if ( F_3 ( ! V_47 ) )
goto V_19;
}
F_26 ( V_2 , sizeof( * V_47 ) ) ;
F_27 ( V_2 , F_22 ( V_2 ) ) ;
V_51 += F_20 ( V_47 -> V_39 ) != F_28 ( V_2 ) ;
F_9 () ;
V_3 = V_47 -> V_14 ;
V_5 = F_2 ( V_10 [ V_3 ] ) ;
if ( ! V_5 || ! V_5 -> V_21 . V_53 ) {
F_29 ( V_2 , F_22 ( V_2 ) ) ;
V_3 = F_1 ( V_2 , V_3 ) ;
F_26 ( V_2 , - F_30 ( V_2 ) ) ;
F_11 ( V_2 ) ;
F_31 ( V_2 , F_22 ( V_2 ) ) ;
V_5 = F_2 ( V_10 [ V_3 ] ) ;
if ( ! V_5 || ! V_5 -> V_21 . V_53 )
goto V_54;
V_47 = F_8 ( V_2 ) ;
}
F_32 ( V_2 ) -> V_3 = V_3 ;
V_51 -- ;
V_48 = F_33 ( V_2 ) ;
for ( V_46 = * V_44 ; V_46 ; V_46 = V_46 -> V_38 ) {
const struct V_15 * V_55 ;
T_4 V_56 ;
if ( ! F_32 ( V_46 ) -> V_57 )
continue;
V_55 = F_8 ( V_46 ) ;
V_56 = * ( T_4 * ) V_47 ^ * ( T_4 * ) V_55 ;
if ( V_48 != F_33 ( V_46 ) ||
( V_56 & F_34 ( 0xF00FFFFF ) ) ||
memcmp ( & V_47 -> V_14 , & V_55 -> V_14 ,
V_48 - F_35 ( struct V_15 , V_14 ) ) ) {
F_32 ( V_46 ) -> V_57 = 0 ;
continue;
}
F_32 ( V_46 ) -> V_51 |= ! ! ( V_56 & F_34 ( 0x0FF00000 ) ) ;
F_32 ( V_46 ) -> V_51 |= V_51 ;
}
F_32 ( V_2 ) -> V_51 |= V_51 ;
V_52 = V_2 -> V_52 ;
F_36 ( V_2 , V_47 , F_33 ( V_2 ) ) ;
V_45 = V_5 -> V_21 . V_53 ( V_44 , V_2 ) ;
V_2 -> V_52 = V_52 ;
V_54:
F_12 () ;
V_19:
F_32 ( V_2 ) -> V_51 |= V_51 ;
return V_45 ;
}
static int F_37 ( struct V_1 * V_2 )
{
const struct V_4 * V_5 ;
struct V_15 * V_47 = F_8 ( V_2 ) ;
int V_17 = - V_58 ;
V_47 -> V_39 = F_17 ( V_2 -> V_8 - F_38 ( V_2 ) -
sizeof( * V_47 ) ) ;
F_9 () ;
V_5 = F_2 ( V_10 [ F_32 ( V_2 ) -> V_3 ] ) ;
if ( F_39 ( ! V_5 || ! V_5 -> V_21 . V_59 ) )
goto V_54;
V_17 = V_5 -> V_21 . V_59 ( V_2 ) ;
V_54:
F_12 () ;
return V_17 ;
}
static int T_5 F_40 ( void )
{
if ( F_41 () < 0 )
F_42 ( L_1 , V_60 ) ;
if ( F_43 () < 0 )
F_42 ( L_2 , V_60 ) ;
if ( F_44 () < 0 )
F_42 ( L_3 , V_60 ) ;
F_45 ( & V_61 ) ;
return 0 ;
}
