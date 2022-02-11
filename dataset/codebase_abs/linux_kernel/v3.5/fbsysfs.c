struct V_1 * F_1 ( T_1 V_2 , struct V_3 * V_4 )
{
#define F_2 (BITS_PER_LONG/8)
#define F_3 (BYTES_PER_LONG - (sizeof(struct fb_info) % BYTES_PER_LONG))
int V_5 = sizeof( struct V_1 ) ;
struct V_1 * V_6 ;
char * V_7 ;
if ( V_2 )
V_5 += F_3 ;
V_7 = F_4 ( V_5 + V_2 , V_8 ) ;
if ( ! V_7 )
return NULL ;
V_6 = (struct V_1 * ) V_7 ;
if ( V_2 )
V_6 -> V_9 = V_7 + V_5 ;
V_6 -> V_3 = V_4 ;
#ifdef F_5
F_6 ( & V_6 -> V_10 ) ;
#endif
return V_6 ;
#undef F_3
#undef F_2
}
void F_7 ( struct V_1 * V_6 )
{
if ( ! V_6 )
return;
F_8 ( V_6 -> V_11 ) ;
F_8 ( V_6 ) ;
}
static int F_9 ( struct V_1 * V_1 , struct V_12 * V_13 )
{
int V_14 ;
V_13 -> F_9 |= V_15 ;
F_10 () ;
V_1 -> V_16 |= V_17 ;
V_14 = F_11 ( V_1 , V_13 ) ;
V_1 -> V_16 &= ~ V_17 ;
F_12 () ;
if ( V_14 )
return V_14 ;
return 0 ;
}
static int F_13 ( char * V_18 , unsigned int V_19 ,
const struct V_20 * V_21 )
{
char V_22 = 'U' ;
char V_23 = 'p' ;
if ( V_21 -> V_24 & V_25 )
V_22 = 'D' ;
if ( V_21 -> V_24 & V_26 )
V_22 = 'V' ;
if ( V_21 -> V_24 & V_27 )
V_22 = 'S' ;
if ( V_21 -> V_28 & V_29 )
V_23 = 'i' ;
if ( V_21 -> V_28 & V_30 )
V_23 = 'd' ;
return snprintf ( & V_18 [ V_19 ] , V_31 - V_19 , L_1 ,
V_22 , V_21 -> V_32 , V_21 -> V_33 , V_23 , V_21 -> V_34 ) ;
}
static T_2 F_14 ( struct V_3 * V_3 , struct V_35 * V_36 ,
const char * V_18 , T_1 V_37 )
{
struct V_1 * V_1 = F_15 ( V_3 ) ;
char V_38 [ 100 ] ;
struct V_12 V_13 ;
struct V_39 * V_40 ;
struct V_20 * V_21 ;
struct V_41 * V_42 ;
T_1 V_43 ;
int V_14 ;
memset ( & V_13 , 0 , sizeof( V_13 ) ) ;
F_16 (pos, &fb_info->modelist) {
V_40 = F_17 ( V_42 , struct V_39 , V_44 ) ;
V_21 = & V_40 -> V_21 ;
V_43 = F_13 ( V_38 , 0 , V_21 ) ;
if ( strncmp ( V_38 , V_18 , F_18 ( V_37 , V_43 ) ) == 0 ) {
V_13 = V_1 -> V_13 ;
F_19 ( & V_13 , V_21 ) ;
if ( ( V_14 = F_9 ( V_1 , & V_13 ) ) )
return V_14 ;
V_1 -> V_21 = V_21 ;
return V_37 ;
}
}
return - V_45 ;
}
static T_2 F_20 ( struct V_3 * V_3 , struct V_35 * V_36 ,
char * V_18 )
{
struct V_1 * V_1 = F_15 ( V_3 ) ;
if ( ! V_1 -> V_21 )
return 0 ;
return F_13 ( V_18 , 0 , V_1 -> V_21 ) ;
}
static T_2 F_21 ( struct V_3 * V_3 ,
struct V_35 * V_36 ,
const char * V_18 , T_1 V_37 )
{
struct V_1 * V_1 = F_15 ( V_3 ) ;
F_22 ( V_46 ) ;
int V_43 = V_37 / sizeof( struct V_20 ) ;
if ( V_43 * sizeof( struct V_20 ) != V_37 )
return - V_45 ;
F_10 () ;
F_23 ( & V_1 -> V_40 , & V_46 ) ;
F_24 ( ( const struct V_20 * ) V_18 , V_43 ,
& V_1 -> V_40 ) ;
if ( F_25 ( V_1 ) ) {
F_26 ( & V_1 -> V_40 ) ;
F_23 ( & V_46 , & V_1 -> V_40 ) ;
} else
F_26 ( & V_46 ) ;
F_12 () ;
return 0 ;
}
static T_2 F_27 ( struct V_3 * V_3 , struct V_35 * V_36 ,
char * V_18 )
{
struct V_1 * V_1 = F_15 ( V_3 ) ;
unsigned int V_43 ;
struct V_41 * V_42 ;
struct V_39 * V_40 ;
const struct V_20 * V_21 ;
V_43 = 0 ;
F_16 (pos, &fb_info->modelist) {
V_40 = F_17 ( V_42 , struct V_39 , V_44 ) ;
V_21 = & V_40 -> V_21 ;
V_43 += F_13 ( V_18 , V_43 , V_21 ) ;
}
return V_43 ;
}
static T_2 F_28 ( struct V_3 * V_3 , struct V_35 * V_36 ,
const char * V_18 , T_1 V_37 )
{
struct V_1 * V_1 = F_15 ( V_3 ) ;
struct V_12 V_13 ;
char * * V_47 = NULL ;
int V_14 ;
V_13 = V_1 -> V_13 ;
V_13 . V_48 = F_29 ( V_18 , V_47 , 0 ) ;
if ( ( V_14 = F_9 ( V_1 , & V_13 ) ) )
return V_14 ;
return V_37 ;
}
static T_2 F_30 ( struct V_3 * V_3 , struct V_35 * V_36 ,
char * V_18 )
{
struct V_1 * V_1 = F_15 ( V_3 ) ;
return snprintf ( V_18 , V_31 , L_2 , V_1 -> V_13 . V_48 ) ;
}
static T_2 F_31 ( struct V_3 * V_3 ,
struct V_35 * V_36 ,
const char * V_18 , T_1 V_37 )
{
struct V_1 * V_1 = F_15 ( V_3 ) ;
struct V_12 V_13 ;
char * * V_47 = NULL ;
int V_14 ;
V_13 = V_1 -> V_13 ;
V_13 . V_49 = F_29 ( V_18 , V_47 , 0 ) ;
if ( ( V_14 = F_9 ( V_1 , & V_13 ) ) )
return V_14 ;
return V_37 ;
}
static T_2 F_32 ( struct V_3 * V_3 ,
struct V_35 * V_36 , char * V_18 )
{
struct V_1 * V_1 = F_15 ( V_3 ) ;
return snprintf ( V_18 , V_31 , L_2 , V_1 -> V_13 . V_49 ) ;
}
static T_2 F_33 ( struct V_3 * V_3 ,
struct V_35 * V_36 ,
const char * V_18 , T_1 V_37 )
{
struct V_1 * V_1 = F_15 ( V_3 ) ;
struct V_12 V_13 ;
char * V_47 = NULL ;
int V_14 ;
V_13 = V_1 -> V_13 ;
V_13 . V_50 = F_29 ( V_18 , & V_47 , 0 ) ;
V_47 ++ ;
if ( V_47 - V_18 >= V_37 )
return - V_45 ;
V_13 . V_51 = F_29 ( V_47 , & V_47 , 0 ) ;
if ( ( V_14 = F_9 ( V_1 , & V_13 ) ) )
return V_14 ;
return V_37 ;
}
static T_2 F_34 ( struct V_3 * V_3 ,
struct V_35 * V_36 , char * V_18 )
{
struct V_1 * V_1 = F_15 ( V_3 ) ;
return snprintf ( V_18 , V_31 , L_3 , V_1 -> V_13 . V_50 ,
V_1 -> V_13 . V_51 ) ;
}
static T_2 F_35 ( struct V_3 * V_3 ,
struct V_35 * V_36 , char * V_18 )
{
struct V_1 * V_1 = F_15 ( V_3 ) ;
return snprintf ( V_18 , V_31 , L_2 , V_1 -> V_52 . V_53 ) ;
}
static T_2 F_36 ( struct V_3 * V_3 ,
struct V_35 * V_36 ,
const char * V_18 , T_1 V_37 )
{
struct V_1 * V_1 = F_15 ( V_3 ) ;
char * V_47 = NULL ;
int V_14 ;
F_10 () ;
V_1 -> V_16 |= V_17 ;
V_14 = F_37 ( V_1 , F_29 ( V_18 , & V_47 , 0 ) ) ;
V_1 -> V_16 &= ~ V_17 ;
F_12 () ;
if ( V_14 < 0 )
return V_14 ;
return V_37 ;
}
static T_2 F_38 ( struct V_3 * V_3 ,
struct V_35 * V_36 , char * V_18 )
{
return 0 ;
}
static T_2 F_39 ( struct V_3 * V_3 ,
struct V_35 * V_36 ,
const char * V_18 , T_1 V_37 )
{
return 0 ;
}
static T_2 F_40 ( struct V_3 * V_3 ,
struct V_35 * V_36 , char * V_18 )
{
return 0 ;
}
static T_2 F_41 ( struct V_3 * V_3 ,
struct V_35 * V_36 ,
const char * V_18 , T_1 V_37 )
{
return 0 ;
}
static T_2 F_42 ( struct V_3 * V_3 ,
struct V_35 * V_36 , char * V_18 )
{
return 0 ;
}
static T_2 F_43 ( struct V_3 * V_3 ,
struct V_35 * V_36 ,
const char * V_18 , T_1 V_37 )
{
struct V_1 * V_1 = F_15 ( V_3 ) ;
struct V_12 V_13 ;
char * V_47 = NULL ;
int V_14 ;
V_13 = V_1 -> V_13 ;
V_13 . V_54 = F_29 ( V_18 , & V_47 , 0 ) ;
V_47 ++ ;
if ( V_47 - V_18 >= V_37 )
return - V_45 ;
V_13 . V_55 = F_29 ( V_47 , & V_47 , 0 ) ;
F_10 () ;
V_14 = F_44 ( V_1 , & V_13 ) ;
F_12 () ;
if ( V_14 < 0 )
return V_14 ;
return V_37 ;
}
static T_2 F_45 ( struct V_3 * V_3 ,
struct V_35 * V_36 , char * V_18 )
{
struct V_1 * V_1 = F_15 ( V_3 ) ;
return snprintf ( V_18 , V_31 , L_3 , V_1 -> V_13 . V_54 ,
V_1 -> V_13 . V_55 ) ;
}
static T_2 F_46 ( struct V_3 * V_3 ,
struct V_35 * V_36 , char * V_18 )
{
struct V_1 * V_1 = F_15 ( V_3 ) ;
return snprintf ( V_18 , V_31 , L_4 , V_1 -> V_52 . V_56 ) ;
}
static T_2 F_47 ( struct V_3 * V_3 ,
struct V_35 * V_36 ,
const char * V_18 , T_1 V_37 )
{
struct V_1 * V_1 = F_15 ( V_3 ) ;
T_3 V_57 ;
char * V_47 = NULL ;
V_57 = F_29 ( V_18 , & V_47 , 0 ) ;
if ( ! F_48 ( V_1 ) )
return - V_58 ;
F_10 () ;
F_49 ( V_1 , ( int ) V_57 ) ;
F_12 () ;
F_50 ( V_1 ) ;
return V_37 ;
}
static T_2 F_51 ( struct V_3 * V_3 ,
struct V_35 * V_36 , char * V_18 )
{
struct V_1 * V_1 = F_15 ( V_3 ) ;
return snprintf ( V_18 , V_31 , L_2 , V_1 -> V_57 ) ;
}
static T_2 F_52 ( struct V_3 * V_3 ,
struct V_35 * V_36 ,
const char * V_18 , T_1 V_37 )
{
struct V_1 * V_1 = F_15 ( V_3 ) ;
T_4 V_59 [ V_60 ] ;
unsigned int V_43 ;
if ( ! V_1 || ! V_1 -> V_61 )
return - V_58 ;
if ( V_37 != ( V_60 / 8 * 24 ) )
return - V_45 ;
for ( V_43 = 0 ; V_43 < ( V_60 / 8 ) ; ++ V_43 )
if ( sscanf ( & V_18 [ V_43 * 24 ] ,
L_5 ,
& V_59 [ V_43 * 8 + 0 ] ,
& V_59 [ V_43 * 8 + 1 ] ,
& V_59 [ V_43 * 8 + 2 ] ,
& V_59 [ V_43 * 8 + 3 ] ,
& V_59 [ V_43 * 8 + 4 ] ,
& V_59 [ V_43 * 8 + 5 ] ,
& V_59 [ V_43 * 8 + 6 ] ,
& V_59 [ V_43 * 8 + 7 ] ) != 8 )
return - V_45 ;
F_53 ( & V_1 -> V_10 ) ;
for ( V_43 = 0 ; V_43 < V_60 ; ++ V_43 )
V_1 -> V_62 [ V_43 ] = V_59 [ V_43 ] ;
F_54 ( & V_1 -> V_10 ) ;
return V_37 ;
}
static T_2 F_55 ( struct V_3 * V_3 ,
struct V_35 * V_36 , char * V_18 )
{
struct V_1 * V_1 = F_15 ( V_3 ) ;
T_2 V_63 = 0 ;
unsigned int V_43 ;
if ( ! V_1 || ! V_1 -> V_61 )
return - V_58 ;
F_53 ( & V_1 -> V_10 ) ;
for ( V_43 = 0 ; V_43 < V_60 ; V_43 += 8 )
V_63 += snprintf ( & V_18 [ V_63 ] , V_31 ,
L_6 ,
V_1 -> V_62 [ V_43 + 0 ] ,
V_1 -> V_62 [ V_43 + 1 ] ,
V_1 -> V_62 [ V_43 + 2 ] ,
V_1 -> V_62 [ V_43 + 3 ] ,
V_1 -> V_62 [ V_43 + 4 ] ,
V_1 -> V_62 [ V_43 + 5 ] ,
V_1 -> V_62 [ V_43 + 6 ] ,
V_1 -> V_62 [ V_43 + 7 ] ) ;
F_54 ( & V_1 -> V_10 ) ;
return V_63 ;
}
int F_56 ( struct V_1 * V_1 )
{
int V_43 , error = 0 ;
F_57 ( V_1 -> V_4 , V_1 ) ;
V_1 -> V_64 |= V_65 ;
for ( V_43 = 0 ; V_43 < F_58 ( V_66 ) ; V_43 ++ ) {
error = F_59 ( V_1 -> V_4 , & V_66 [ V_43 ] ) ;
if ( error )
break;
}
if ( error ) {
while ( -- V_43 >= 0 )
F_60 ( V_1 -> V_4 , & V_66 [ V_43 ] ) ;
V_1 -> V_64 &= ~ V_65 ;
}
return 0 ;
}
void F_61 ( struct V_1 * V_1 )
{
unsigned int V_43 ;
if ( V_1 -> V_64 & V_65 ) {
for ( V_43 = 0 ; V_43 < F_58 ( V_66 ) ; V_43 ++ )
F_60 ( V_1 -> V_4 , & V_66 [ V_43 ] ) ;
V_1 -> V_64 &= ~ V_65 ;
}
}
void F_62 ( struct V_1 * V_1 , T_4 V_67 , T_4 V_68 , T_4 F_18 )
{
unsigned int V_43 , V_69 , V_37 , V_70 = ( F_18 - V_68 ) ;
F_53 ( & V_1 -> V_10 ) ;
V_1 -> V_62 [ 0 ] = V_67 ;
for ( V_69 = 1 ; V_69 < ( V_60 / 16 ) ; ++ V_69 )
V_1 -> V_62 [ V_69 ] = V_68 ;
V_37 = V_60 * 15 / 16 ;
for ( V_43 = 0 ; V_43 < V_37 ; ++ V_43 )
V_1 -> V_62 [ V_69 + V_43 ] = V_68 + ( V_70 * ( V_43 + 1 ) / V_37 ) ;
F_54 ( & V_1 -> V_10 ) ;
}
