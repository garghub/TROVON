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
unsigned int V_23 ;
T_2 * V_24 ;
int V_25 = 0 ;
bool V_26 , V_27 ;
int V_28 ;
bool V_29 ;
F_9 ( V_2 ) ;
V_28 = F_10 ( V_2 ) - F_11 ( V_2 ) ;
if ( F_3 ( ! F_4 ( V_2 , sizeof( * V_19 ) ) ) )
goto V_30;
V_26 = F_12 ( V_2 ) -> V_31 > 0 ;
if ( V_26 )
V_15 &= V_2 -> V_32 -> V_33 ;
F_12 ( V_2 ) -> V_31 += sizeof( * V_19 ) ;
V_19 = F_13 ( V_2 ) ;
F_6 ( V_2 , sizeof( * V_19 ) ) ;
V_16 = F_8 ( - V_34 ) ;
V_3 = F_1 ( V_2 , V_19 -> V_14 ) ;
if ( V_2 -> V_35 &&
F_14 ( V_2 ) -> V_36 & ( V_37 | V_38 ) )
V_27 = V_3 == V_39 && V_26 ;
else
V_27 = V_3 == V_39 && ! V_2 -> V_35 ;
V_5 = F_2 ( V_10 [ V_3 ] ) ;
if ( F_15 ( V_5 && V_5 -> V_40 . V_41 ) ) {
F_16 ( V_2 ) ;
V_16 = V_5 -> V_40 . V_41 ( V_2 , V_15 ) ;
}
if ( F_17 ( V_16 ) )
goto V_30;
V_29 = ! ! ( F_14 ( V_16 ) -> V_36 & V_42 ) ;
for ( V_2 = V_16 ; V_2 ; V_2 = V_2 -> V_43 ) {
V_19 = (struct V_18 * ) ( F_11 ( V_2 ) + V_28 ) ;
if ( V_29 )
V_23 = F_14 ( V_2 ) -> V_44 +
F_12 ( V_2 ) -> V_45 +
V_2 -> V_46 - ( unsigned char * ) ( V_19 + 1 ) ;
else
V_23 = V_2 -> V_8 - V_28 - sizeof( * V_19 ) ;
V_19 -> V_23 = F_18 ( V_23 ) ;
V_2 -> V_47 = ( T_2 * ) V_19 - V_2 -> V_46 ;
if ( V_27 ) {
V_22 = F_19 ( V_2 , & V_24 ) ;
V_21 = (struct V_20 * ) ( ( T_2 * ) V_19 + V_22 ) ;
V_21 -> V_48 = F_18 ( V_25 ) ;
if ( V_2 -> V_43 )
V_21 -> V_48 |= F_18 ( V_49 ) ;
V_25 += ( F_20 ( V_19 -> V_23 ) -
sizeof( struct V_20 ) ) ;
}
if ( V_26 )
F_21 ( V_2 ) ;
}
V_30:
return V_16 ;
}
static int F_22 ( struct V_18 * V_50 ,
const struct V_4 * * V_51 )
{
struct V_6 * V_7 = ( void * ) V_50 ;
int V_8 = 0 , V_3 , V_52 = sizeof( * V_50 ) ;
V_3 = V_50 -> V_14 ;
for (; ; ) {
if ( V_3 != V_9 ) {
* V_51 = F_2 ( V_10 [ V_3 ] ) ;
if ( F_3 ( ! ( * V_51 ) ) )
break;
if ( ! ( ( * V_51 ) -> V_11 & V_12 ) )
break;
}
V_7 = ( void * ) V_7 + V_52 ;
V_52 = F_5 ( V_7 ) ;
V_8 += V_52 ;
V_3 = V_7 -> V_14 ;
}
return V_8 ;
}
static struct V_1 * * F_23 ( struct V_1 * * V_46 ,
struct V_1 * V_2 )
{
const struct V_4 * V_5 ;
struct V_1 * * V_53 = NULL ;
struct V_1 * V_54 ;
struct V_18 * V_50 ;
unsigned int V_55 ;
unsigned int V_56 ;
unsigned int V_57 ;
T_3 V_58 = 1 ;
int V_3 ;
V_57 = F_24 ( V_2 ) ;
V_56 = V_57 + sizeof( * V_50 ) ;
V_50 = F_25 ( V_2 , V_57 ) ;
if ( F_26 ( V_2 , V_56 ) ) {
V_50 = F_27 ( V_2 , V_56 , V_57 ) ;
if ( F_3 ( ! V_50 ) )
goto V_30;
}
F_28 ( V_2 , V_57 ) ;
F_29 ( V_2 , sizeof( * V_50 ) ) ;
F_30 ( V_2 , F_24 ( V_2 ) ) ;
V_58 += F_20 ( V_50 -> V_23 ) != F_31 ( V_2 ) ;
F_32 () ;
V_3 = V_50 -> V_14 ;
V_5 = F_2 ( V_10 [ V_3 ] ) ;
if ( ! V_5 || ! V_5 -> V_40 . V_59 ) {
F_33 ( V_2 , F_24 ( V_2 ) ) ;
F_34 ( V_2 ) ;
V_3 = F_1 ( V_2 , V_3 ) ;
F_29 ( V_2 , - F_35 ( V_2 ) ) ;
F_16 ( V_2 ) ;
F_36 ( V_2 , F_24 ( V_2 ) ) ;
V_5 = F_2 ( V_10 [ V_3 ] ) ;
if ( ! V_5 || ! V_5 -> V_40 . V_59 )
goto V_60;
V_50 = F_13 ( V_2 ) ;
}
F_37 ( V_2 ) -> V_3 = V_3 ;
V_58 -- ;
V_55 = F_38 ( V_2 ) ;
for ( V_54 = * V_46 ; V_54 ; V_54 = V_54 -> V_43 ) {
const struct V_18 * V_61 ;
T_4 V_62 ;
if ( ! F_37 ( V_54 ) -> V_63 )
continue;
V_61 = (struct V_18 * ) ( V_54 -> V_13 + V_57 ) ;
V_62 = * ( T_4 * ) V_50 ^ * ( T_4 * ) V_61 ;
if ( ( V_62 & F_39 ( 0xF00FFFFF ) ) ||
memcmp ( & V_50 -> V_14 , & V_61 -> V_14 ,
V_55 - F_40 ( struct V_18 , V_14 ) ) ) {
F_37 ( V_54 ) -> V_63 = 0 ;
continue;
}
F_37 ( V_54 ) -> V_58 |= ! ! ( V_62 & F_39 ( 0x0FF00000 ) ) ;
F_37 ( V_54 ) -> V_58 |= V_58 ;
if ( F_37 ( V_2 ) -> V_64 )
F_37 ( V_54 ) -> V_65 = 0 ;
}
F_37 ( V_2 ) -> V_64 = true ;
F_37 ( V_2 ) -> V_58 |= V_58 ;
F_41 ( V_2 , V_50 , V_55 ) ;
V_53 = F_42 ( V_5 -> V_40 . V_59 , V_46 , V_2 ) ;
V_60:
F_43 () ;
V_30:
F_44 ( V_2 , V_53 , V_58 ) ;
return V_53 ;
}
static struct V_1 * * F_45 ( struct V_1 * * V_46 ,
struct V_1 * V_2 )
{
if ( F_37 ( V_2 ) -> V_66 ) {
F_37 ( V_2 ) -> V_58 = 1 ;
return NULL ;
}
F_37 ( V_2 ) -> V_66 = 1 ;
return F_23 ( V_46 , V_2 ) ;
}
static struct V_1 * * F_46 ( struct V_1 * * V_46 ,
struct V_1 * V_2 )
{
if ( F_37 ( V_2 ) -> V_66 ) {
F_37 ( V_2 ) -> V_58 = 1 ;
return NULL ;
}
F_37 ( V_2 ) -> V_66 = 1 ;
return F_47 ( V_46 , V_2 ) ;
}
static int F_48 ( struct V_1 * V_2 , int V_28 )
{
const struct V_4 * V_5 ;
struct V_18 * V_50 = (struct V_18 * ) ( V_2 -> V_13 + V_28 ) ;
int V_67 = - V_68 ;
if ( V_2 -> V_35 ) {
F_49 ( V_2 , F_50 ( V_69 ) ) ;
F_51 ( V_2 , V_28 ) ;
}
V_50 -> V_23 = F_18 ( V_2 -> V_8 - V_28 - sizeof( * V_50 ) ) ;
F_32 () ;
V_28 += sizeof( * V_50 ) + F_22 ( V_50 , & V_5 ) ;
if ( F_52 ( ! V_5 || ! V_5 -> V_40 . V_70 ) )
goto V_60;
V_67 = V_5 -> V_40 . V_70 ( V_2 , V_28 ) ;
V_60:
F_43 () ;
return V_67 ;
}
static int F_53 ( struct V_1 * V_2 , int V_28 )
{
V_2 -> V_35 = 1 ;
F_14 ( V_2 ) -> V_36 |= V_37 ;
return F_48 ( V_2 , V_28 ) ;
}
static int F_54 ( struct V_1 * V_2 , int V_28 )
{
V_2 -> V_35 = 1 ;
F_14 ( V_2 ) -> V_36 |= V_38 ;
return F_48 ( V_2 , V_28 ) ;
}
static int F_55 ( struct V_1 * V_2 , int V_28 )
{
V_2 -> V_35 = 1 ;
F_14 ( V_2 ) -> V_36 |= V_38 ;
return F_56 ( V_2 , V_28 ) ;
}
static int T_5 F_57 ( void )
{
if ( F_58 () < 0 )
F_59 ( L_1 , V_71 ) ;
if ( F_60 () < 0 )
F_59 ( L_2 , V_71 ) ;
F_61 ( & V_72 ) ;
F_62 ( & V_73 , V_74 ) ;
F_63 ( & V_75 , V_74 ) ;
F_63 ( & V_76 , V_77 ) ;
return 0 ;
}
