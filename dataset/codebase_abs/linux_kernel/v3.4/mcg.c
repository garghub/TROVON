int F_1 ( struct V_1 * V_2 )
{
return F_2 ( ( 1 << V_3 ) , V_4 ) ;
}
int F_3 ( struct V_1 * V_2 )
{
return 4 * ( F_1 ( V_2 ) / 16 - 2 ) ;
}
static int F_4 ( struct V_1 * V_2 , int V_5 ,
struct V_6 * V_7 )
{
return F_5 ( V_2 , 0 , V_7 -> V_8 , V_5 , 0 , V_9 ,
V_10 , V_11 ) ;
}
static int F_6 ( struct V_1 * V_2 , int V_5 ,
struct V_6 * V_7 )
{
return F_7 ( V_2 , V_7 -> V_8 , V_5 , 0 , V_12 ,
V_10 , V_11 ) ;
}
static int F_8 ( struct V_1 * V_2 , T_1 V_13 , T_1 V_14 ,
struct V_6 * V_7 )
{
T_2 V_15 ;
V_15 = ( T_2 ) V_13 << 16 | V_14 << 1 ;
return F_7 ( V_2 , V_7 -> V_8 , V_15 , 0x1 ,
V_12 , V_10 ,
V_11 ) ;
}
static int F_9 ( struct V_1 * V_2 , struct V_6 * V_7 ,
T_3 * V_16 , T_1 V_17 )
{
T_4 V_18 ;
int V_19 ;
V_19 = F_10 ( V_2 , V_7 -> V_8 , & V_18 , 0 , V_17 ,
V_20 , V_10 ,
V_11 ) ;
if ( ! V_19 )
* V_16 = V_18 ;
return V_19 ;
}
static struct V_21 * F_11 ( struct V_1 * V_2 , T_1 V_22 ,
enum V_23 V_14 ,
T_2 V_24 )
{
struct V_25 * V_26 = & F_12 ( V_2 ) -> V_14 [ V_22 ] ;
struct V_21 * V_27 ;
F_13 (pqp, &s_steer->promisc_qps[steer], list) {
if ( V_27 -> V_24 == V_24 )
return V_27 ;
}
return NULL ;
}
static int F_14 ( struct V_1 * V_2 , T_1 V_13 ,
enum V_23 V_14 ,
unsigned int V_5 , T_2 V_24 )
{
struct V_25 * V_26 ;
struct V_6 * V_7 ;
struct V_28 * V_29 ;
T_2 V_30 ;
struct V_31 * V_32 ;
struct V_21 * V_27 ;
struct V_21 * V_33 = NULL ;
T_2 V_34 ;
int V_19 ;
V_26 = & F_12 ( V_2 ) -> V_14 [ V_13 - 1 ] ;
V_32 = F_15 ( sizeof *V_32 , V_35 ) ;
if ( ! V_32 )
return - V_36 ;
F_16 ( & V_32 -> V_37 ) ;
V_32 -> V_5 = V_5 ;
F_17 ( & V_32 -> V_38 , & V_26 -> V_39 [ V_14 ] ) ;
V_27 = F_11 ( V_2 , 0 , V_14 , V_24 ) ;
if ( V_27 ) {
V_33 = F_18 ( sizeof *V_33 , V_35 ) ;
if ( ! V_33 ) {
V_19 = - V_36 ;
goto V_40;
}
V_33 -> V_24 = V_24 ;
F_17 ( & V_33 -> V_38 , & V_32 -> V_37 ) ;
}
if ( F_19 ( & V_26 -> V_41 [ V_14 ] ) )
return 0 ;
V_7 = F_20 ( V_2 ) ;
if ( F_21 ( V_7 ) ) {
V_19 = - V_36 ;
goto V_40;
}
V_29 = V_7 -> V_42 ;
V_19 = F_4 ( V_2 , V_5 , V_7 ) ;
if ( V_19 )
goto V_43;
V_30 = F_22 ( V_29 -> V_30 ) & 0xffffff ;
V_34 = F_22 ( V_29 -> V_30 ) >> 30 ;
F_13 (pqp, &s_steer->promisc_qps[steer], list) {
if ( V_27 -> V_24 == V_24 )
continue;
if ( V_30 == V_2 -> V_44 . V_45 ) {
V_19 = - V_36 ;
goto V_43;
}
V_29 -> V_46 [ V_30 ++ ] = F_23 ( V_27 -> V_24 & V_47 ) ;
}
V_29 -> V_30 = F_23 ( V_30 | ( V_34 << 30 ) ) ;
V_19 = F_6 ( V_2 , V_5 , V_7 ) ;
V_43:
F_24 ( V_2 , V_7 ) ;
if ( ! V_19 )
return 0 ;
V_40:
if ( V_33 ) {
F_25 ( & V_33 -> V_38 ) ;
F_26 ( V_33 ) ;
}
F_25 ( & V_32 -> V_38 ) ;
F_26 ( V_32 ) ;
return V_19 ;
}
static int F_27 ( struct V_1 * V_2 , T_1 V_13 ,
enum V_23 V_14 ,
unsigned int V_5 , T_2 V_24 )
{
struct V_25 * V_26 ;
struct V_31 * V_48 , * V_49 = NULL ;
struct V_21 * V_27 ;
struct V_21 * V_33 ;
V_26 = & F_12 ( V_2 ) -> V_14 [ V_13 - 1 ] ;
V_27 = F_11 ( V_2 , 0 , V_14 , V_24 ) ;
if ( ! V_27 )
return 0 ;
F_13 (tmp_entry, &s_steer->steer_entries[steer], list) {
if ( V_48 -> V_5 == V_5 ) {
V_49 = V_48 ;
break;
}
}
if ( F_28 ( ! V_49 ) ) {
F_29 ( V_2 , L_1 , V_5 ) ;
return - V_50 ;
}
F_13 (dqp, &entry->duplicates, list) {
if ( V_24 == V_27 -> V_24 )
return 0 ;
}
V_33 = F_18 ( sizeof *V_33 , V_35 ) ;
if ( ! V_33 )
return - V_36 ;
V_33 -> V_24 = V_24 ;
F_17 ( & V_33 -> V_38 , & V_49 -> V_37 ) ;
return 0 ;
}
static bool F_30 ( struct V_1 * V_2 , T_1 V_13 ,
enum V_23 V_14 ,
unsigned int V_5 , T_2 V_24 )
{
struct V_25 * V_26 ;
struct V_31 * V_48 , * V_49 = NULL ;
struct V_21 * V_33 , * V_51 ;
V_26 = & F_12 ( V_2 ) -> V_14 [ V_13 - 1 ] ;
if ( ! F_11 ( V_2 , 0 , V_14 , V_24 ) )
return false ;
F_13 (tmp_entry, &s_steer->steer_entries[steer], list) {
if ( V_48 -> V_5 == V_5 ) {
V_49 = V_48 ;
break;
}
}
if ( F_28 ( ! V_49 ) ) {
F_29 ( V_2 , L_2 , V_5 ) ;
return false ;
}
F_31 (dqp, tmp_dqp, &entry->duplicates, list) {
if ( V_33 -> V_24 == V_24 ) {
F_25 ( & V_33 -> V_38 ) ;
F_26 ( V_33 ) ;
}
}
return true ;
}
static bool F_32 ( struct V_1 * V_2 , T_1 V_13 ,
enum V_23 V_14 ,
unsigned int V_5 , T_2 V_52 )
{
struct V_25 * V_26 ;
struct V_6 * V_7 ;
struct V_28 * V_29 ;
struct V_31 * V_49 = NULL , * V_48 ;
T_2 V_24 ;
T_2 V_30 ;
bool V_53 = false ;
int V_54 ;
V_26 = & F_12 ( V_2 ) -> V_14 [ V_13 - 1 ] ;
V_7 = F_20 ( V_2 ) ;
if ( F_21 ( V_7 ) )
return false ;
V_29 = V_7 -> V_42 ;
if ( F_4 ( V_2 , V_5 , V_7 ) )
goto V_55;
V_30 = F_22 ( V_29 -> V_30 ) & 0xffffff ;
for ( V_54 = 0 ; V_54 < V_30 ; V_54 ++ ) {
V_24 = F_22 ( V_29 -> V_46 [ V_54 ] ) & V_47 ;
if ( ! F_11 ( V_2 , 0 , V_14 , V_24 ) && V_24 != V_52 ) {
goto V_55;
}
}
V_53 = true ;
F_31 (entry, tmp_entry, &s_steer->steer_entries[steer], list) {
if ( V_49 -> V_5 == V_5 ) {
if ( F_19 ( & V_49 -> V_37 ) ) {
F_25 ( & V_49 -> V_38 ) ;
F_26 ( V_49 ) ;
} else {
V_53 = false ;
goto V_55;
}
}
}
V_55:
F_24 ( V_2 , V_7 ) ;
return V_53 ;
}
static int F_33 ( struct V_1 * V_2 , T_1 V_13 ,
enum V_23 V_14 , T_2 V_24 )
{
struct V_25 * V_26 ;
struct V_6 * V_7 ;
struct V_28 * V_29 ;
struct V_31 * V_49 ;
struct V_21 * V_27 ;
struct V_21 * V_33 ;
T_2 V_30 ;
T_2 V_34 ;
int V_54 ;
bool V_56 ;
int V_57 ;
int V_19 ;
struct F_12 * V_58 = F_12 ( V_2 ) ;
V_26 = & F_12 ( V_2 ) -> V_14 [ V_13 - 1 ] ;
F_34 ( & V_58 -> V_59 . V_60 ) ;
if ( F_11 ( V_2 , 0 , V_14 , V_24 ) ) {
V_19 = 0 ;
goto V_61;
}
V_27 = F_18 ( sizeof *V_27 , V_35 ) ;
if ( ! V_27 ) {
V_19 = - V_36 ;
goto V_61;
}
V_27 -> V_24 = V_24 ;
V_7 = F_20 ( V_2 ) ;
if ( F_21 ( V_7 ) ) {
V_19 = - V_36 ;
goto V_40;
}
V_29 = V_7 -> V_42 ;
F_13 (entry, &s_steer->steer_entries[steer], list) {
V_19 = F_4 ( V_2 , V_49 -> V_5 , V_7 ) ;
if ( V_19 )
goto V_43;
V_30 = F_22 ( V_29 -> V_30 ) & 0xffffff ;
V_34 = F_22 ( V_29 -> V_30 ) >> 30 ;
V_56 = false ;
for ( V_54 = 0 ; V_54 < V_30 ; V_54 ++ ) {
if ( ( F_22 ( V_29 -> V_46 [ V_54 ] ) & V_47 ) == V_24 ) {
V_33 = F_18 ( sizeof *V_33 , V_35 ) ;
if ( ! V_33 )
goto V_43;
V_33 -> V_24 = V_24 ;
F_17 ( & V_33 -> V_38 , & V_49 -> V_37 ) ;
V_56 = true ;
}
}
if ( ! V_56 ) {
if ( V_30 == V_2 -> V_44 . V_45 ) {
V_19 = - V_36 ;
goto V_43;
}
V_29 -> V_46 [ V_30 ++ ] = F_23 ( V_24 & V_47 ) ;
V_29 -> V_30 = F_23 ( V_30 | ( V_34 << 30 ) ) ;
V_19 = F_6 ( V_2 , V_49 -> V_5 , V_7 ) ;
if ( V_19 )
goto V_43;
}
V_57 = V_49 -> V_5 ;
}
F_17 ( & V_27 -> V_38 , & V_26 -> V_41 [ V_14 ] ) ;
memset ( V_29 , 0 , sizeof *V_29 ) ;
V_30 = 0 ;
F_13 (dqp, &s_steer->promisc_qps[steer], list)
V_29 -> V_46 [ V_30 ++ ] = F_23 ( V_33 -> V_24 & V_47 ) ;
V_29 -> V_30 = F_23 ( V_30 | V_62 << 30 ) ;
V_19 = F_8 ( V_2 , V_13 , V_14 , V_7 ) ;
if ( V_19 )
goto V_63;
F_24 ( V_2 , V_7 ) ;
F_35 ( & V_58 -> V_59 . V_60 ) ;
return 0 ;
V_63:
F_25 ( & V_27 -> V_38 ) ;
V_43:
F_24 ( V_2 , V_7 ) ;
V_40:
F_26 ( V_27 ) ;
V_61:
F_35 ( & V_58 -> V_59 . V_60 ) ;
return V_19 ;
}
static int F_36 ( struct V_1 * V_2 , T_1 V_13 ,
enum V_23 V_14 , T_2 V_24 )
{
struct F_12 * V_58 = F_12 ( V_2 ) ;
struct V_25 * V_26 ;
struct V_6 * V_7 ;
struct V_28 * V_29 ;
struct V_31 * V_49 ;
struct V_21 * V_27 ;
struct V_21 * V_33 ;
T_2 V_30 ;
bool V_56 ;
bool V_64 = false ;
int V_65 , V_54 ;
int V_19 ;
V_26 = & F_12 ( V_2 ) -> V_14 [ V_13 - 1 ] ;
F_34 ( & V_58 -> V_59 . V_60 ) ;
V_27 = F_11 ( V_2 , 0 , V_14 , V_24 ) ;
if ( F_28 ( ! V_27 ) ) {
F_29 ( V_2 , L_3 , V_24 ) ;
V_19 = 0 ;
goto V_61;
}
F_25 ( & V_27 -> V_38 ) ;
V_7 = F_20 ( V_2 ) ;
if ( F_21 ( V_7 ) ) {
V_19 = - V_36 ;
V_64 = true ;
goto V_63;
}
V_29 = V_7 -> V_42 ;
memset ( V_29 , 0 , sizeof *V_29 ) ;
V_30 = 0 ;
F_13 (dqp, &s_steer->promisc_qps[steer], list)
V_29 -> V_46 [ V_30 ++ ] = F_23 ( V_33 -> V_24 & V_47 ) ;
V_29 -> V_30 = F_23 ( V_30 | V_62 << 30 ) ;
V_19 = F_8 ( V_2 , V_13 , V_14 , V_7 ) ;
if ( V_19 )
goto V_43;
F_13 (entry, &s_steer->steer_entries[steer], list) {
V_56 = false ;
F_13 (dqp, &entry->duplicates, list) {
if ( V_33 -> V_24 == V_24 ) {
V_56 = true ;
break;
}
}
if ( V_56 ) {
F_25 ( & V_33 -> V_38 ) ;
F_26 ( V_33 ) ;
} else {
V_19 = F_4 ( V_2 , V_49 -> V_5 , V_7 ) ;
if ( V_19 )
goto V_43;
V_30 = F_22 ( V_29 -> V_30 ) & 0xffffff ;
for ( V_65 = - 1 , V_54 = 0 ; V_54 < V_30 ; ++ V_54 )
if ( ( F_22 ( V_29 -> V_46 [ V_54 ] ) & V_47 ) == V_24 )
V_65 = V_54 ;
V_29 -> V_30 = F_23 ( -- V_30 |
( V_62 << 30 ) ) ;
V_29 -> V_46 [ V_65 ] = V_29 -> V_46 [ V_54 - 1 ] ;
V_29 -> V_46 [ V_54 - 1 ] = 0 ;
V_19 = F_6 ( V_2 , V_49 -> V_5 , V_7 ) ;
if ( V_19 )
goto V_43;
}
}
V_43:
F_24 ( V_2 , V_7 ) ;
V_63:
if ( V_64 )
F_17 ( & V_27 -> V_38 , & V_26 -> V_41 [ V_14 ] ) ;
else
F_26 ( V_27 ) ;
V_61:
F_35 ( & V_58 -> V_59 . V_60 ) ;
return V_19 ;
}
static int F_37 ( struct V_1 * V_2 , T_1 V_13 ,
T_1 * V_66 , enum V_67 V_34 ,
struct V_6 * V_68 ,
int * V_69 , int * V_5 )
{
struct V_6 * V_7 ;
struct V_28 * V_29 = V_68 -> V_42 ;
T_1 * V_70 ;
int V_19 ;
T_3 V_16 ;
T_1 V_17 = ( V_34 == V_62 ) ?
! ! ( V_2 -> V_44 . V_71 & V_72 ) : 0 ;
V_7 = F_20 ( V_2 ) ;
if ( F_21 ( V_7 ) )
return - V_36 ;
V_70 = V_7 -> V_42 ;
memcpy ( V_70 , V_66 , 16 ) ;
V_19 = F_9 ( V_2 , V_7 , & V_16 , V_17 ) ;
F_24 ( V_2 , V_7 ) ;
if ( V_19 )
return V_19 ;
if ( 0 )
F_38 ( V_2 , L_4 , V_66 , V_16 ) ;
* V_5 = V_16 ;
* V_69 = - 1 ;
do {
V_19 = F_4 ( V_2 , * V_5 , V_68 ) ;
if ( V_19 )
return V_19 ;
if ( ! ( F_22 ( V_29 -> V_30 ) & 0xffffff ) ) {
if ( * V_5 != V_16 ) {
F_39 ( V_2 , L_5 ) ;
V_19 = - V_50 ;
}
return V_19 ;
}
if ( ! memcmp ( V_29 -> V_66 , V_66 , 16 ) &&
F_22 ( V_29 -> V_30 ) >> 30 == V_34 )
return V_19 ;
* V_69 = * V_5 ;
* V_5 = F_22 ( V_29 -> V_73 ) >> 6 ;
} while ( * V_5 );
* V_5 = - 1 ;
return V_19 ;
}
int F_40 ( struct V_1 * V_2 , struct V_74 * V_46 , T_1 V_66 [ 16 ] ,
int V_75 , enum V_67 V_34 ,
enum V_23 V_14 )
{
struct F_12 * V_58 = F_12 ( V_2 ) ;
struct V_6 * V_7 ;
struct V_28 * V_29 ;
T_2 V_30 ;
int V_5 , V_69 ;
int V_76 = 0 ;
int V_54 ;
int V_19 ;
T_1 V_13 = V_66 [ 5 ] ;
T_1 V_32 = 0 ;
V_7 = F_20 ( V_2 ) ;
if ( F_21 ( V_7 ) )
return F_41 ( V_7 ) ;
V_29 = V_7 -> V_42 ;
F_34 ( & V_58 -> V_59 . V_60 ) ;
V_19 = F_37 ( V_2 , V_13 , V_66 , V_34 ,
V_7 , & V_69 , & V_5 ) ;
if ( V_19 )
goto V_55;
if ( V_5 != - 1 ) {
if ( ! ( F_22 ( V_29 -> V_30 ) & 0xffffff ) ) {
V_32 = 1 ;
memcpy ( V_29 -> V_66 , V_66 , 16 ) ;
}
} else {
V_76 = 1 ;
V_5 = F_42 ( & V_58 -> V_59 . V_77 ) ;
if ( V_5 == - 1 ) {
F_39 ( V_2 , L_6 ) ;
V_19 = - V_36 ;
goto V_55;
}
V_5 += V_2 -> V_44 . V_78 ;
V_32 = 1 ;
memset ( V_29 , 0 , sizeof *V_29 ) ;
memcpy ( V_29 -> V_66 , V_66 , 16 ) ;
}
V_30 = F_22 ( V_29 -> V_30 ) & 0xffffff ;
if ( V_30 == V_2 -> V_44 . V_45 ) {
F_39 ( V_2 , L_7 , V_5 ) ;
V_19 = - V_36 ;
goto V_55;
}
for ( V_54 = 0 ; V_54 < V_30 ; ++ V_54 )
if ( ( F_22 ( V_29 -> V_46 [ V_54 ] ) & V_47 ) == V_46 -> V_24 ) {
F_38 ( V_2 , L_8 , V_46 -> V_24 ) ;
V_19 = 0 ;
goto V_55;
}
if ( V_75 )
V_29 -> V_46 [ V_30 ++ ] = F_23 ( ( V_46 -> V_24 & V_47 ) |
( 1U << V_79 ) ) ;
else
V_29 -> V_46 [ V_30 ++ ] = F_23 ( V_46 -> V_24 & V_47 ) ;
V_29 -> V_30 = F_23 ( V_30 | ( T_2 ) V_34 << 30 ) ;
V_19 = F_6 ( V_2 , V_5 , V_7 ) ;
if ( V_19 )
goto V_55;
if ( ! V_76 )
goto V_55;
V_19 = F_4 ( V_2 , V_69 , V_7 ) ;
if ( V_19 )
goto V_55;
V_29 -> V_73 = F_23 ( V_5 << 6 ) ;
V_19 = F_6 ( V_2 , V_69 , V_7 ) ;
if ( V_19 )
goto V_55;
V_55:
if ( V_34 == V_62 ) {
if ( V_32 )
F_14 ( V_2 , V_13 , V_14 , V_5 , V_46 -> V_24 ) ;
else
F_27 ( V_2 , V_13 , V_14 ,
V_5 , V_46 -> V_24 ) ;
}
if ( V_19 && V_76 && V_5 != - 1 ) {
if ( V_5 < V_2 -> V_44 . V_78 )
F_29 ( V_2 , L_9 ,
V_5 , V_2 -> V_44 . V_78 ) ;
else
F_43 ( & V_58 -> V_59 . V_77 ,
V_5 - V_2 -> V_44 . V_78 ) ;
}
F_35 ( & V_58 -> V_59 . V_60 ) ;
F_24 ( V_2 , V_7 ) ;
return V_19 ;
}
int F_44 ( struct V_1 * V_2 , struct V_74 * V_46 , T_1 V_66 [ 16 ] ,
enum V_67 V_34 , enum V_23 V_14 )
{
struct F_12 * V_58 = F_12 ( V_2 ) ;
struct V_6 * V_7 ;
struct V_28 * V_29 ;
T_2 V_30 ;
int V_69 , V_5 ;
int V_54 , V_65 ;
int V_19 ;
T_1 V_13 = V_66 [ 5 ] ;
bool V_80 = false ;
V_7 = F_20 ( V_2 ) ;
if ( F_21 ( V_7 ) )
return F_41 ( V_7 ) ;
V_29 = V_7 -> V_42 ;
F_34 ( & V_58 -> V_59 . V_60 ) ;
V_19 = F_37 ( V_2 , V_13 , V_66 , V_34 ,
V_7 , & V_69 , & V_5 ) ;
if ( V_19 )
goto V_55;
if ( V_5 == - 1 ) {
F_39 ( V_2 , L_10 , V_66 ) ;
V_19 = - V_50 ;
goto V_55;
}
if ( V_34 == V_62 &&
F_30 ( V_2 , V_13 , V_14 , V_5 , V_46 -> V_24 ) )
goto V_55;
V_30 = F_22 ( V_29 -> V_30 ) & 0xffffff ;
for ( V_65 = - 1 , V_54 = 0 ; V_54 < V_30 ; ++ V_54 )
if ( ( F_22 ( V_29 -> V_46 [ V_54 ] ) & V_47 ) == V_46 -> V_24 )
V_65 = V_54 ;
if ( V_65 == - 1 ) {
F_39 ( V_2 , L_11 , V_46 -> V_24 ) ;
V_19 = - V_50 ;
goto V_55;
}
V_29 -> V_30 = F_23 ( -- V_30 | ( T_2 ) V_34 << 30 ) ;
V_29 -> V_46 [ V_65 ] = V_29 -> V_46 [ V_54 - 1 ] ;
V_29 -> V_46 [ V_54 - 1 ] = 0 ;
if ( V_34 == V_62 )
V_80 = F_32 ( V_2 , V_13 , V_14 ,
V_5 , V_46 -> V_24 ) ;
if ( V_54 != 1 && ( V_34 != V_62 || ! V_80 ) ) {
V_19 = F_6 ( V_2 , V_5 , V_7 ) ;
goto V_55;
}
V_29 -> V_30 = F_23 ( ( T_2 ) V_34 << 30 ) ;
if ( V_69 == - 1 ) {
int V_81 = F_22 ( V_29 -> V_73 ) >> 6 ;
if ( V_81 ) {
V_19 = F_4 ( V_2 , V_81 , V_7 ) ;
if ( V_19 )
goto V_55;
} else
memset ( V_29 -> V_66 , 0 , 16 ) ;
V_19 = F_6 ( V_2 , V_5 , V_7 ) ;
if ( V_19 )
goto V_55;
if ( V_81 ) {
if ( V_81 < V_2 -> V_44 . V_78 )
F_29 ( V_2 , L_12 ,
V_5 , V_81 , V_2 -> V_44 . V_78 ) ;
else
F_43 ( & V_58 -> V_59 . V_77 ,
V_81 - V_2 -> V_44 . V_78 ) ;
}
} else {
int V_82 = F_22 ( V_29 -> V_73 ) >> 6 ;
V_19 = F_4 ( V_2 , V_69 , V_7 ) ;
if ( V_19 )
goto V_55;
V_29 -> V_73 = F_23 ( V_82 << 6 ) ;
V_19 = F_6 ( V_2 , V_69 , V_7 ) ;
if ( V_19 )
goto V_55;
if ( V_5 < V_2 -> V_44 . V_78 )
F_29 ( V_2 , L_13 ,
V_69 , V_5 , V_2 -> V_44 . V_78 ) ;
else
F_43 ( & V_58 -> V_59 . V_77 ,
V_5 - V_2 -> V_44 . V_78 ) ;
}
V_55:
F_35 ( & V_58 -> V_59 . V_60 ) ;
F_24 ( V_2 , V_7 ) ;
return V_19 ;
}
static int F_45 ( struct V_1 * V_2 , struct V_74 * V_46 ,
T_1 V_66 [ 16 ] , T_1 V_83 , T_1 V_84 ,
enum V_67 V_34 )
{
struct V_6 * V_7 ;
int V_19 = 0 ;
int V_24 ;
if ( ! F_46 ( V_2 ) )
return - V_85 ;
V_7 = F_20 ( V_2 ) ;
if ( F_21 ( V_7 ) )
return F_41 ( V_7 ) ;
memcpy ( V_7 -> V_42 , V_66 , 16 ) ;
V_24 = V_46 -> V_24 ;
V_24 |= ( V_34 << 28 ) ;
if ( V_83 && V_84 )
V_24 |= ( 1 << 31 ) ;
V_19 = F_7 ( V_2 , V_7 -> V_8 , V_24 , V_83 ,
V_86 , V_10 ,
V_87 ) ;
F_24 ( V_2 , V_7 ) ;
return V_19 ;
}
int F_47 ( struct V_1 * V_2 , struct V_74 * V_46 , T_1 V_66 [ 16 ] ,
int V_75 , enum V_67 V_34 )
{
if ( V_34 == V_62 &&
! ( V_2 -> V_44 . V_71 & V_72 ) )
return 0 ;
if ( V_34 == V_62 )
V_66 [ 7 ] |= ( V_88 << 1 ) ;
if ( F_46 ( V_2 ) )
return F_45 ( V_2 , V_46 , V_66 , 1 ,
V_75 , V_34 ) ;
return F_40 ( V_2 , V_46 , V_66 , V_75 ,
V_34 , V_88 ) ;
}
int F_48 ( struct V_1 * V_2 , struct V_74 * V_46 , T_1 V_66 [ 16 ] ,
enum V_67 V_34 )
{
if ( V_34 == V_62 &&
! ( V_2 -> V_44 . V_71 & V_72 ) )
return 0 ;
if ( V_34 == V_62 )
V_66 [ 7 ] |= ( V_88 << 1 ) ;
if ( F_46 ( V_2 ) )
return F_45 ( V_2 , V_46 , V_66 , 0 , 0 , V_34 ) ;
return F_44 ( V_2 , V_46 , V_66 , V_34 , V_88 ) ;
}
int F_49 ( struct V_1 * V_2 ,
struct V_74 * V_46 , T_1 V_66 [ 16 ] ,
int V_75 , enum V_67 V_34 )
{
if ( V_34 == V_62 &&
! ( V_2 -> V_44 . V_71 & V_89 ) )
return 0 ;
if ( V_34 == V_62 )
V_66 [ 7 ] |= ( V_90 << 1 ) ;
if ( F_46 ( V_2 ) )
return F_45 ( V_2 , V_46 , V_66 , 1 ,
V_75 , V_34 ) ;
return F_40 ( V_2 , V_46 , V_66 , V_75 ,
V_34 , V_90 ) ;
}
int F_50 ( struct V_1 * V_2 , struct V_74 * V_46 ,
T_1 V_66 [ 16 ] , enum V_67 V_34 )
{
if ( V_34 == V_62 &&
! ( V_2 -> V_44 . V_71 & V_89 ) )
return 0 ;
if ( V_34 == V_62 )
V_66 [ 7 ] |= ( V_90 << 1 ) ;
if ( F_46 ( V_2 ) )
return F_45 ( V_2 , V_46 , V_66 , 0 , 0 , V_34 ) ;
return F_44 ( V_2 , V_46 , V_66 , V_34 , V_90 ) ;
}
int F_51 ( struct V_1 * V_2 , int V_91 ,
struct V_92 * V_93 ,
struct V_6 * V_94 ,
struct V_6 * V_95 ,
struct V_96 * V_97 )
{
T_2 V_24 = ( T_2 ) V_93 -> V_98 & 0xffffffff ;
T_1 V_13 = V_93 -> V_98 >> 62 ;
enum V_23 V_14 = V_93 -> V_99 ;
if ( F_46 ( V_2 ) && V_14 == V_90 )
return 0 ;
if ( V_93 -> V_100 )
return F_33 ( V_2 , V_13 , V_14 , V_24 ) ;
else
return F_36 ( V_2 , V_13 , V_14 , V_24 ) ;
}
static int F_52 ( struct V_1 * V_2 , T_2 V_24 ,
enum V_23 V_14 , T_1 V_101 , T_1 V_13 )
{
return F_7 ( V_2 , ( T_4 ) V_24 | ( T_4 ) V_13 << 62 , ( T_2 ) V_14 , V_101 ,
V_102 , V_10 ,
V_87 ) ;
}
int F_53 ( struct V_1 * V_2 , T_2 V_24 , T_1 V_13 )
{
if ( ! ( V_2 -> V_44 . V_71 & V_72 ) )
return 0 ;
if ( F_46 ( V_2 ) )
return F_52 ( V_2 , V_24 , V_88 , 1 , V_13 ) ;
return F_33 ( V_2 , V_13 , V_88 , V_24 ) ;
}
int F_54 ( struct V_1 * V_2 , T_2 V_24 , T_1 V_13 )
{
if ( ! ( V_2 -> V_44 . V_71 & V_72 ) )
return 0 ;
if ( F_46 ( V_2 ) )
return F_52 ( V_2 , V_24 , V_88 , 0 , V_13 ) ;
return F_36 ( V_2 , V_13 , V_88 , V_24 ) ;
}
int F_55 ( struct V_1 * V_2 , T_2 V_24 , T_1 V_13 )
{
if ( ! ( V_2 -> V_44 . V_71 & V_89 ) )
return 0 ;
if ( F_46 ( V_2 ) )
return F_52 ( V_2 , V_24 , V_90 , 1 , V_13 ) ;
return F_33 ( V_2 , V_13 , V_90 , V_24 ) ;
}
int F_56 ( struct V_1 * V_2 , T_2 V_24 , T_1 V_13 )
{
if ( ! ( V_2 -> V_44 . V_71 & V_89 ) )
return 0 ;
if ( F_46 ( V_2 ) )
return F_52 ( V_2 , V_24 , V_90 , 0 , V_13 ) ;
return F_36 ( V_2 , V_13 , V_90 , V_24 ) ;
}
int F_57 ( struct V_1 * V_2 )
{
struct F_12 * V_58 = F_12 ( V_2 ) ;
int V_19 ;
V_19 = F_58 ( & V_58 -> V_59 . V_77 , V_2 -> V_44 . V_103 ,
V_2 -> V_44 . V_103 - 1 , 0 , 0 ) ;
if ( V_19 )
return V_19 ;
F_59 ( & V_58 -> V_59 . V_60 ) ;
return 0 ;
}
void F_60 ( struct V_1 * V_2 )
{
F_61 ( & F_12 ( V_2 ) -> V_59 . V_77 ) ;
}
