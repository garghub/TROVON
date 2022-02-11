static int F_1 ( struct V_1 * V_2 , int V_3 ,
struct V_4 * V_5 )
{
return F_2 ( V_2 , 0 , V_5 -> V_6 , V_3 , 0 , V_7 ,
V_8 ) ;
}
static int F_3 ( struct V_1 * V_2 , int V_3 ,
struct V_4 * V_5 )
{
return F_4 ( V_2 , V_5 -> V_6 , V_3 , 0 , V_9 ,
V_8 ) ;
}
static int F_5 ( struct V_1 * V_2 , T_1 V_10 , T_1 V_11 , T_1 V_12 ,
struct V_4 * V_5 )
{
T_2 V_13 ;
V_13 = ( T_2 ) V_10 << 24 | ( T_2 ) V_11 << 16 | V_12 << 1 ;
return F_4 ( V_2 , V_5 -> V_6 , V_13 , 0x1 ,
V_9 , V_8 ) ;
}
static int F_6 ( struct V_1 * V_2 , struct V_4 * V_5 ,
T_3 * V_14 , T_1 V_15 )
{
T_4 V_16 ;
int V_17 ;
V_17 = F_7 ( V_2 , V_5 -> V_6 , & V_16 , 0 , V_15 ,
V_18 , V_8 ) ;
if ( ! V_17 )
* V_14 = V_16 ;
return V_17 ;
}
static struct V_19 * F_8 ( struct V_1 * V_2 , T_1 V_20 ,
enum V_21 V_12 ,
T_2 V_22 )
{
struct V_23 * V_24 = & F_9 ( V_2 ) -> V_12 [ V_20 ] ;
struct V_19 * V_25 ;
F_10 (pqp, &s_steer->promisc_qps[steer], list) {
if ( V_25 -> V_22 == V_22 )
return V_25 ;
}
return NULL ;
}
static int F_11 ( struct V_1 * V_2 , T_1 V_10 , T_1 V_11 ,
enum V_21 V_12 ,
unsigned int V_3 , T_2 V_22 )
{
struct V_23 * V_24 ;
struct V_4 * V_5 ;
struct V_26 * V_27 ;
T_2 V_28 ;
struct V_29 * V_30 ;
struct V_19 * V_25 ;
struct V_19 * V_31 = NULL ;
T_2 V_32 ;
int V_17 ;
T_1 V_20 ;
V_20 = ( V_2 -> V_33 . V_34 == 1 ) ? V_10 : ( V_10 << 1 ) | ( V_11 - 1 ) ;
V_24 = & F_9 ( V_2 ) -> V_12 [ V_20 ] ;
V_30 = F_12 ( sizeof *V_30 , V_35 ) ;
if ( ! V_30 )
return - V_36 ;
F_13 ( & V_30 -> V_37 ) ;
V_30 -> V_3 = V_3 ;
F_14 ( & V_30 -> V_38 , & V_24 -> V_39 [ V_12 ] ) ;
V_25 = F_8 ( V_2 , V_20 , V_12 , V_22 ) ;
if ( V_25 ) {
V_31 = F_15 ( sizeof *V_31 , V_35 ) ;
if ( ! V_31 ) {
V_17 = - V_36 ;
goto V_40;
}
V_31 -> V_22 = V_22 ;
F_14 ( & V_31 -> V_38 , & V_30 -> V_37 ) ;
}
if ( F_16 ( & V_24 -> V_41 [ V_12 ] ) )
return 0 ;
V_5 = F_17 ( V_2 ) ;
if ( F_18 ( V_5 ) ) {
V_17 = - V_36 ;
goto V_40;
}
V_27 = V_5 -> V_42 ;
V_17 = F_1 ( V_2 , V_3 , V_5 ) ;
if ( V_17 )
goto V_43;
V_28 = F_19 ( V_27 -> V_28 ) & 0xffffff ;
V_32 = F_19 ( V_27 -> V_28 ) >> 30 ;
F_10 (pqp, &s_steer->promisc_qps[steer], list) {
if ( V_25 -> V_22 == V_22 )
continue;
if ( V_28 == V_44 ) {
V_17 = - V_36 ;
goto V_43;
}
V_27 -> V_45 [ V_28 ++ ] = F_20 ( V_25 -> V_22 & V_46 ) ;
}
V_27 -> V_28 = F_20 ( V_28 | ( V_32 << 30 ) ) ;
V_17 = F_3 ( V_2 , V_3 , V_5 ) ;
V_43:
F_21 ( V_2 , V_5 ) ;
if ( ! V_17 )
return 0 ;
V_40:
if ( V_31 ) {
F_22 ( & V_31 -> V_38 ) ;
F_23 ( V_31 ) ;
}
F_22 ( & V_30 -> V_38 ) ;
F_23 ( V_30 ) ;
return V_17 ;
}
static int F_24 ( struct V_1 * V_2 , T_1 V_10 , T_1 V_11 ,
enum V_21 V_12 ,
unsigned int V_3 , T_2 V_22 )
{
struct V_23 * V_24 ;
struct V_29 * V_47 , * V_48 = NULL ;
struct V_19 * V_25 ;
struct V_19 * V_31 ;
T_1 V_20 ;
V_20 = ( V_2 -> V_33 . V_34 == 1 ) ? V_10 : ( V_10 << 1 ) | ( V_11 - 1 ) ;
V_24 = & F_9 ( V_2 ) -> V_12 [ V_20 ] ;
V_25 = F_8 ( V_2 , V_20 , V_12 , V_22 ) ;
if ( ! V_25 )
return 0 ;
F_10 (tmp_entry, &s_steer->steer_entries[steer], list) {
if ( V_47 -> V_3 == V_3 ) {
V_48 = V_47 ;
break;
}
}
if ( F_25 ( ! V_48 ) ) {
F_26 ( V_2 , L_1 , V_3 ) ;
return - V_49 ;
}
F_10 (dqp, &entry->duplicates, list) {
if ( V_22 == V_31 -> V_22 )
return 0 ;
}
V_31 = F_15 ( sizeof *V_31 , V_35 ) ;
if ( ! V_31 )
return - V_36 ;
V_31 -> V_22 = V_22 ;
F_14 ( & V_31 -> V_38 , & V_48 -> V_37 ) ;
return 0 ;
}
static bool F_27 ( struct V_1 * V_2 , T_1 V_10 , T_1 V_11 ,
enum V_21 V_12 ,
unsigned int V_3 , T_2 V_22 )
{
struct V_23 * V_24 ;
struct V_29 * V_47 , * V_48 = NULL ;
struct V_19 * V_31 , * V_50 ;
T_1 V_20 ;
V_20 = ( V_2 -> V_33 . V_34 == 1 ) ? V_10 : ( V_10 << 1 ) | ( V_11 - 1 ) ;
V_24 = & F_9 ( V_2 ) -> V_12 [ V_20 ] ;
if ( ! F_8 ( V_2 , V_20 , V_12 , V_22 ) )
return false ;
F_10 (tmp_entry, &s_steer->steer_entries[steer], list) {
if ( V_47 -> V_3 == V_3 ) {
V_48 = V_47 ;
break;
}
}
if ( F_25 ( ! V_48 ) ) {
F_26 ( V_2 , L_2 , V_3 ) ;
return false ;
}
F_28 (dqp, tmp_dqp, &entry->duplicates, list) {
if ( V_31 -> V_22 == V_22 ) {
F_22 ( & V_31 -> V_38 ) ;
F_23 ( V_31 ) ;
}
}
return true ;
}
static bool F_29 ( struct V_1 * V_2 , T_1 V_10 , T_1 V_11 ,
enum V_21 V_12 ,
unsigned int V_3 , T_2 V_51 )
{
struct V_23 * V_24 ;
struct V_4 * V_5 ;
struct V_26 * V_27 ;
struct V_29 * V_48 = NULL , * V_47 ;
T_2 V_22 ;
T_2 V_28 ;
bool V_52 = false ;
int V_53 ;
T_1 V_20 ;
V_20 = ( V_2 -> V_33 . V_34 == 1 ) ? V_10 : ( V_10 << 1 ) | ( V_11 - 1 ) ;
V_24 = & F_9 ( V_2 ) -> V_12 [ V_20 ] ;
V_5 = F_17 ( V_2 ) ;
if ( F_18 ( V_5 ) )
return false ;
V_27 = V_5 -> V_42 ;
if ( F_1 ( V_2 , V_3 , V_5 ) )
goto V_54;
V_28 = F_19 ( V_27 -> V_28 ) & 0xffffff ;
for ( V_53 = 0 ; V_53 < V_28 ; V_53 ++ ) {
V_22 = F_19 ( V_27 -> V_45 [ V_53 ] ) & V_46 ;
if ( ! F_8 ( V_2 , V_20 , V_12 , V_22 ) && V_22 != V_51 ) {
goto V_54;
}
}
V_52 = true ;
F_28 (entry, tmp_entry, &s_steer->steer_entries[steer], list) {
if ( V_48 -> V_3 == V_3 ) {
if ( F_16 ( & V_48 -> V_37 ) ) {
F_22 ( & V_48 -> V_38 ) ;
F_23 ( V_48 ) ;
} else {
V_52 = false ;
goto V_54;
}
}
}
V_54:
F_21 ( V_2 , V_5 ) ;
return V_52 ;
}
static int F_30 ( struct V_1 * V_2 , T_1 V_10 , T_1 V_11 ,
enum V_21 V_12 , T_2 V_22 )
{
struct V_23 * V_24 ;
struct V_4 * V_5 ;
struct V_26 * V_27 ;
struct V_29 * V_48 ;
struct V_19 * V_25 ;
struct V_19 * V_31 ;
T_2 V_28 ;
T_2 V_32 ;
int V_53 ;
bool V_55 ;
int V_56 ;
int V_17 ;
T_1 V_20 ;
struct F_9 * V_57 = F_9 ( V_2 ) ;
V_20 = ( V_2 -> V_33 . V_34 == 1 ) ? V_10 : ( V_10 << 1 ) | ( V_11 - 1 ) ;
V_24 = & F_9 ( V_2 ) -> V_12 [ V_20 ] ;
F_31 ( & V_57 -> V_58 . V_59 ) ;
if ( F_8 ( V_2 , V_20 , V_12 , V_22 ) ) {
V_17 = 0 ;
goto V_60;
}
V_25 = F_15 ( sizeof *V_25 , V_35 ) ;
if ( ! V_25 ) {
V_17 = - V_36 ;
goto V_60;
}
V_25 -> V_22 = V_22 ;
V_5 = F_17 ( V_2 ) ;
if ( F_18 ( V_5 ) ) {
V_17 = - V_36 ;
goto V_40;
}
V_27 = V_5 -> V_42 ;
F_10 (entry, &s_steer->steer_entries[steer], list) {
V_17 = F_1 ( V_2 , V_48 -> V_3 , V_5 ) ;
if ( V_17 )
goto V_43;
V_28 = F_19 ( V_27 -> V_28 ) & 0xffffff ;
V_32 = F_19 ( V_27 -> V_28 ) >> 30 ;
V_55 = false ;
for ( V_53 = 0 ; V_53 < V_28 ; V_53 ++ ) {
if ( ( F_19 ( V_27 -> V_45 [ V_53 ] ) & V_46 ) == V_22 ) {
V_31 = F_15 ( sizeof *V_31 , V_35 ) ;
if ( ! V_31 )
goto V_43;
V_31 -> V_22 = V_22 ;
F_14 ( & V_31 -> V_38 , & V_48 -> V_37 ) ;
V_55 = true ;
}
}
if ( ! V_55 ) {
if ( V_28 == V_44 ) {
V_17 = - V_36 ;
goto V_43;
}
V_27 -> V_45 [ V_28 ++ ] = F_20 ( V_22 & V_46 ) ;
V_27 -> V_28 = F_20 ( V_28 | ( V_32 << 30 ) ) ;
V_17 = F_3 ( V_2 , V_48 -> V_3 , V_5 ) ;
if ( V_17 )
goto V_43;
}
V_56 = V_48 -> V_3 ;
}
F_14 ( & V_25 -> V_38 , & V_24 -> V_41 [ V_12 ] ) ;
memset ( V_27 , 0 , sizeof *V_27 ) ;
V_28 = 0 ;
F_10 (dqp, &s_steer->promisc_qps[steer], list)
V_27 -> V_45 [ V_28 ++ ] = F_20 ( V_31 -> V_22 & V_46 ) ;
V_27 -> V_28 = F_20 ( V_28 | V_61 << 30 ) ;
V_17 = F_5 ( V_2 , V_10 , V_11 , V_12 , V_5 ) ;
if ( V_17 )
goto V_62;
F_21 ( V_2 , V_5 ) ;
F_32 ( & V_57 -> V_58 . V_59 ) ;
return 0 ;
V_62:
F_22 ( & V_25 -> V_38 ) ;
V_43:
F_21 ( V_2 , V_5 ) ;
V_40:
F_23 ( V_25 ) ;
V_60:
F_32 ( & V_57 -> V_58 . V_59 ) ;
return V_17 ;
}
static int F_33 ( struct V_1 * V_2 , T_1 V_10 , T_1 V_11 ,
enum V_21 V_12 , T_2 V_22 )
{
struct F_9 * V_57 = F_9 ( V_2 ) ;
struct V_23 * V_24 ;
struct V_4 * V_5 ;
struct V_26 * V_27 ;
struct V_29 * V_48 ;
struct V_19 * V_25 ;
struct V_19 * V_31 ;
T_2 V_28 ;
bool V_55 ;
bool V_63 = false ;
int V_64 , V_53 ;
int V_17 ;
T_1 V_20 ;
V_20 = ( V_2 -> V_33 . V_34 == 1 ) ? V_10 : ( V_10 << 1 ) | ( V_11 - 1 ) ;
V_24 = & F_9 ( V_2 ) -> V_12 [ V_20 ] ;
F_31 ( & V_57 -> V_58 . V_59 ) ;
V_25 = F_8 ( V_2 , V_20 , V_12 , V_22 ) ;
if ( F_25 ( ! V_25 ) ) {
F_26 ( V_2 , L_3 , V_22 ) ;
V_17 = 0 ;
goto V_60;
}
F_22 ( & V_25 -> V_38 ) ;
V_5 = F_17 ( V_2 ) ;
if ( F_18 ( V_5 ) ) {
V_17 = - V_36 ;
V_63 = true ;
goto V_62;
}
V_27 = V_5 -> V_42 ;
V_28 = 0 ;
F_10 (dqp, &s_steer->promisc_qps[steer], list)
V_27 -> V_45 [ V_28 ++ ] = F_20 ( V_31 -> V_22 & V_46 ) ;
V_27 -> V_28 = F_20 ( V_28 | V_61 << 30 ) ;
V_17 = F_5 ( V_2 , V_10 , V_11 , V_12 , V_5 ) ;
if ( V_17 )
goto V_43;
F_10 (entry, &s_steer->steer_entries[steer], list) {
V_55 = false ;
F_10 (dqp, &entry->duplicates, list) {
if ( V_31 -> V_22 == V_22 ) {
V_55 = true ;
break;
}
}
if ( V_55 ) {
F_22 ( & V_31 -> V_38 ) ;
F_23 ( V_31 ) ;
} else {
V_17 = F_1 ( V_2 , V_48 -> V_3 , V_5 ) ;
if ( V_17 )
goto V_43;
V_28 = F_19 ( V_27 -> V_28 ) & 0xffffff ;
for ( V_64 = - 1 , V_53 = 0 ; V_53 < V_28 ; ++ V_53 )
if ( ( F_19 ( V_27 -> V_45 [ V_53 ] ) & V_46 ) == V_22 )
V_64 = V_53 ;
V_27 -> V_28 = F_20 ( -- V_28 |
( V_61 << 30 ) ) ;
V_27 -> V_45 [ V_64 ] = V_27 -> V_45 [ V_53 - 1 ] ;
V_27 -> V_45 [ V_53 - 1 ] = 0 ;
V_17 = F_3 ( V_2 , V_48 -> V_3 , V_5 ) ;
if ( V_17 )
goto V_43;
}
}
V_43:
F_21 ( V_2 , V_5 ) ;
V_62:
if ( V_63 )
F_14 ( & V_25 -> V_38 , & V_24 -> V_41 [ V_12 ] ) ;
else
F_23 ( V_25 ) ;
V_60:
F_32 ( & V_57 -> V_58 . V_59 ) ;
return V_17 ;
}
static int F_34 ( struct V_1 * V_2 , T_1 V_11 ,
T_1 * V_65 , enum V_66 V_32 ,
enum V_21 V_12 ,
struct V_4 * V_67 ,
T_3 * V_14 , int * V_68 , int * V_3 )
{
struct V_4 * V_5 ;
struct V_26 * V_27 = V_67 -> V_42 ;
T_1 * V_69 ;
int V_17 ;
T_1 V_15 = ( V_32 == V_61 ) ? ! ! ( V_2 -> V_33 . V_70 ) : 0 ;
V_5 = F_17 ( V_2 ) ;
if ( F_18 ( V_5 ) )
return - V_36 ;
V_69 = V_5 -> V_42 ;
memcpy ( V_69 , V_65 , 16 ) ;
V_17 = F_6 ( V_2 , V_5 , V_14 , V_15 ) ;
F_21 ( V_2 , V_5 ) ;
if ( V_17 )
return V_17 ;
if ( 0 )
F_35 ( V_2 , L_4 , V_65 , * V_14 ) ;
* V_3 = * V_14 ;
* V_68 = - 1 ;
do {
V_17 = F_1 ( V_2 , * V_3 , V_67 ) ;
if ( V_17 )
return V_17 ;
if ( ! ( F_19 ( V_27 -> V_28 ) & 0xffffff ) ) {
if ( * V_3 != * V_14 ) {
F_36 ( V_2 , L_5 ) ;
V_17 = - V_49 ;
}
return V_17 ;
}
if ( ! memcmp ( V_27 -> V_65 , V_65 , 16 ) &&
F_19 ( V_27 -> V_28 ) >> 30 == V_32 )
return V_17 ;
* V_68 = * V_3 ;
* V_3 = F_19 ( V_27 -> V_71 ) >> 6 ;
} while ( * V_3 );
* V_3 = - 1 ;
return V_17 ;
}
int F_37 ( struct V_1 * V_2 , struct V_72 * V_45 , T_1 V_65 [ 16 ] ,
int V_73 , enum V_66 V_32 ,
enum V_21 V_12 )
{
struct F_9 * V_57 = F_9 ( V_2 ) ;
struct V_4 * V_5 ;
struct V_26 * V_27 ;
T_2 V_28 ;
T_3 V_14 ;
int V_3 , V_68 ;
int V_74 = 0 ;
int V_53 ;
int V_17 ;
T_1 V_11 = V_65 [ 5 ] ;
T_1 V_30 = 0 ;
V_5 = F_17 ( V_2 ) ;
if ( F_18 ( V_5 ) )
return F_38 ( V_5 ) ;
V_27 = V_5 -> V_42 ;
F_31 ( & V_57 -> V_58 . V_59 ) ;
V_17 = F_34 ( V_2 , V_11 , V_65 , V_32 , V_12 ,
V_5 , & V_14 , & V_68 , & V_3 ) ;
if ( V_17 )
goto V_54;
if ( V_3 != - 1 ) {
if ( ! ( F_19 ( V_27 -> V_28 ) & 0xffffff ) ) {
V_30 = 1 ;
memcpy ( V_27 -> V_65 , V_65 , 16 ) ;
}
} else {
V_74 = 1 ;
V_3 = F_39 ( & V_57 -> V_58 . V_75 ) ;
if ( V_3 == - 1 ) {
F_36 ( V_2 , L_6 ) ;
V_17 = - V_36 ;
goto V_54;
}
V_3 += V_2 -> V_33 . V_76 ;
memset ( V_27 , 0 , sizeof *V_27 ) ;
memcpy ( V_27 -> V_65 , V_65 , 16 ) ;
}
V_28 = F_19 ( V_27 -> V_28 ) & 0xffffff ;
if ( V_28 == V_44 ) {
F_36 ( V_2 , L_7 , V_3 ) ;
V_17 = - V_36 ;
goto V_54;
}
for ( V_53 = 0 ; V_53 < V_28 ; ++ V_53 )
if ( ( F_19 ( V_27 -> V_45 [ V_53 ] ) & V_46 ) == V_45 -> V_22 ) {
F_35 ( V_2 , L_8 , V_45 -> V_22 ) ;
V_17 = 0 ;
goto V_54;
}
if ( V_73 )
V_27 -> V_45 [ V_28 ++ ] = F_20 ( ( V_45 -> V_22 & V_46 ) |
( 1U << V_77 ) ) ;
else
V_27 -> V_45 [ V_28 ++ ] = F_20 ( V_45 -> V_22 & V_46 ) ;
V_27 -> V_28 = F_20 ( V_28 | ( T_2 ) V_32 << 30 ) ;
V_17 = F_3 ( V_2 , V_3 , V_5 ) ;
if ( V_17 )
goto V_54;
if ( ! V_74 )
goto V_54;
V_17 = F_1 ( V_2 , V_68 , V_5 ) ;
if ( V_17 )
goto V_54;
V_27 -> V_71 = F_20 ( V_3 << 6 ) ;
V_17 = F_3 ( V_2 , V_68 , V_5 ) ;
if ( V_17 )
goto V_54;
V_54:
if ( V_32 == V_61 ) {
if ( V_30 )
F_11 ( V_2 , 0 , V_11 , V_12 , V_3 , V_45 -> V_22 ) ;
else
F_24 ( V_2 , 0 , V_11 , V_12 ,
V_3 , V_45 -> V_22 ) ;
}
if ( V_17 && V_74 && V_3 != - 1 ) {
if ( V_3 < V_2 -> V_33 . V_76 )
F_26 ( V_2 , L_9 ,
V_3 , V_2 -> V_33 . V_76 ) ;
else
F_40 ( & V_57 -> V_58 . V_75 ,
V_3 - V_2 -> V_33 . V_76 ) ;
}
F_32 ( & V_57 -> V_58 . V_59 ) ;
F_21 ( V_2 , V_5 ) ;
return V_17 ;
}
int F_41 ( struct V_1 * V_2 , struct V_72 * V_45 , T_1 V_65 [ 16 ] ,
enum V_66 V_32 , enum V_21 V_12 )
{
struct F_9 * V_57 = F_9 ( V_2 ) ;
struct V_4 * V_5 ;
struct V_26 * V_27 ;
T_2 V_28 ;
T_3 V_14 ;
int V_68 , V_3 ;
int V_53 , V_64 ;
int V_17 ;
T_1 V_11 = V_65 [ 5 ] ;
bool V_78 = false ;
V_5 = F_17 ( V_2 ) ;
if ( F_18 ( V_5 ) )
return F_38 ( V_5 ) ;
V_27 = V_5 -> V_42 ;
F_31 ( & V_57 -> V_58 . V_59 ) ;
V_17 = F_34 ( V_2 , V_11 , V_65 , V_32 , V_12 ,
V_5 , & V_14 , & V_68 , & V_3 ) ;
if ( V_17 )
goto V_54;
if ( V_3 == - 1 ) {
F_36 ( V_2 , L_10 , V_65 ) ;
V_17 = - V_49 ;
goto V_54;
}
if ( V_32 == V_61 &&
F_27 ( V_2 , 0 , V_11 , V_12 , V_3 , V_45 -> V_22 ) )
goto V_54;
V_28 = F_19 ( V_27 -> V_28 ) & 0xffffff ;
for ( V_64 = - 1 , V_53 = 0 ; V_53 < V_28 ; ++ V_53 )
if ( ( F_19 ( V_27 -> V_45 [ V_53 ] ) & V_46 ) == V_45 -> V_22 )
V_64 = V_53 ;
if ( V_64 == - 1 ) {
F_36 ( V_2 , L_11 , V_45 -> V_22 ) ;
V_17 = - V_49 ;
goto V_54;
}
V_27 -> V_28 = F_20 ( -- V_28 | ( T_2 ) V_32 << 30 ) ;
V_27 -> V_45 [ V_64 ] = V_27 -> V_45 [ V_53 - 1 ] ;
V_27 -> V_45 [ V_53 - 1 ] = 0 ;
if ( V_32 == V_61 )
V_78 = F_29 ( V_2 , 0 , V_11 , V_12 , V_3 , V_45 -> V_22 ) ;
if ( V_53 != 1 && ( V_32 != V_61 || ! V_78 ) ) {
V_17 = F_3 ( V_2 , V_3 , V_5 ) ;
goto V_54;
}
V_27 -> V_28 = F_20 ( ( T_2 ) V_32 << 30 ) ;
if ( V_68 == - 1 ) {
int V_79 = F_19 ( V_27 -> V_71 ) >> 6 ;
if ( V_79 ) {
V_17 = F_1 ( V_2 , V_79 , V_5 ) ;
if ( V_17 )
goto V_54;
} else
memset ( V_27 -> V_65 , 0 , 16 ) ;
V_17 = F_3 ( V_2 , V_3 , V_5 ) ;
if ( V_17 )
goto V_54;
if ( V_79 ) {
if ( V_79 < V_2 -> V_33 . V_76 )
F_26 ( V_2 , L_12 ,
V_3 , V_79 , V_2 -> V_33 . V_76 ) ;
else
F_40 ( & V_57 -> V_58 . V_75 ,
V_79 - V_2 -> V_33 . V_76 ) ;
}
} else {
int V_80 = F_19 ( V_27 -> V_71 ) >> 6 ;
V_17 = F_1 ( V_2 , V_68 , V_5 ) ;
if ( V_17 )
goto V_54;
V_27 -> V_71 = F_20 ( V_80 << 6 ) ;
V_17 = F_3 ( V_2 , V_68 , V_5 ) ;
if ( V_17 )
goto V_54;
if ( V_3 < V_2 -> V_33 . V_76 )
F_26 ( V_2 , L_13 ,
V_68 , V_3 , V_2 -> V_33 . V_76 ) ;
else
F_40 ( & V_57 -> V_58 . V_75 ,
V_3 - V_2 -> V_33 . V_76 ) ;
}
V_54:
F_32 ( & V_57 -> V_58 . V_59 ) ;
F_21 ( V_2 , V_5 ) ;
return V_17 ;
}
int F_42 ( struct V_1 * V_2 , struct V_72 * V_45 , T_1 V_65 [ 16 ] ,
int V_73 , enum V_66 V_32 )
{
enum V_21 V_12 ;
V_12 = ( F_43 ( & V_65 [ 10 ] ) ) ? V_81 : V_82 ;
if ( V_32 == V_61 && ! V_2 -> V_33 . V_70 )
return 0 ;
if ( V_32 == V_61 )
V_65 [ 7 ] |= ( V_12 << 1 ) ;
return F_37 ( V_2 , V_45 , V_65 ,
V_73 , V_32 ,
V_12 ) ;
}
int F_44 ( struct V_1 * V_2 , struct V_72 * V_45 , T_1 V_65 [ 16 ] ,
enum V_66 V_32 )
{
enum V_21 V_12 ;
V_12 = ( F_43 ( & V_65 [ 10 ] ) ) ? V_81 : V_82 ;
if ( V_32 == V_61 && ! V_2 -> V_33 . V_70 )
return 0 ;
if ( V_32 == V_61 ) {
V_65 [ 7 ] |= ( V_12 << 1 ) ;
}
return F_41 ( V_2 , V_45 , V_65 , V_32 , V_12 ) ;
}
int F_45 ( struct V_1 * V_2 , T_2 V_22 , T_1 V_11 )
{
if ( ! V_2 -> V_33 . V_70 )
return 0 ;
return F_30 ( V_2 , 0 , V_11 , V_82 , V_22 ) ;
}
int F_46 ( struct V_1 * V_2 , T_2 V_22 , T_1 V_11 )
{
if ( ! V_2 -> V_33 . V_70 )
return 0 ;
return F_33 ( V_2 , 0 , V_11 , V_82 , V_22 ) ;
}
int F_47 ( struct V_1 * V_2 , T_2 V_22 , T_1 V_11 )
{
if ( ! V_2 -> V_33 . V_70 )
return 0 ;
return F_30 ( V_2 , 0 , V_11 , V_81 , V_22 ) ;
}
int F_48 ( struct V_1 * V_2 , T_2 V_22 , T_1 V_11 )
{
if ( ! V_2 -> V_33 . V_70 )
return 0 ;
return F_33 ( V_2 , 0 , V_11 , V_81 , V_22 ) ;
}
int F_49 ( struct V_1 * V_2 )
{
struct F_9 * V_57 = F_9 ( V_2 ) ;
int V_17 ;
V_17 = F_50 ( & V_57 -> V_58 . V_75 , V_2 -> V_33 . V_83 ,
V_2 -> V_33 . V_83 - 1 , 0 , 0 ) ;
if ( V_17 )
return V_17 ;
F_51 ( & V_57 -> V_58 . V_59 ) ;
return 0 ;
}
void F_52 ( struct V_1 * V_2 )
{
F_53 ( & F_9 ( V_2 ) -> V_58 . V_75 ) ;
}
