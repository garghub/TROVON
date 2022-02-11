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
V_7 = ( void * ) V_2 -> V_13 ;
V_3 = V_7 -> V_14 ;
F_6 ( V_2 , V_8 ) ;
}
return V_3 ;
}
static struct V_1 * F_7 ( struct V_1 * V_2 ,
T_1 V_15 )
{
struct V_1 * V_16 = F_8 ( - V_17 ) ;
struct V_18 * V_19 ;
const struct V_4 * V_5 ;
int V_3 ;
struct V_20 * V_21 ;
unsigned int V_22 ;
T_2 * V_23 ;
int V_24 = 0 ;
bool V_25 , V_26 ;
int V_27 ;
if ( F_3 ( F_9 ( V_2 ) -> V_28 &
~ ( V_29 |
V_30 |
V_31 |
V_32 |
V_33 |
V_34 |
V_35 |
V_36 |
V_37 |
V_38 |
V_39 |
V_40 |
0 ) ) )
goto V_41;
F_10 ( V_2 ) ;
V_27 = F_11 ( V_2 ) - F_12 ( V_2 ) ;
if ( F_3 ( ! F_4 ( V_2 , sizeof( * V_19 ) ) ) )
goto V_41;
V_25 = F_13 ( V_2 ) -> V_42 > 0 ;
if ( V_25 )
V_15 &= V_2 -> V_43 -> V_44 ;
F_13 ( V_2 ) -> V_42 += sizeof( * V_19 ) ;
V_19 = F_14 ( V_2 ) ;
F_6 ( V_2 , sizeof( * V_19 ) ) ;
V_16 = F_8 ( - V_45 ) ;
V_3 = F_1 ( V_2 , V_19 -> V_14 ) ;
if ( V_2 -> V_46 &&
F_9 ( V_2 ) -> V_28 & ( V_36 | V_35 ) )
V_26 = V_3 == V_47 && V_25 ;
else
V_26 = V_3 == V_47 && ! V_2 -> V_46 ;
V_5 = F_2 ( V_10 [ V_3 ] ) ;
if ( F_15 ( V_5 && V_5 -> V_48 . V_49 ) ) {
F_16 ( V_2 ) ;
V_16 = V_5 -> V_48 . V_49 ( V_2 , V_15 ) ;
}
if ( F_17 ( V_16 ) )
goto V_41;
for ( V_2 = V_16 ; V_2 ; V_2 = V_2 -> V_50 ) {
V_19 = (struct V_18 * ) ( F_12 ( V_2 ) + V_27 ) ;
V_19 -> V_51 = F_18 ( V_2 -> V_8 - V_27 - sizeof( * V_19 ) ) ;
V_2 -> V_52 = ( T_2 * ) V_19 - V_2 -> V_53 ;
if ( V_26 ) {
V_22 = F_19 ( V_2 , & V_23 ) ;
V_21 = (struct V_20 * ) ( ( T_2 * ) V_19 + V_22 ) ;
V_21 -> V_54 = F_18 ( V_24 ) ;
if ( V_2 -> V_50 != NULL )
V_21 -> V_54 |= F_18 ( V_55 ) ;
V_24 += ( F_20 ( V_19 -> V_51 ) -
sizeof( struct V_20 ) ) ;
}
if ( V_25 )
F_21 ( V_2 ) ;
}
V_41:
return V_16 ;
}
static int F_22 ( struct V_18 * V_56 ,
const struct V_4 * * V_57 )
{
struct V_6 * V_7 = ( void * ) V_56 ;
int V_8 = 0 , V_3 , V_58 = sizeof( * V_56 ) ;
V_3 = V_56 -> V_14 ;
for (; ; ) {
if ( V_3 != V_9 ) {
* V_57 = F_2 ( V_10 [ V_3 ] ) ;
if ( F_3 ( ! ( * V_57 ) ) )
break;
if ( ! ( ( * V_57 ) -> V_11 & V_12 ) )
break;
}
V_7 = ( void * ) V_7 + V_58 ;
V_58 = F_5 ( V_7 ) ;
V_8 += V_58 ;
V_3 = V_7 -> V_14 ;
}
return V_8 ;
}
static struct V_1 * * F_23 ( struct V_1 * * V_53 ,
struct V_1 * V_2 )
{
const struct V_4 * V_5 ;
struct V_1 * * V_59 = NULL ;
struct V_1 * V_60 ;
struct V_18 * V_56 ;
unsigned int V_61 ;
unsigned int V_62 ;
unsigned int V_63 ;
T_3 V_64 = 1 ;
int V_3 ;
V_63 = F_24 ( V_2 ) ;
V_62 = V_63 + sizeof( * V_56 ) ;
V_56 = F_25 ( V_2 , V_63 ) ;
if ( F_26 ( V_2 , V_62 ) ) {
V_56 = F_27 ( V_2 , V_62 , V_63 ) ;
if ( F_3 ( ! V_56 ) )
goto V_41;
}
F_28 ( V_2 , V_63 ) ;
F_29 ( V_2 , sizeof( * V_56 ) ) ;
F_30 ( V_2 , F_24 ( V_2 ) ) ;
V_64 += F_20 ( V_56 -> V_51 ) != F_31 ( V_2 ) ;
F_32 () ;
V_3 = V_56 -> V_14 ;
V_5 = F_2 ( V_10 [ V_3 ] ) ;
if ( ! V_5 || ! V_5 -> V_48 . V_65 ) {
F_33 ( V_2 , F_24 ( V_2 ) ) ;
V_3 = F_1 ( V_2 , V_3 ) ;
F_29 ( V_2 , - F_34 ( V_2 ) ) ;
F_16 ( V_2 ) ;
F_35 ( V_2 , F_24 ( V_2 ) ) ;
V_5 = F_2 ( V_10 [ V_3 ] ) ;
if ( ! V_5 || ! V_5 -> V_48 . V_65 )
goto V_66;
V_56 = F_14 ( V_2 ) ;
}
F_36 ( V_2 ) -> V_3 = V_3 ;
V_64 -- ;
V_61 = F_37 ( V_2 ) ;
for ( V_60 = * V_53 ; V_60 ; V_60 = V_60 -> V_50 ) {
const struct V_18 * V_67 ;
T_4 V_68 ;
if ( ! F_36 ( V_60 ) -> V_69 )
continue;
V_67 = (struct V_18 * ) ( V_60 -> V_13 + V_63 ) ;
V_68 = * ( T_4 * ) V_56 ^ * ( T_4 * ) V_67 ;
if ( ( V_68 & F_38 ( 0xF00FFFFF ) ) ||
memcmp ( & V_56 -> V_14 , & V_67 -> V_14 ,
V_61 - F_39 ( struct V_18 , V_14 ) ) ) {
F_36 ( V_60 ) -> V_69 = 0 ;
continue;
}
F_36 ( V_60 ) -> V_64 |= ! ! ( V_68 & F_38 ( 0x0FF00000 ) ) ;
F_36 ( V_60 ) -> V_64 |= V_64 ;
F_36 ( V_60 ) -> V_70 = 0 ;
}
F_36 ( V_2 ) -> V_64 |= V_64 ;
F_40 ( V_2 , V_56 , V_61 ) ;
V_59 = V_5 -> V_48 . V_65 ( V_53 , V_2 ) ;
V_66:
F_41 () ;
V_41:
F_36 ( V_2 ) -> V_64 |= V_64 ;
return V_59 ;
}
static int F_42 ( struct V_1 * V_2 , int V_27 )
{
const struct V_4 * V_5 ;
struct V_18 * V_56 = (struct V_18 * ) ( V_2 -> V_13 + V_27 ) ;
int V_71 = - V_72 ;
V_56 -> V_51 = F_18 ( V_2 -> V_8 - V_27 - sizeof( * V_56 ) ) ;
F_32 () ;
V_27 += sizeof( * V_56 ) + F_22 ( V_56 , & V_5 ) ;
if ( F_43 ( ! V_5 || ! V_5 -> V_48 . V_73 ) )
goto V_66;
V_71 = V_5 -> V_48 . V_73 ( V_2 , V_27 ) ;
V_66:
F_41 () ;
return V_71 ;
}
static int T_5 F_44 ( void )
{
if ( F_45 () < 0 )
F_46 ( L_1 , V_74 ) ;
if ( F_47 () < 0 )
F_46 ( L_2 , V_74 ) ;
if ( F_48 () < 0 )
F_46 ( L_3 , V_74 ) ;
F_49 ( & V_75 ) ;
F_50 ( & V_76 , V_77 ) ;
return 0 ;
}
