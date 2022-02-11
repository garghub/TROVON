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
F_9 ( V_2 ) ;
V_28 = F_10 ( V_2 ) - F_11 ( V_2 ) ;
if ( F_3 ( ! F_4 ( V_2 , sizeof( * V_19 ) ) ) )
goto V_29;
V_26 = F_12 ( V_2 ) -> V_30 > 0 ;
if ( V_26 )
V_15 &= V_2 -> V_31 -> V_32 ;
F_12 ( V_2 ) -> V_30 += sizeof( * V_19 ) ;
V_19 = F_13 ( V_2 ) ;
F_6 ( V_2 , sizeof( * V_19 ) ) ;
V_16 = F_8 ( - V_33 ) ;
V_3 = F_1 ( V_2 , V_19 -> V_14 ) ;
if ( V_2 -> V_34 &&
F_14 ( V_2 ) -> V_35 & ( V_36 | V_37 ) )
V_27 = V_3 == V_38 && V_26 ;
else
V_27 = V_3 == V_38 && ! V_2 -> V_34 ;
V_5 = F_2 ( V_10 [ V_3 ] ) ;
if ( F_15 ( V_5 && V_5 -> V_39 . V_40 ) ) {
F_16 ( V_2 ) ;
V_16 = V_5 -> V_39 . V_40 ( V_2 , V_15 ) ;
}
if ( F_17 ( V_16 ) )
goto V_29;
for ( V_2 = V_16 ; V_2 ; V_2 = V_2 -> V_41 ) {
V_19 = (struct V_18 * ) ( F_11 ( V_2 ) + V_28 ) ;
if ( F_18 ( V_2 ) )
V_23 = F_14 ( V_2 ) -> V_42 +
F_12 ( V_2 ) -> V_43 +
V_2 -> V_44 - ( unsigned char * ) ( V_19 + 1 ) ;
else
V_23 = V_2 -> V_8 - V_28 - sizeof( * V_19 ) ;
V_19 -> V_23 = F_19 ( V_23 ) ;
V_2 -> V_45 = ( T_2 * ) V_19 - V_2 -> V_44 ;
if ( V_27 ) {
V_22 = F_20 ( V_2 , & V_24 ) ;
V_21 = (struct V_20 * ) ( ( T_2 * ) V_19 + V_22 ) ;
V_21 -> V_46 = F_19 ( V_25 ) ;
if ( V_2 -> V_41 )
V_21 -> V_46 |= F_19 ( V_47 ) ;
V_25 += ( F_21 ( V_19 -> V_23 ) -
sizeof( struct V_20 ) ) ;
}
if ( V_26 )
F_22 ( V_2 ) ;
}
V_29:
return V_16 ;
}
static int F_23 ( struct V_18 * V_48 ,
const struct V_4 * * V_49 )
{
struct V_6 * V_7 = ( void * ) V_48 ;
int V_8 = 0 , V_3 , V_50 = sizeof( * V_48 ) ;
V_3 = V_48 -> V_14 ;
for (; ; ) {
if ( V_3 != V_9 ) {
* V_49 = F_2 ( V_10 [ V_3 ] ) ;
if ( F_3 ( ! ( * V_49 ) ) )
break;
if ( ! ( ( * V_49 ) -> V_11 & V_12 ) )
break;
}
V_7 = ( void * ) V_7 + V_50 ;
V_50 = F_5 ( V_7 ) ;
V_8 += V_50 ;
V_3 = V_7 -> V_14 ;
}
return V_8 ;
}
static struct V_1 * * F_24 ( struct V_1 * * V_44 ,
struct V_1 * V_2 )
{
const struct V_4 * V_5 ;
struct V_1 * * V_51 = NULL ;
struct V_1 * V_52 ;
struct V_18 * V_48 ;
unsigned int V_53 ;
unsigned int V_54 ;
unsigned int V_55 ;
T_3 V_56 = 1 ;
int V_3 ;
V_55 = F_25 ( V_2 ) ;
V_54 = V_55 + sizeof( * V_48 ) ;
V_48 = F_26 ( V_2 , V_55 ) ;
if ( F_27 ( V_2 , V_54 ) ) {
V_48 = F_28 ( V_2 , V_54 , V_55 ) ;
if ( F_3 ( ! V_48 ) )
goto V_29;
}
F_29 ( V_2 , V_55 ) ;
F_30 ( V_2 , sizeof( * V_48 ) ) ;
F_31 ( V_2 , F_25 ( V_2 ) ) ;
V_56 += F_21 ( V_48 -> V_23 ) != F_32 ( V_2 ) ;
F_33 () ;
V_3 = V_48 -> V_14 ;
V_5 = F_2 ( V_10 [ V_3 ] ) ;
if ( ! V_5 || ! V_5 -> V_39 . V_57 ) {
F_34 ( V_2 , F_25 ( V_2 ) ) ;
V_3 = F_1 ( V_2 , V_3 ) ;
F_30 ( V_2 , - F_35 ( V_2 ) ) ;
F_16 ( V_2 ) ;
F_36 ( V_2 , F_25 ( V_2 ) ) ;
V_5 = F_2 ( V_10 [ V_3 ] ) ;
if ( ! V_5 || ! V_5 -> V_39 . V_57 )
goto V_58;
V_48 = F_13 ( V_2 ) ;
}
F_37 ( V_2 ) -> V_3 = V_3 ;
V_56 -- ;
V_53 = F_38 ( V_2 ) ;
for ( V_52 = * V_44 ; V_52 ; V_52 = V_52 -> V_41 ) {
const struct V_18 * V_59 ;
T_4 V_60 ;
if ( ! F_37 ( V_52 ) -> V_61 )
continue;
V_59 = (struct V_18 * ) ( V_52 -> V_13 + V_55 ) ;
V_60 = * ( T_4 * ) V_48 ^ * ( T_4 * ) V_59 ;
if ( ( V_60 & F_39 ( 0xF00FFFFF ) ) ||
memcmp ( & V_48 -> V_14 , & V_59 -> V_14 ,
V_53 - F_40 ( struct V_18 , V_14 ) ) ) {
F_37 ( V_52 ) -> V_61 = 0 ;
continue;
}
F_37 ( V_52 ) -> V_56 |= ! ! ( V_60 & F_39 ( 0x0FF00000 ) ) ;
F_37 ( V_52 ) -> V_56 |= V_56 ;
if ( F_37 ( V_2 ) -> V_62 )
F_37 ( V_52 ) -> V_63 = 0 ;
}
F_37 ( V_2 ) -> V_62 = true ;
F_37 ( V_2 ) -> V_56 |= V_56 ;
F_41 ( V_2 , V_48 , V_53 ) ;
V_51 = V_5 -> V_39 . V_57 ( V_44 , V_2 ) ;
V_58:
F_42 () ;
V_29:
F_37 ( V_2 ) -> V_56 |= V_56 ;
return V_51 ;
}
static struct V_1 * * F_43 ( struct V_1 * * V_44 ,
struct V_1 * V_2 )
{
if ( F_37 ( V_2 ) -> V_64 ) {
F_37 ( V_2 ) -> V_56 = 1 ;
return NULL ;
}
F_37 ( V_2 ) -> V_64 = 1 ;
return F_24 ( V_44 , V_2 ) ;
}
static struct V_1 * * F_44 ( struct V_1 * * V_44 ,
struct V_1 * V_2 )
{
if ( F_37 ( V_2 ) -> V_64 ) {
F_37 ( V_2 ) -> V_56 = 1 ;
return NULL ;
}
F_37 ( V_2 ) -> V_64 = 1 ;
return F_45 ( V_44 , V_2 ) ;
}
static int F_46 ( struct V_1 * V_2 , int V_28 )
{
const struct V_4 * V_5 ;
struct V_18 * V_48 = (struct V_18 * ) ( V_2 -> V_13 + V_28 ) ;
int V_65 = - V_66 ;
if ( V_2 -> V_34 )
F_47 ( V_2 , V_28 ) ;
V_48 -> V_23 = F_19 ( V_2 -> V_8 - V_28 - sizeof( * V_48 ) ) ;
F_33 () ;
V_28 += sizeof( * V_48 ) + F_23 ( V_48 , & V_5 ) ;
if ( F_48 ( ! V_5 || ! V_5 -> V_39 . V_67 ) )
goto V_58;
V_65 = V_5 -> V_39 . V_67 ( V_2 , V_28 ) ;
V_58:
F_42 () ;
return V_65 ;
}
static int F_49 ( struct V_1 * V_2 , int V_28 )
{
V_2 -> V_34 = 1 ;
F_14 ( V_2 ) -> V_35 |= V_36 ;
return F_46 ( V_2 , V_28 ) ;
}
static int F_50 ( struct V_1 * V_2 , int V_28 )
{
V_2 -> V_34 = 1 ;
F_14 ( V_2 ) -> V_35 |= V_37 ;
return F_46 ( V_2 , V_28 ) ;
}
static int F_51 ( struct V_1 * V_2 , int V_28 )
{
V_2 -> V_34 = 1 ;
F_14 ( V_2 ) -> V_35 |= V_37 ;
return F_52 ( V_2 , V_28 ) ;
}
static int T_5 F_53 ( void )
{
if ( F_54 () < 0 )
F_55 ( L_1 , V_68 ) ;
if ( F_56 () < 0 )
F_55 ( L_2 , V_68 ) ;
F_57 ( & V_69 ) ;
F_58 ( & V_70 , V_71 ) ;
F_59 ( & V_72 , V_71 ) ;
F_59 ( & V_73 , V_74 ) ;
return 0 ;
}
