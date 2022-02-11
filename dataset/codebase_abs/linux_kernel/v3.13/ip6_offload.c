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
V_5 = F_2 ( V_10 [
F_1 ( V_2 , V_16 -> V_14 ) ] ) ;
if ( F_9 ( V_5 && V_5 -> V_21 . V_22 ) ) {
F_10 ( V_2 ) ;
V_17 = V_5 -> V_21 . V_22 ( V_2 ) ;
}
V_19:
return V_17 ;
}
static struct V_1 * F_11 ( struct V_1 * V_2 ,
T_1 V_23 )
{
struct V_1 * V_24 = F_12 ( - V_18 ) ;
struct V_15 * V_16 ;
const struct V_4 * V_5 ;
int V_3 ;
struct V_25 * V_26 ;
unsigned int V_27 ;
T_2 * V_28 ;
int V_29 = 0 ;
bool V_30 ;
int V_31 ;
if ( F_3 ( F_13 ( V_2 ) -> V_32 &
~ ( V_33 |
V_34 |
V_35 |
V_36 |
V_37 |
V_38 |
V_39 |
V_40 |
V_41 |
0 ) ) )
goto V_19;
F_14 ( V_2 ) ;
V_31 = F_15 ( V_2 ) - F_16 ( V_2 ) ;
if ( F_3 ( ! F_4 ( V_2 , sizeof( * V_16 ) ) ) )
goto V_19;
V_30 = F_17 ( V_2 ) -> V_42 > 0 ;
if ( V_30 )
V_23 = V_2 -> V_43 -> V_44 & F_18 ( V_2 ) ;
F_17 ( V_2 ) -> V_42 += sizeof( * V_16 ) ;
V_16 = F_8 ( V_2 ) ;
F_6 ( V_2 , sizeof( * V_16 ) ) ;
V_24 = F_12 ( - V_20 ) ;
V_3 = F_1 ( V_2 , V_16 -> V_14 ) ;
V_5 = F_2 ( V_10 [ V_3 ] ) ;
if ( F_9 ( V_5 && V_5 -> V_21 . V_45 ) ) {
F_10 ( V_2 ) ;
V_24 = V_5 -> V_21 . V_45 ( V_2 , V_23 ) ;
}
if ( F_19 ( V_24 ) )
goto V_19;
for ( V_2 = V_24 ; V_2 ; V_2 = V_2 -> V_46 ) {
V_16 = (struct V_15 * ) ( F_16 ( V_2 ) + V_31 ) ;
V_16 -> V_47 = F_20 ( V_2 -> V_8 - V_31 - sizeof( * V_16 ) ) ;
if ( V_30 ) {
F_21 ( V_2 ) ;
V_2 -> V_48 = 1 ;
}
V_2 -> V_49 = ( T_2 * ) V_16 - V_2 -> V_50 ;
if ( ! V_30 && V_3 == V_51 ) {
V_27 = F_22 ( V_2 , & V_28 ) ;
V_26 = (struct V_25 * ) ( ( T_2 * ) V_16 + V_27 ) ;
V_26 -> V_52 = F_20 ( V_29 ) ;
if ( V_2 -> V_46 != NULL )
V_26 -> V_52 |= F_20 ( V_53 ) ;
V_29 += ( F_23 ( V_16 -> V_47 ) -
sizeof( struct V_25 ) ) ;
}
}
V_19:
return V_24 ;
}
static struct V_1 * * F_24 ( struct V_1 * * V_50 ,
struct V_1 * V_2 )
{
const struct V_4 * V_5 ;
struct V_1 * * V_54 = NULL ;
struct V_1 * V_55 ;
struct V_15 * V_56 ;
unsigned int V_57 ;
unsigned int V_58 ;
unsigned int V_59 ;
int V_60 = 1 ;
int V_3 ;
T_3 V_61 ;
V_59 = F_25 ( V_2 ) ;
V_58 = V_59 + sizeof( * V_56 ) ;
V_56 = F_26 ( V_2 , V_59 ) ;
if ( F_27 ( V_2 , V_58 ) ) {
V_56 = F_28 ( V_2 , V_58 , V_59 ) ;
if ( F_3 ( ! V_56 ) )
goto V_19;
}
F_29 ( V_2 , sizeof( * V_56 ) ) ;
F_30 ( V_2 , F_25 ( V_2 ) ) ;
V_60 += F_23 ( V_56 -> V_47 ) != F_31 ( V_2 ) ;
F_32 () ;
V_3 = V_56 -> V_14 ;
V_5 = F_2 ( V_10 [ V_3 ] ) ;
if ( ! V_5 || ! V_5 -> V_21 . V_62 ) {
F_33 ( V_2 , F_25 ( V_2 ) ) ;
V_3 = F_1 ( V_2 , V_3 ) ;
F_29 ( V_2 , - F_34 ( V_2 ) ) ;
F_10 ( V_2 ) ;
F_35 ( V_2 , F_25 ( V_2 ) ) ;
V_5 = F_2 ( V_10 [ V_3 ] ) ;
if ( ! V_5 || ! V_5 -> V_21 . V_62 )
goto V_63;
V_56 = F_8 ( V_2 ) ;
}
F_36 ( V_2 ) -> V_3 = V_3 ;
V_60 -- ;
V_57 = F_37 ( V_2 ) ;
for ( V_55 = * V_50 ; V_55 ; V_55 = V_55 -> V_46 ) {
const struct V_15 * V_64 ;
T_4 V_65 ;
if ( ! F_36 ( V_55 ) -> V_66 )
continue;
V_64 = F_8 ( V_55 ) ;
V_65 = * ( T_4 * ) V_56 ^ * ( T_4 * ) V_64 ;
if ( V_57 != F_37 ( V_55 ) ||
( V_65 & F_38 ( 0xF00FFFFF ) ) ||
memcmp ( & V_56 -> V_14 , & V_64 -> V_14 ,
V_57 - F_39 ( struct V_15 , V_14 ) ) ) {
F_36 ( V_55 ) -> V_66 = 0 ;
continue;
}
F_36 ( V_55 ) -> V_60 |= ! ! ( V_65 & F_38 ( 0x0FF00000 ) ) ;
F_36 ( V_55 ) -> V_60 |= V_60 ;
}
F_36 ( V_2 ) -> V_60 |= V_60 ;
V_61 = V_2 -> V_61 ;
F_40 ( V_2 , V_56 , F_37 ( V_2 ) ) ;
V_54 = V_5 -> V_21 . V_62 ( V_50 , V_2 ) ;
V_2 -> V_61 = V_61 ;
V_63:
F_41 () ;
V_19:
F_36 ( V_2 ) -> V_60 |= V_60 ;
return V_54 ;
}
static int F_42 ( struct V_1 * V_2 )
{
const struct V_4 * V_5 ;
struct V_15 * V_56 = F_8 ( V_2 ) ;
int V_17 = - V_67 ;
V_56 -> V_47 = F_20 ( V_2 -> V_8 - F_43 ( V_2 ) -
sizeof( * V_56 ) ) ;
F_32 () ;
V_5 = F_2 ( V_10 [ F_36 ( V_2 ) -> V_3 ] ) ;
if ( F_44 ( ! V_5 || ! V_5 -> V_21 . V_68 ) )
goto V_63;
V_17 = V_5 -> V_21 . V_68 ( V_2 ) ;
V_63:
F_41 () ;
return V_17 ;
}
static int T_5 F_45 ( void )
{
if ( F_46 () < 0 )
F_47 ( L_1 , V_69 ) ;
if ( F_48 () < 0 )
F_47 ( L_2 , V_69 ) ;
if ( F_49 () < 0 )
F_47 ( L_3 , V_69 ) ;
F_50 ( & V_70 ) ;
F_51 ( & V_71 , V_72 ) ;
return 0 ;
}
