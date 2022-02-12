char * __init
prom_getbootargs(void)
{
int iter;
char *cp, *arg;
if (fetched) {
return barg_buf;
}
switch(prom_vers) {
case PROM_V0:
cp = barg_buf;
for(iter = 1; iter < 8; iter++) {
arg = (*(romvec->pv_v0bootargs))->argv[iter];
if (arg == NULL)
break;
while(*arg != 0) {
if(cp >= barg_buf + BARG_LEN-2){
break;
}
*cp++ = *arg++;
}
*cp++ = ' ';
}
*cp = 0;
break;
case PROM_V2:
case PROM_V3:
strlcpy(barg_buf, *romvec->pv_v2bootargs.bootargs, sizeof(barg_buf));
break;
default:
break;
}
fetched = 1;
return barg_buf;
}
