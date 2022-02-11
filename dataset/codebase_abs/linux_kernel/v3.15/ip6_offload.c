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
bool V_30 , V_31 ;
int V_32 ;
if ( F_3 ( F_13 ( V_2 ) -> V_33 &
~ ( V_34 |
V_35 |
V_36 |
V_37 |
V_38 |
V_39 |
V_40 |
V_41 |
V_42 |
0 ) ) )
goto V_19;
F_14 ( V_2 ) ;
V_32 = F_15 ( V_2 ) - F_16 ( V_2 ) ;
if ( F_3 ( ! F_4 ( V_2 , sizeof( * V_16 ) ) ) )
goto V_19;
V_30 = F_17 ( V_2 ) -> V_43 > 0 ;
if ( V_30 )
V_23 = V_2 -> V_44 -> V_45 & F_18 ( V_2 ) ;
F_17 ( V_2 ) -> V_43 += sizeof( * V_16 ) ;
V_16 = F_8 ( V_2 ) ;
F_6 ( V_2 , sizeof( * V_16 ) ) ;
V_24 = F_12 ( - V_20 ) ;
V_3 = F_1 ( V_2 , V_16 -> V_14 ) ;
if ( V_2 -> V_46 &&
F_13 ( V_2 ) -> V_33 & ( V_39 | V_38 ) )
V_31 = V_3 == V_47 && V_30 ;
else
V_31 = V_3 == V_47 && ! V_2 -> V_46 ;
V_5 = F_2 ( V_10 [ V_3 ] ) ;
if ( F_9 ( V_5 && V_5 -> V_21 . V_48 ) ) {
F_10 ( V_2 ) ;
V_24 = V_5 -> V_21 . V_48 ( V_2 , V_23 ) ;
}
if ( F_19 ( V_24 ) )
goto V_19;
for ( V_2 = V_24 ; V_2 ; V_2 = V_2 -> V_49 ) {
V_16 = (struct V_15 * ) ( F_16 ( V_2 ) + V_32 ) ;
V_16 -> V_50 = F_20 ( V_2 -> V_8 - V_32 - sizeof( * V_16 ) ) ;
V_2 -> V_51 = ( T_2 * ) V_16 - V_2 -> V_52 ;
if ( V_31 ) {
V_27 = F_21 ( V_2 , & V_28 ) ;
V_26 = (struct V_25 * ) ( ( T_2 * ) V_16 + V_27 ) ;
V_26 -> V_53 = F_20 ( V_29 ) ;
if ( V_2 -> V_49 != NULL )
V_26 -> V_53 |= F_20 ( V_54 ) ;
V_29 += ( F_22 ( V_16 -> V_50 ) -
sizeof( struct V_25 ) ) ;
}
if ( V_30 )
F_23 ( V_2 ) ;
}
V_19:
return V_24 ;
}
static int F_24 ( struct V_15 * V_55 ,
const struct V_4 * * V_56 )
{
struct V_6 * V_7 = ( void * ) V_55 ;
int V_8 = 0 , V_3 , V_57 = sizeof( * V_55 ) ;
V_3 = V_55 -> V_14 ;
for (; ; ) {
if ( V_3 != V_9 ) {
* V_56 = F_2 ( V_10 [ V_3 ] ) ;
if ( F_3 ( ! ( * V_56 ) ) )
break;
if ( ! ( ( * V_56 ) -> V_11 & V_12 ) )
break;
}
V_7 = ( void * ) V_7 + V_57 ;
V_57 = F_5 ( V_7 ) ;
V_8 += V_57 ;
V_3 = V_7 -> V_14 ;
}
return V_8 ;
}
static struct V_1 * * F_25 ( struct V_1 * * V_52 ,
struct V_1 * V_2 )
{
const struct V_4 * V_5 ;
struct V_1 * * V_58 = NULL ;
struct V_1 * V_59 ;
struct V_15 * V_55 ;
unsigned int V_60 ;
unsigned int V_61 ;
unsigned int V_62 ;
T_3 V_63 = 1 ;
int V_3 ;
V_62 = F_26 ( V_2 ) ;
V_61 = V_62 + sizeof( * V_55 ) ;
V_55 = F_27 ( V_2 , V_62 ) ;
if ( F_28 ( V_2 , V_61 ) ) {
V_55 = F_29 ( V_2 , V_61 , V_62 ) ;
if ( F_3 ( ! V_55 ) )
goto V_19;
}
F_30 ( V_2 , V_62 ) ;
F_31 ( V_2 , sizeof( * V_55 ) ) ;
F_32 ( V_2 , F_26 ( V_2 ) ) ;
V_63 += F_22 ( V_55 -> V_50 ) != F_33 ( V_2 ) ;
F_34 () ;
V_3 = V_55 -> V_14 ;
V_5 = F_2 ( V_10 [ V_3 ] ) ;
if ( ! V_5 || ! V_5 -> V_21 . V_64 ) {
F_35 ( V_2 , F_26 ( V_2 ) ) ;
V_3 = F_1 ( V_2 , V_3 ) ;
F_31 ( V_2 , - F_36 ( V_2 ) ) ;
F_10 ( V_2 ) ;
F_37 ( V_2 , F_26 ( V_2 ) ) ;
V_5 = F_2 ( V_10 [ V_3 ] ) ;
if ( ! V_5 || ! V_5 -> V_21 . V_64 )
goto V_65;
V_55 = F_8 ( V_2 ) ;
}
F_38 ( V_2 ) -> V_3 = V_3 ;
V_63 -- ;
V_60 = F_39 ( V_2 ) ;
for ( V_59 = * V_52 ; V_59 ; V_59 = V_59 -> V_49 ) {
const struct V_15 * V_66 ;
T_4 V_67 ;
if ( ! F_38 ( V_59 ) -> V_68 )
continue;
V_66 = (struct V_15 * ) ( V_59 -> V_13 + V_62 ) ;
V_67 = * ( T_4 * ) V_55 ^ * ( T_4 * ) V_66 ;
if ( ( V_67 & F_40 ( 0xF00FFFFF ) ) ||
memcmp ( & V_55 -> V_14 , & V_66 -> V_14 ,
V_60 - F_41 ( struct V_15 , V_14 ) ) ) {
F_38 ( V_59 ) -> V_68 = 0 ;
continue;
}
F_38 ( V_59 ) -> V_63 |= ! ! ( V_67 & F_40 ( 0x0FF00000 ) ) ;
F_38 ( V_59 ) -> V_63 |= V_63 ;
}
F_38 ( V_2 ) -> V_63 |= V_63 ;
F_42 ( V_2 , V_55 , V_60 ) ;
V_58 = V_5 -> V_21 . V_64 ( V_52 , V_2 ) ;
V_65:
F_43 () ;
V_19:
F_38 ( V_2 ) -> V_63 |= V_63 ;
return V_58 ;
}
static int F_44 ( struct V_1 * V_2 , int V_32 )
{
const struct V_4 * V_5 ;
struct V_15 * V_55 = (struct V_15 * ) ( V_2 -> V_13 + V_32 ) ;
int V_17 = - V_69 ;
V_55 -> V_50 = F_20 ( V_2 -> V_8 - V_32 - sizeof( * V_55 ) ) ;
F_34 () ;
V_32 += sizeof( * V_55 ) + F_24 ( V_55 , & V_5 ) ;
if ( F_45 ( ! V_5 || ! V_5 -> V_21 . V_70 ) )
goto V_65;
V_17 = V_5 -> V_21 . V_70 ( V_2 , V_32 ) ;
V_65:
F_43 () ;
return V_17 ;
}
static int T_5 F_46 ( void )
{
if ( F_47 () < 0 )
F_48 ( L_1 , V_71 ) ;
if ( F_49 () < 0 )
F_48 ( L_2 , V_71 ) ;
if ( F_50 () < 0 )
F_48 ( L_3 , V_71 ) ;
F_51 ( & V_72 ) ;
F_52 ( & V_73 , V_74 ) ;
return 0 ;
}
